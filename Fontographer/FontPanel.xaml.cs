using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Fontographer
{
    /// <summary>
    /// Interaction logic for FontPanel.xaml
    /// </summary>
    public partial class FontPanel : UserControl
    {
        public FontPanel()
        {
            InitializeComponent();
        }

        private void ItalicButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.FontStyle = this.UserSandbox.FontStyle == FontStyles.Normal
                                             ? FontStyles.Italic
                                             : FontStyles.Normal;
        }

        private void BoldButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.FontWeight = this.UserSandbox.FontWeight == FontWeights.Normal
                                              ? FontWeights.Bold
                                              : FontWeights.Normal;
        }

        private void KerningButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.Kerning = this.UserSandbox.Typography.Kerning ? false : true;
        }

        private void ContextualAlternatesButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.ContextualAlternates = this.UserSandbox.Typography.ContextualAlternates
                                                                   ? false
                                                                   : true;
        }

        private void ContextualLigaturesButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.ContextualLigatures = this.UserSandbox.Typography.ContextualLigatures
                                                                  ? false
                                                                  : true;
        }

        private void SlashedZeroButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.SlashedZero = this.UserSandbox.Typography.SlashedZero ? false : true;
        }

        private void FractionCombo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var combo = sender as ComboBox;
            var fractionStyle = (FontFraction)combo.SelectedValue;
            this.UserSandbox.Typography.Fraction = fractionStyle;
        }

        private void Ligatures_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.StandardLigatures = this.UserSandbox.Typography.StandardLigatures ? false : true;
        }

        private void HistoricalLigaturesButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.HistoricalLigatures = this.UserSandbox.Typography.HistoricalLigatures
                                                                  ? false
                                                                  : true;
        }

        private void StylisticSetCombo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            this.UserSandbox.Typography.StylisticSet1 =
                this.UserSandbox.Typography.StylisticSet2 =
                this.UserSandbox.Typography.StylisticSet3 =
                this.UserSandbox.Typography.StylisticSet4 =
                this.UserSandbox.Typography.StylisticSet5 =
                this.UserSandbox.Typography.StylisticSet6 =
                this.UserSandbox.Typography.StylisticSet7 =
                this.UserSandbox.Typography.StylisticSet8 =
                this.UserSandbox.Typography.StylisticSet9 =
                this.UserSandbox.Typography.StylisticSet10 =
                this.UserSandbox.Typography.StylisticSet11 =
                this.UserSandbox.Typography.StylisticSet12 =
                this.UserSandbox.Typography.StylisticSet13 =
                this.UserSandbox.Typography.StylisticSet14 =
                this.UserSandbox.Typography.StylisticSet15 =
                this.UserSandbox.Typography.StylisticSet16 =
                this.UserSandbox.Typography.StylisticSet17 =
                this.UserSandbox.Typography.StylisticSet18 =
                this.UserSandbox.Typography.StylisticSet19 =
                this.UserSandbox.Typography.StylisticSet20 = false;

            var combo = sender as ComboBox;
            switch (combo.SelectedIndex)
            {
                case 1:
                    this.UserSandbox.Typography.StylisticSet1 = true;
                    return;
                case 2:
                    this.UserSandbox.Typography.StylisticSet2 = true;
                    return;
                case 3:
                    this.UserSandbox.Typography.StylisticSet3 = true;
                    return;
                case 4:
                    this.UserSandbox.Typography.StylisticSet4 = true;
                    return;
                case 5:
                    this.UserSandbox.Typography.StylisticSet5 = true;
                    return;
                case 6:
                    this.UserSandbox.Typography.StylisticSet6 = true;
                    return;
                case 7:
                    this.UserSandbox.Typography.StylisticSet7 = true;
                    return;
                case 8:
                    this.UserSandbox.Typography.StylisticSet8 = true;
                    return;
                case 9:
                    this.UserSandbox.Typography.StylisticSet9 = true;
                    return;
                case 10:
                    this.UserSandbox.Typography.StylisticSet10 = true;
                    return;
                case 11:
                    this.UserSandbox.Typography.StylisticSet11 = true;
                    return;
                case 12:
                    this.UserSandbox.Typography.StylisticSet12 = true;
                    return;
                case 13:
                    this.UserSandbox.Typography.StylisticSet13 = true;
                    return;
                case 14:
                    this.UserSandbox.Typography.StylisticSet14 = true;
                    return;
                case 15:
                    this.UserSandbox.Typography.StylisticSet15 = true;
                    return;
                case 16:
                    this.UserSandbox.Typography.StylisticSet16 = true;
                    return;
                case 17:
                    this.UserSandbox.Typography.StylisticSet17 = true;
                    return;
                case 18:
                    this.UserSandbox.Typography.StylisticSet18 = true;
                    return;
                case 19:
                    this.UserSandbox.Typography.StylisticSet19 = true;
                    return;
                case 20:
                    this.UserSandbox.Typography.StylisticSet20 = true;
                    return;
                default:
                    return;
            }
        }
    }
}
