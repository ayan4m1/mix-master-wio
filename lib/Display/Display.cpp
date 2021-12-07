#include "Display.hpp"

TFT_eSPI Display::display = TFT_eSPI();

void Display::init() {
  display.init();
  display.setRotation(1);
  display.fillScreen(TFT_BLACK);
  display.flush();
}

void Display::update(const DisplayState state) {
  display.fillScreen(TFT_BLACK);
  display.drawNumber(state.mass, 0, 0);
  if (state.stable) {
    display.drawString(F("U"), 60, 0);
  } else {
    display.drawString(F("S"), 60, 0);
  }
  display.flush();
}
