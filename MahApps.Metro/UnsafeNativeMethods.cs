// -----------------------------------------------------------------------
// <copyright file="UnsafeNativeMethods.cs" company="">
// TODO: Update copyright text.
// </copyright>
// -----------------------------------------------------------------------

namespace MahApps.Metro
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Runtime.InteropServices;
    using System.Security;
    using System.Text;

    using MahApps.Metro.Native;

    /// <summary>
    /// TODO: Update summary.
    /// </summary>
    [SuppressUnmanagedCodeSecurity]
    internal static class UnsafeNativeMethods
    {
        [DllImport("dwmapi", PreserveSig = false)]
        [return: MarshalAs(UnmanagedType.Bool)]
        internal static extern bool DwmIsCompositionEnabled();

        [DllImport("dwmapi", PreserveSig = true)]
        [return: MarshalAs(UnmanagedType.Error)]
        internal static extern int DwmExtendFrameIntoClientArea(IntPtr hWnd, [In] ref MARGINS pMarInset);

        [DllImport("user32")]
        internal static extern IntPtr DefWindowProc([In] IntPtr hwnd, [In] int msg, [In] IntPtr wParam, [In] IntPtr lParam);

        [DllImport("user32")]
        [return: MarshalAs(UnmanagedType.Bool)]
        internal static extern bool GetMonitorInfo([In] IntPtr hMonitor, [Out] MONITORINFO lpmi);

        [DllImport("user32")]
        internal static extern IntPtr MonitorFromWindow([In] IntPtr handle, [In] int flags);
    }
}
