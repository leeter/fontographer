#pragma once
#include "FontInfo.h"
using namespace System::Collections::Generic;
namespace Fontographer
{
	namespace Core
	{
		public ref class FontFinder
		{
		public:
			__clrcall FontFinder(void);
			[System::ComponentModel::Bindable(true)]
			property IEnumerable<FontInfo^>^ Fonts{ IEnumerable<FontInfo^>^ __clrcall get(void); };

		private:
			List<FontInfo^>^ fonts;
		};
	}
}
