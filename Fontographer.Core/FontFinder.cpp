#include "StdAfx.h"
#define VC_EXTRALEAN
#include <Windows.h>
#include "FontFinder.h"
#include "FontInfoHelpers.h"
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace Fontographer::Core;

static System::String ^ NewOrEmptyString(const std::wstring * in)
{
	if(in)
	{
		return gcnew System::String(in->c_str());
	}

	return System::String::Empty;
}

__clrcall FontFinder::FontFinder(void)
{	
	FontInfoInternal * internalFonts = NULL;
	UINT32 count = 0;
	HRESULT hr = GetFontInfoInternal(NULL, &count);
	if (SUCCEEDED(hr) || hr == E_NOT_SUFFICIENT_BUFFER)
	{
		internalFonts = new (std::nothrow) FontInfoInternal[count];
		if (!internalFonts)
		{
			throw gcnew OutOfMemoryException();
		}
		hr = S_OK;
	}

	if (SUCCEEDED(hr))
	{
		hr = GetFontInfoInternal(internalFonts, &count);
	}

	if (SUCCEEDED(hr))
	{
		this->fonts = gcnew List<FontInfo^>(count);
		for (UINT32 i = 0; i < count; ++i)
		{
			if(!internalFonts[i].name)
				continue;
			FontInfo ^ toAdd = gcnew FontInfo(
				NewOrEmptyString(internalFonts[i].name),
				NewOrEmptyString(internalFonts[i].manufacturer),
				NewOrEmptyString(internalFonts[i].designerUri));
			this->fonts->Add(toAdd);
		}
	}
	
	if (internalFonts)
	{
		delete [] internalFonts;
	}

}

IEnumerable<FontInfo^>^ __clrcall FontFinder::Fonts::get()
{
	return this->fonts;
}