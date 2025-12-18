#include "leds.h"
#include "sylib/sylib.hpp"

auto leftUnderglow = sylib::Addrled(22, 7, 60);
auto rightUnderglow = sylib::Addrled(22, 8, 60);

int colorRed = 0xFF0000;
int colorBlue = 0x0000FF;
int colorGreen = 0x7CFC00;

void rainbow() {
    // underglow rainbow cycle
    leftUnderglow.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
    leftUnderglow.cycle(*leftUnderglow, 10);
    rightUnderglow.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
    rightUnderglow.cycle(*rightUnderglow, 10);
}

void setRed() {
    leftUnderglow.set_all(colorRed);
    rightUnderglow.set_all(colorRed);
}

void setBlue() {
    leftUnderglow.set_all(colorBlue);
    rightUnderglow.set_all(colorBlue);
}

void setGreen() {
    leftUnderglow.set_all(colorGreen);
    rightUnderglow.set_all(colorGreen);
}