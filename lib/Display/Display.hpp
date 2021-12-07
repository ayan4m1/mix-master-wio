#pragma once

#include <SPI.h>
#include <TFT_eSPI.h>

struct DisplayState {
  float mass;
  bool stable;
};

class Display {
  static TFT_eSPI display;

 public:
  static void init();
  static void update(const DisplayState state);
};
