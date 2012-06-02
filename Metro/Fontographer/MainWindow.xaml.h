//
// BlankPage.xaml.h
// Declaration of the BlankPage.xaml class.
//

#pragma once

#include "pch.h"
#include "FontFinder.h"
#include "Common\LayoutAwarePage.h"
#include "MainWindow.g.h"

namespace Fontographer
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainWindow sealed
	{
	public:
		MainWindow();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		void backButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		bool UsingLogicalPageNavigation();
		bool UsingLogicalPageNavigation(Windows::UI::ViewManagement::ApplicationViewState viewState);
	};
}
