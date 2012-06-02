#pragma once
#include <dwrite_1.h>

STDMETHODIMP IsCJK(DWRITE_UNICODE_RANGE range, bool * result);
STDMETHODIMP IsBasicLatin(DWRITE_UNICODE_RANGE range, bool * result);
STDMETHODIMP IsLatinExtended(DWRITE_UNICODE_RANGE range, bool * result);