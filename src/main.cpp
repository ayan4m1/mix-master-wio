#include <Arduino.h>

#include "Display.hpp"
#include "LoadCell.hpp"
#include "Settings.hpp"

DisplayState state;
DeviceSettings settings;

void setup() {
  state = DisplayState();
  settings = Settings::init();

  LoadCell::init();
  LoadCell::calibrate(settings.loadCellDivider, settings.loadCellOffset);

  Display::init();
}

void loop() {
  auto newState = DisplayState();
  newState.mass = LoadCell::read();
  newState.stable = abs(state.mass - newState.mass) < 0.02;

  Display::update(newState);
  state = newState;
  delay(500);
}
