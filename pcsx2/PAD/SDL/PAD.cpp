#include "PAD.h"

int32_t PADinit() {
  return 0;
}

int32_t PADopen(void *pDisplay) {
  // TODO
  return 0;
}

void PADclose() {
  // TODO
}

void PADshutdown() {}

void PADupdate(uint8_t pad) {
  // TODO
}

uint8_t PADstartPoll(uint8_t pad) {
  // TODO
  return 0;
}

uint8_t PADpoll(uint8_t value) {
  // TODO
  return 0;
}

keyEvent *PADkeyEvent() {
  // TODO
  return nullptr;
}

void PADWriteEvent(const keyEvent event) {
  // TODO
}

void PADconfigure() {
  // TODO
}

int32_t PADsetSlot(uint8_t port, uint8_t slot) {
  // TODO
  return 0;
}

int32_t PADfreeze(uint8_t mode, freezeData *data) {
  // TODO
  return 0;
}

void PADDoFreezeIn(const pxInputStream& reader) {
  // TODO
}

void PADDoFreezeOut(void *dest) {
  // TODO
}
