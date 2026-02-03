#include "leds.h"
#include "sylib/sylib.hpp"

auto leftUnderglow = sylib::Addrled(22, 7, 60);
auto rightUnderglow = sylib::Addrled(22, 8, 60);

int colorRed = 0xFF0000;
int colorBlue = 0x0000FF;
int colorGreen = 0x7CFC00;
int colorPink = 0xFF00FF;

bool PINK = false;

void rainbow() {
    // underglow rainbow cycle
    leftUnderglow.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
    leftUnderglow.cycle(*leftUnderglow, 10);
    rightUnderglow.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
    rightUnderglow.cycle(*rightUnderglow, 10);
}

void setUnderglow(uint32_t input) {
    if (PINK) {
        leftUnderglow.set_all(0xFF00FF);
        rightUnderglow.set_all(0xFF00FF);
    } else {
        leftUnderglow.set_all(input);
        rightUnderglow.set_all(input);
    }
}