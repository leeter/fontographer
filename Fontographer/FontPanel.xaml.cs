// --------------------------------------------------------------------------------------------------------------------
// <copyright file="FontPanel.xaml.cs" company="LeetSoftwerx">
//   2012 © LeetSoftwerx
// </copyright>
// <summary>
//   Interaction logic for FontPanel.xaml
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace Fontographer
{
    using System.Windows;
    using System.Windows.Controls;

    /// <summary>
    /// Interaction logic for FontPanel.xaml
    /// </summary>
    public partial class FontPanel : UserControl
    {
        #region Constructors and Destructors

        /// <summary>
        /// Initializes a new instance of the <see cref="FontPanel"/> class. 
        /// Initializes a new instance of the <see cref="FontPanel"/> class.
        /// </summary>
        public FontPanel()
        {
            this.InitializeComponent();
        }

        #endregion

        #region Methods

        /// <summary>
        /// The bold button_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void BoldButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.FontWeight = this.UserSandbox.FontWeight == FontWeights.Normal
                                              ? FontWeights.Bold
                                              : FontWeights.Normal;
        }

        /// <summary>
        /// The contextual alternates button_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void ContextualAlternatesButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.ContextualAlternates = !this.UserSandbox.Typography.ContextualAlternates;
        }

        /// <summary>
        /// The contextual ligatures button_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void ContextualLigaturesButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.ContextualLigatures = !this.UserSandbox.Typography.ContextualLigatures;
        }

        /// <summary>
        /// The fraction combo_ selection changed.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void FractionCombo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var combo = sender as ComboBox;
            var fractionStyle = (FontFraction)combo.SelectedValue;
            this.UserSandbox.Typography.Fraction = fractionStyle;
        }

        /// <summary>
        /// The historical ligatures button_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void HistoricalLigaturesButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.HistoricalLigatures = !this.UserSandbox.Typography.HistoricalLigatures;
        }

        /// <summary>
        /// The italic button_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void ItalicButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.FontStyle = this.UserSandbox.FontStyle == FontStyles.Normal
                                             ? FontStyles.Italic
                                             : FontStyles.Normal;
        }

        /// <summary>
        /// The kerning button_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void KerningButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.Kerning = !this.UserSandbox.Typography.Kerning;
        }

        /// <summary>
        /// The ligatures_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void Ligatures_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.StandardLigatures = !this.UserSandbox.Typography.StandardLigatures;
        }

        /// <summary>
        /// The slashed zero button_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void SlashedZeroButton_Click(object sender, RoutedEventArgs e)
        {
            this.UserSandbox.Typography.SlashedZero = !this.UserSandbox.Typography.SlashedZero;
        }

        /// <summary>
        /// The stylistic set combo_ selection changed.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
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
                this.UserSandbox.Typography.StylisticSet19 = this.UserSandbox.Typography.StylisticSet20 = false;

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

        #endregion
    }
}