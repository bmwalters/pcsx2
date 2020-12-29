#pragma once

#include <stdint.h>
#include "../../../common/include/PS2Edefs.h"
#include "../../../common/include/Utilities/pxStreams.h"

// TODO: Docs
int32_t PADinit();

// TODO: Docs
// pDisplay normally is passed a handle to the GS plugins window.
int32_t PADopen(void *pDisplay);

// TODO: Docs
void PADclose();

// TODO: Docs
void PADshutdown();

// TODO: Docs
// pad: always zero
void PADupdate(uint8_t pad);

// TODO: Doc
uint8_t PADstartPoll(uint8_t pad);

// TODO: Doc
uint8_t PADpoll(uint8_t value);

// PADkeyEvent is called every vsync (return NULL if no event)
// TODO: Doc interaction with PADupdate (PADupdate prepares events for keyEvent to return
keyEvent *PADkeyEvent();

// Used to inject an event that was swallowed by some other framework
// but should still be distributed via PADkeyEvent.
void PADWriteEvent(const keyEvent event);

// Displays configuration GUI for the PAD plugin.
// TODO: Doc how window is parented, etc.
void PADconfigure();

// Sets the active pad slot for the specified port.
// Both numbers are 1-based indices.  Should return 0 if there's no
// pad on the specified slot.  Even if PADqueryMtap(port) returns 0,
// should handle this properly for slot != 1, so emulator can allow
// Multitap to be enabled/disabled elsewhere.
int32_t PADsetSlot(uint8_t port, uint8_t slot);

// Fills in freezeData with the amount of data that would be
// written by PADDoFreezeOut.
int32_t PADfreeze(uint8_t mode, freezeData *data);

// Restores PAD state by reading data from a save state.
void PADDoFreezeIn(const pxInputStream& reader);

// Saves PAD state to a save state.
void PADDoFreezeOut(void *dest);
