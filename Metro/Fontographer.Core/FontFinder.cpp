#include "pch.h"
#include "FontFinder.h"
#include "RangeHelpers.h"
#include <dwrite_1.h>
using namespace Fontographer::Core;
using namespace Windows::Foundation::Collections;

template <class T> static inline void SafeRelease(T **ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}


static STDMETHODIMP GetLocalizedString(IDWriteLocalizedStrings * strings, wchar_t ** string, UINT32 * length)
{
	wchar_t localeName[LOCALE_NAME_MAX_LENGTH];
	HRESULT hr = S_OK;
	UINT32 index = 0;
	BOOL exists = FALSE;
	int defaultLocaleSuccess = GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH);
	if(defaultLocaleSuccess)
	{
		hr = strings->FindLocaleName(localeName, &index, &exists);
	}
	if(SUCCEEDED(hr) && !exists)
	{
		hr = strings->FindLocaleName(L"en-us", &index, &exists);
	}
	if(!exists)
	{
		index = 0;
	}
	if (SUCCEEDED(hr))
	{
		hr = strings->GetStringLength(index, length); 
	}
	*string = new (std::nothrow) wchar_t[*length + 1];
	if (*string == NULL)
	{
		hr = E_OUTOFMEMORY;
	}
	if(SUCCEEDED(hr))
	{
		hr = strings->GetString(index, *string, *length + 1);
	}
	return hr;
}

static Platform::String^ __stdcall GetFontProperty(IDWriteFont * font, DWRITE_INFORMATIONAL_STRING_ID property)
{
	IDWriteLocalizedStrings * localizedStrings = NULL;
	wchar_t * string = NULL;
	UINT32 length = 0;
	BOOL exists = FALSE;
	HRESULT hr = font->GetInformationalStrings(property, &localizedStrings, &exists);

	if(SUCCEEDED(hr) && exists)
	{
		hr = GetLocalizedString(localizedStrings, &string, &length);
	}

	auto toReturn = ref new Platform::String(string, length + 1);
	SafeRelease(&localizedStrings);
	if(string)
	{
		delete [] string;
	}
	return toReturn;
}

static bool FontCompare(Font^ a, Font^ b)
{
	return a->FontName < b->FontName;
}

FontFinder::FontFinder(void)
{
	this->fonts = ref new Platform::Collections::Vector<Font^>();

	IDWriteFactory * factory = NULL;
	IDWriteFontCollection * fontCollection = NULL;
	UINT32 familyCount = 0;

	HRESULT hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(IDWriteFactory),
		reinterpret_cast<IUnknown**>(&factory));

	if (SUCCEEDED(hr))
	{
		hr = factory->GetSystemFontCollection(&fontCollection);
	}

	if (SUCCEEDED(hr))
	{
		familyCount = fontCollection->GetFontFamilyCount();
	}

	for(UINT32 i = 0; i < familyCount; ++i)
	{
		IDWriteFontFamily * family = NULL;
		IDWriteLocalizedStrings * familyNames = NULL;
		IDWriteFont * font = NULL;
		IDWriteFont1 * extendedFont = NULL;
		wchar_t *name = NULL;
		UINT32 length = 0, rangeCount = 0;
		Platform::String ^ familyName = nullptr;
		DWRITE_UNICODE_RANGE * ranges = NULL;
		bool CJK = false, Katakana = false, basicLatin = false, extendedLatin = false; 


		if (SUCCEEDED(hr))
		{
			hr = fontCollection->GetFontFamily(i, &family); 
		}

		if (SUCCEEDED(hr))
		{
			hr = family->GetFamilyNames(&familyNames);
		}

		if (SUCCEEDED(hr))
		{
			hr = GetLocalizedString(familyNames, &name, &length);
		}

		if (SUCCEEDED(hr))
		{
			familyName = ref new Platform::String(name, length + 1);
			hr = family->GetFont(0, &font);
		}

		if (SUCCEEDED(hr))
		{
			hr = font->QueryInterface(&extendedFont);
		}

		if (SUCCEEDED(hr))
		{
			hr = extendedFont->GetUnicodeRanges(0, NULL, &rangeCount);

			if (hr == HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) && rangeCount)
			{
				ranges = new (std::nothrow) DWRITE_UNICODE_RANGE[rangeCount];
				if(!ranges)
				{
					hr = E_OUTOFMEMORY;
				}
				else
				{
					hr = S_OK;
				}
			}

			if(SUCCEEDED(hr))
			{
				hr = extendedFont->GetUnicodeRanges(rangeCount, ranges, &rangeCount);
			}
		}

		if (SUCCEEDED(hr))
		{
			for(UINT32 i = 0; i < rangeCount; ++i)
			{
				bool isCJK = false, isBasicLatin = false, isExtendedLatin = false;
				IsCJK(ranges[i], &isCJK);
				IsBasicLatin(ranges[i], &isBasicLatin);
				IsLatinExtended(ranges[i], &isExtendedLatin);
				CJK |= isCJK;
				basicLatin |= isBasicLatin;
				extendedLatin |= isExtendedLatin;
			}
		}

		if (SUCCEEDED(hr))
		{
			auto designerName = GetFontProperty(font, DWRITE_INFORMATIONAL_STRING_DESIGNER);
			auto copyright = GetFontProperty(font, DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE);
			auto license = GetFontProperty(font, DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION);
			auto manufacturer = GetFontProperty(font, DWRITE_INFORMATIONAL_STRING_MANUFACTURER);
			auto sampleText = GetFontProperty(font, DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT);
			auto toAppend = ref new Font(familyName, designerName, copyright, license, manufacturer, sampleText, basicLatin, extendedLatin, CJK);
			this->fonts->Append(toAppend);
		}

		SafeRelease(&family);
		SafeRelease(&familyNames);
		SafeRelease(&font);
		SafeRelease(&extendedFont);

		if(ranges != NULL)
		{
			delete [] ranges;
		}
		if(name != NULL)
		{
			delete [] name;
		}
	}

	std::sort(begin(this->fonts), end(this->fonts), FontCompare);
	SafeRelease(&fontCollection);
	SafeRelease(&factory);
	if(FAILED(hr))
	{
		RaiseFailFastException(NULL, NULL, FAIL_FAST_GENERATE_EXCEPTION_ADDRESS);
	}
}

IVector<Font^>^ FontFinder::Fonts::get()
{ 
	return this->fonts;
}


FontFinder::~FontFinder(void)
{
}
