#pragma once
#include "Font.h"
#include <collection.h>
namespace Fontographer
{
	namespace Core
	{
		[Windows::UI::Xaml::Data::Bindable]
		public ref class FontFinder sealed
		{
		public:
			FontFinder(void);
			property Windows::Foundation::Collections::IVector<Font^>^ Fonts{Windows::Foundation::Collections::IVector<Font^>^ get();}
			~FontFinder(void);

		private:
			Platform::Collections::Vector<Font^>^ fonts;
		};
	}
}

