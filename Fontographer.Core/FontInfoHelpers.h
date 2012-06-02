#pragma once
#include <string>

typedef struct FontInfoInternal{
	std::wstring * name;
	std::wstring * copyright;
	std::wstring * manufacturer;
	std::wstring * designerUri;
	~FontInfoInternal(void);
	FontInfoInternal(void);
} FontInfoInternal;

#ifdef __cplusplus
extern "C" {
#endif
STDMETHODIMP GetFontInfoInternal(FontInfoInternal fonts[], UINT32 * count);

#ifdef __cplusplus
}
#endif