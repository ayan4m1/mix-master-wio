#pragma once

#include <HX711.h>

#define LOAD_CELL_DATA_PIN D1
#define LOAD_CELL_CLOCK_PIN D0

class LoadCell {
  static HX711 cell;

 public:
  static void init();
  static void calibrate(float divider, float offset);
  static float read();
};
