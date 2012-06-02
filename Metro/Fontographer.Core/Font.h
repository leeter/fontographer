#pragma once
namespace Fontographer
{
	namespace Core
	{
		[Windows::UI::Xaml::Data::Bindable]
		public ref class Font sealed 
		{
		public:
			Font(
				Platform::String^ fontName,
				Platform::String^ designer,
				Platform::String^ copyright,
				Platform::String^ license,
				Platform::String^ manufacturer,
				Platform::String^ sampleText,
				Platform::Boolean isLatinBasic,
				Platform::Boolean isLatinExtended,
				Platform::Boolean isCjk);
			~Font(void);

			property Platform::String^ FontName { Platform::String^ get();};
			property Platform::String^ FirstChar { Platform::String^ get();};
			property Platform::String^ Designer { Platform::String^ get();};
			property Platform::String^ Copyright { Platform::String^ get();};
			property Platform::String^ License { Platform::String^ get();};
			property Platform::String^ Manufacturer { Platform::String ^ get();};
			property Platform::String^ SampleText { Platform::String^ get();};
			property Platform::Boolean IsCjk { Platform::Boolean get();};
			property Platform::Boolean IsLatinBasic { Platform::Boolean get();};
			property Platform::Boolean IsLatinExtended { Platform::Boolean get();};

		private:
			Platform::String ^ fontName;
			Platform::String ^ designer;
			Platform::String ^ copyright;
			Platform::String ^ license;
			Platform::String ^ manufacturer;
			Platform::String ^ sampleText;
			Platform::Boolean isCjk;
			Platform::Boolean isLatinBasic;
			Platform::Boolean isLatinExtended;
		};
	}
}
