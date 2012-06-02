// --------------------------------------------------------------------------------------------------------------------
// <copyright file="App.xaml.cs" company="LeetSoftwerx">
//   2012 © LeetSoftwerx
// </copyright>
// <summary>
//   Interaction logic for App.xaml
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace Fontographer
{
    using System.Diagnostics;
    using System.Windows;
    using System.Windows.Documents;

    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        private void Hyperlink_RequestNavigate(object sender, System.Windows.Navigation.RequestNavigateEventArgs e)
        {
            Hyperlink hl = (Hyperlink)sender;
            string navigateUri = hl.NavigateUri.ToString();
            Process.Start(new ProcessStartInfo(navigateUri));
            e.Handled = true;
        }
    }
}