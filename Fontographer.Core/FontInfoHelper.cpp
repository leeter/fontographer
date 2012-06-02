#include "precompile.h"

#include "FontInfoHelpers.h"

template <class T> static void SafeRelease(T **ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}

FontInfoInternal::FontInfoInternal()
{
	this->copyright = NULL;
	this->designerUri = NULL;
	this->manufacturer = NULL;
	this->name = NULL;
}

FontInfoInternal::~FontInfoInternal()
{
	if (this->copyright)
	{
		delete this->copyright;
	}
	if (this->manufacturer)
	{
		delete this->manufacturer;
	}
	if (this->name)
	{
		delete this->name;
	}
	if (this->designerUri)
	{
		delete this->designerUri;
	}
}

static STDMETHODIMP GetLocalizedString(IDWriteLocalizedStrings * strings, std::wstring ** string)
{
	wchar_t localeName[LOCALE_NAME_MAX_LENGTH];
	UINT32 index = 0, length = 0;
	BOOL exists = FALSE;
	wchar_t * rawstring = NULL;
	HRESULT hr = S_OK;
	if (GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH))
	{
		hr = strings->FindLocaleName(localeName, &index, &exists);
	}

	if (SUCCEEDED(hr) && !exists)
	{
		hr = strings->FindLocaleName(L"en-us", &index, &exists);
		if(!exists)
			index = 0;
	}

	if (SUCCEEDED(hr))
	{
		hr = strings->GetStringLength(index, &length);
	}

	if (SUCCEEDED(hr))
	{
		rawstring = new (std::nothrow) wchar_t[length + 1];
		if (!rawstring)
		{
			return E_OUTOFMEMORY;
		}
		hr = strings->GetString(index, rawstring, length + 1 );
	}

	if (SUCCEEDED(hr))
	{
		*string = new (std::nothrow) std::wstring(rawstring, length + 1);
		if (!(*string))
		{
			hr = E_OUTOFMEMORY;
		}
	}

	if (rawstring)
	{
		delete [] rawstring;
	}

	return hr;
}

static STDMETHODIMP GetFontPropertyString(
	IDWriteFont * font,
	DWRITE_INFORMATIONAL_STRING_ID propertyId,
	std::wstring ** string, BOOL * exists)
{
	IDWriteLocalizedStrings * strings = NULL;
	HRESULT hr = font->GetInformationalStrings(propertyId, &strings, exists);
	if (SUCCEEDED(hr) && *exists)
	{
		hr = GetLocalizedString(strings, string);
	}

	SafeRelease(&strings);
	return hr;
}

extern "C" {

	STDMETHODIMP GetFontInfoInternal(FontInfoInternal fonts[], UINT32 * count)
	{
		IDWriteFactory * factory = NULL;
		IDWriteFontCollection * systemFonts = NULL;
		UINT32 familyCount = 0;

		HRESULT hr = DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&factory)
			);

		if (SUCCEEDED(hr))
		{
			hr = factory->GetSystemFontCollection(&systemFonts, FALSE);
		}

		if (SUCCEEDED(hr))
		{			
			familyCount = systemFonts->GetFontFamilyCount();
			if (*count == 0)
			{
				*count = familyCount;
				hr = E_NOT_SUFFICIENT_BUFFER;
			}			
		}

		if (SUCCEEDED(hr))
		{
			UINT32 getCount = familyCount < *count ? familyCount : *count;
			for(UINT32 i = 0; i < getCount; ++i)
			{
				IDWriteFontFamily * family = NULL;
				IDWriteLocalizedStrings * familyNames = NULL;
				IDWriteFont * font = NULL;
				std::wstring * name = NULL;
				std::wstring * manufacturer = NULL;
				BOOL exists = FALSE;

				if (SUCCEEDED(hr))
				{
					hr = systemFonts->GetFontFamily(i, &family);
				}

				if (SUCCEEDED(hr))
				{
					hr = family->GetFamilyNames(&familyNames);
				}

				if (SUCCEEDED(hr))
				{
					hr = GetLocalizedString(familyNames, &fonts[i].name);
				}

				if (SUCCEEDED(hr))
				{
					hr = family->GetFont(0, &font);
				}

				if (SUCCEEDED(hr))
				{	
					hr = GetFontPropertyString(font, DWRITE_INFORMATIONAL_STRING_MANUFACTURER, &fonts[i].manufacturer, &exists);
				}

				if (SUCCEEDED(hr))
				{
					hr = GetFontPropertyString(font, DWRITE_INFORMATIONAL_STRING_DESIGNER_URL, &fonts[i].designerUri, &exists);
				}

				if(SUCCEEDED(hr))
				{
					hr = GetFontPropertyString(font, DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE, &fonts[i].copyright, &exists);
				}

				SafeRelease(&font);
				SafeRelease(&familyNames);
				SafeRelease(&family);
			}
		}
		SafeRelease(&factory);
		SafeRelease(&systemFonts);
		return hr;
	}
}