#pragma once

#if defined(__unix__)
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
// undef Xlib macros that conflict with our symbols,
// but only after including X11 headers that use them.
#undef Status
#undef DisableScreenSaver

#include <wayland-client.h>
#include <wayland-egl.h>
#elif defined(_WIN32)
#include <windows.h>
#endif

// Represents a platform-native window handle shared between GUI and components.
struct NativeWindowHandle {
	enum {
#if defined(__unix__)
		WAYLAND,
		X11,
#elif defined(_WIN32)
		WIN32,
#endif
	} kind;

	union
	{
#if defined(__unix__)
		struct {
			wl_display* display;
			wl_egl_window* egl_window;
		} wayland;

		struct {
			Display* display;
			Window window;
		} x11;
#elif defined(_WIN32)
		HWND win32;
#endif
	};
};
