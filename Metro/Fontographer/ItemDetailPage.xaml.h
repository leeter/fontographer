//
// ItemDetailPage.xaml.h
// Declaration of the ItemDetailPage class
//

#pragma once

#include "pch.h"
#include "Common\LayoutAwarePage.h" // Required by generated header
#include "Common\RichTextColumns.h" // Required by generated header
#include "ItemDetailPage.g.h"

#include <collection.h>

namespace Fontographer
{
	/// <summary>
	/// A page that displays details for a single item within a group while allowing gestures to
	/// flip through other items belonging to the same group.
	/// </summary>
	public ref class ItemDetailPage sealed
	{
	public:
		ItemDetailPage();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	};
}
