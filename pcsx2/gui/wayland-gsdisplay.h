#pragma once

#include <wayland-client.h>
#include <wayland-egl.h>
#include "../wayland-idle-inhibit-unstable-v1-client-protocol.h"

// When the GS window handle is a Wayland window,
// the first entry of pDsp will point to one of these.
struct PluginDisplayPropertiesWayland {
	wl_display* display; // NOTE: This display is not owned by this struct.
	wl_egl_window* egl_window;
	wl_surface* surface;
	wl_subsurface* subsurface;
	zwp_idle_inhibitor_v1* idle_inhibitor;
};
