//
// ItemDetailPage.xaml.cpp
// Implementation of the ItemDetailPage class
//

#include "pch.h"
#include "ItemDetailPage.xaml.h"

using namespace Fontographer;

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Item Detail Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234232

ItemDetailPage::ItemDetailPage()
{
	InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property provides the initial item to be displayed.</param>
void ItemDetailPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	// TODO: Set a bindable group using DefaultViewModel->Insert("Group", <value>)
	// TODO: Set a collection of bindable items using DefaultViewModel->Insert("Items", <value>)
}
