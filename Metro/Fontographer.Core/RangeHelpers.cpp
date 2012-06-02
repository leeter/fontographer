#include "pch.h"
#include "RangeHelpers.h"

STDMETHODIMP IsCJK(DWRITE_UNICODE_RANGE range, bool * result)
{
	if(!result)
	{
		return E_INVALIDARG;
	}

	if(range.first <= 0x4E00 && range.last >= 0x9FFF)
	{
		*result = true;
	}
	else
	{
		*result = false;
	}
	return S_OK;
}

STDMETHODIMP IsBasicLatin(DWRITE_UNICODE_RANGE range, bool * result)
{
	if(!result)
	{
		return E_INVALIDARG;
	}

	if(range.first <= 0x21 && range.last >= 0x7e)
	{
		*result = true;
	}
	else
	{
		*result = false;
	}
	return S_OK;
}

STDMETHODIMP IsLatinExtended(DWRITE_UNICODE_RANGE range, bool * result)
{
	if(!result)
	{
		return E_INVALIDARG;
	}

	if(range.first <= 0xAE && range.last >= 0xFF)
	{
		*result = true;
	}
	else
	{
		*result = false;
	}
	return S_OK;
}