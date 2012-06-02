#include "StdAfx.h"
#include "FontInfo.h"
using namespace Fontographer::Core;

FontInfo::FontInfo(
	System::String ^ name,
	System::String ^ manufacturer,
	System::String ^ designerUri)
{
	this->name = name;
	this->manufacturer = manufacturer;
	System::Uri ^ uri = nullptr;
	System::Uri::TryCreate(designerUri, System::UriKind::Absolute, this->designerUri);
}

System::String ^ FontInfo::Name::get()
{
	return this->name;
}

System::String ^ FontInfo::Manufacturer::get()
{
	return this->manufacturer;
}

System::Uri^ FontInfo::DesignerUri::get()
{
	return this->designerUri;
}
