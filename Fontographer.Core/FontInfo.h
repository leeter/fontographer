#pragma once
namespace Fontographer
{
	namespace Core
	{
		public ref class FontInfo
		{
		public:
			FontInfo(
				System::String ^ name,
				System::String ^ manufacturer,
				System::String ^ designerUri);
			[System::ComponentModel::Bindable(true)]
			property System::String^ Name { System::String ^ get();};
			[System::ComponentModel::Bindable(true)]
			property System::String^ Manufacturer { System::String ^ get(); };
			[System::ComponentModel::Bindable(true)]
			property System::Uri^ DesignerUri { System::Uri ^ get(); };
		private:
			System::String ^ name;
			System::String ^ manufacturer;
			System::String ^ copyright;
			System::String ^ designer;
			System::String ^ version;
			System::Uri ^ designerUri;
		};
	}
}
