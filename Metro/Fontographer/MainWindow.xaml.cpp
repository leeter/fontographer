//
// MainWindow.xaml.cpp
// Implementation of the MainWindow.xaml class.
//

#include "pch.h"
#include "FontFinder.h"
#include "MainWindow.xaml.h"
#include "Common\LayoutAwarePage.h"

using namespace Fontographer;
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

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainWindow::MainWindow()
{
	InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void MainWindow::OnNavigatedTo(NavigationEventArgs^ e)
{
	auto finder = safe_cast<FontFinder^>(e->Parameter);
	DefaultViewModel->Insert("Finder", finder);
	DefaultViewModel->Insert("Fonts", finder->Fonts);
}


void Fontographer::MainWindow::backButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (UsingLogicalPageNavigation())
	{
	}
	else
	{
		// When logical page navigation is not in effect, or when there is no selected item,
		// use the default back button behavior.
		LayoutAwarePage::GoBack(sender, e);
	}
}

bool Fontographer::MainWindow::UsingLogicalPageNavigation()
{
	return UsingLogicalPageNavigation(ApplicationView::Value);
}
bool Fontographer::MainWindow::UsingLogicalPageNavigation(Windows::UI::ViewManagement::ApplicationViewState viewState)
{
	return viewState == ApplicationViewState::FullScreenPortrait ||
		viewState == ApplicationViewState::Snapped;
}
