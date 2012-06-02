//
// SplitPage.xaml.cpp
// Implementation of the SplitPage class
//

#include "pch.h"
#include "SplitPage.xaml.h"
#include "Common\LayoutAwarePage.h"

using namespace Fontographer;
using namespace Fontographer::Core;
using namespace Fontographer::Common;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::ViewManagement;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Split Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234234

SplitPage::SplitPage()
{
	InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The
/// Parameter property provides the group to be displayed.</param>
void SplitPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	auto finder = safe_cast<FontFinder^>(e->Parameter);
	DefaultViewModel->Insert("Finder", finder);
	DefaultViewModel->Insert("Fonts", finder->Fonts);
	// TODO: Set a bindable group using DefaultViewModel->Insert("Group", <value>)
	// TODO: Set a collection of bindable items using DefaultViewModel->Insert("Items", <value>)

	// Select the first item automatically unless logical page navigation is being used (see the
	// logical page navigation #pragma region below.)
	if (!UsingLogicalPageNavigation()) fonts->View->MoveCurrentToFirst();
}

#pragma region Logical_Page_Navigation

// Visual state management typically reflects the four application view states directly (full
// screen landscape and portrait plus snapped and filled views.)  The split page is designed so
// that the snapped and portrait view states each have two distinct sub-states: either the item
// list or the details are displayed, but not both at the same time.
//
// This is all implemented with a single physical page that can represent two logical pages.
// The code below achieves this goal without making the user aware of the distinction.

/// <summary>
/// Invoked to determine whether the page should act as one logical page or two.
/// </summary>
/// <returns>True when the current view state is portrait or snapped, false
/// otherwise.</returns>
bool SplitPage::UsingLogicalPageNavigation()
{
	return UsingLogicalPageNavigation(ApplicationView::Value);
}

/// <summary>
/// Invoked to determine whether the page should act as one logical page or two.
/// </summary>
/// <param name="viewState">The view state for which the question is being posed.</param>
/// <returns>True when the view state in question is portrait or snapped, false
/// otherwise.</returns>
bool SplitPage::UsingLogicalPageNavigation(ApplicationViewState viewState)
{
	return viewState == ApplicationViewState::FullScreenPortrait ||
		viewState == ApplicationViewState::Snapped;
}

/// <summary>
/// Invoked when an item within the list is selected.
/// </summary>
/// <param name="sender">The GridView (or ListView when the application is Snapped)
/// displaying the selected item.</param>
/// <param name="e">Event data that describes how the selection was changed.</param>
void SplitPage::ItemListView_SelectionChanged(Object^ sender, SelectionChangedEventArgs^ e)
{
	// Invalidate the view state when logical page navigation is in effect, as a change in
	// selection may cause a corresponding change in the current logical page.  When an item is
	// selected this has the effect of changing from displaying the item list to showing the
	// selected item's details.  When the selection is cleared this has the opposite effect.
	if (UsingLogicalPageNavigation()) InvalidateVisualState();
}

/// <summary>
/// Invoked when the page's back button is pressed.
/// </summary>
/// <param name="sender">The back button instance.</param>
/// <param name="e">Event data that describes how the back button was clicked.</param>
void SplitPage::GoBack(Object^ sender, RoutedEventArgs^ e)
{
	if (UsingLogicalPageNavigation() && itemListView->SelectedItem != nullptr)
	{
		// When logical page navigation is in effect and there's a selected item that item's
		// details are currently displayed.  Clearing the selection will return to the item list.
		// From the user's point of view this is a logical backward navigation.
		itemListView->SelectedItem = nullptr;
	}
	else
	{
		// When logical page navigation is not in effect, or when there is no selected item, use
		// the default back button behavior.
		LayoutAwarePage::GoBack(sender, e);
	}
}

/// <summary>
/// Invoked to determine the name of the visual state that corresponds to an application view
/// state.
/// </summary>
/// <param name="viewState">The view state for which the question is being posed.</param>
/// <returns>The name of the desired visual state.  This is the same as the name of the view state
/// except when there is a selected item in portrait and snapped views where this additional
/// logical page is represented by adding a suffix of _Detail.</returns>
String^ SplitPage::DetermineVisualState(ApplicationViewState viewState)
{
	// Update the back button's enabled state when the view state changes
	auto logicalPageBack = UsingLogicalPageNavigation(viewState) && itemListView->SelectedItem != nullptr;
	auto physicalPageBack = Frame != nullptr && Frame->CanGoBack;
	DefaultViewModel->Insert("CanGoBack", logicalPageBack || physicalPageBack);

	// Start with the default visual state name, and add a suffix when logical page navigation is
	// in effect and we need to display details instead of the list
	String^ defaultStateName = LayoutAwarePage::DetermineVisualState(viewState);
	return logicalPageBack ? defaultStateName + "_Detail" : defaultStateName;
}

#pragma endregion
