#include "pch.h"
#include "Font.h"

using namespace Fontographer::Core;

Font::Font(
	Platform::String^ fontName,
	Platform::String ^ designer,
	Platform::String ^ copyright,
	Platform::String ^ license,
	Platform::String ^ manufacturer,
	Platform::String ^ sampleText,
	Platform::Boolean isLatinBasic,
	Platform::Boolean isLatinExtended,
	Platform::Boolean isCjk)
{
	this->fontName = fontName;
	this->designer = designer;
	this->copyright = copyright;
	this->license = license;
	this->manufacturer = manufacturer;
	this->sampleText = sampleText;
	this->isCjk = isCjk;
	this->isLatinBasic = isLatinBasic;
	this->isLatinExtended = isLatinExtended;
}


Font::~Font(void)
{
}

Platform::String^ Font::FontName::get()
{
	return this->fontName;
}

Platform::String^ Font::FirstChar::get()
{
	return this->fontName->Data()[0].ToString();
}

Platform::String^ Font::Designer::get()
{
	return this->designer;
}

Platform::String^ Font::Copyright::get()
{
	return this->copyright;
}

Platform::String^ Font::License::get()
{
	return this->license;
}

Platform::String^ Font::Manufacturer::get()
{
	return this->manufacturer;
}

Platform::String^ Font::SampleText::get()
{
	return this->sampleText;
}

Platform::Boolean Font::IsCjk::get()
{
	return this->isCjk;
}

Platform::Boolean Font::IsLatinBasic::get()
{
	return this->isLatinBasic;
}

Platform::Boolean Font::IsLatinExtended::get()
{
	return this->isLatinExtended;
}