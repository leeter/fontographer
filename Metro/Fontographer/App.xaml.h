﻿//
// App.xaml.h
// Declaration of the App.xaml class.
//

#pragma once

#include "pch.h"
#include "Common\BooleanToVisibilityConverter.h"
#include "App.g.h"

namespace Fontographer
{
	/// <summary>
	/// Provides application-specific behavior to supplement the default Application class.
	/// </summary>
	ref class App sealed
	{
	public:
		App();
		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs) override;

	private:
		void OnSuspending(Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);
		
	};
}
