#include "LoadCell.hpp"

HX711 LoadCell::cell = HX711();

void LoadCell::init() {
  cell.begin(LOAD_CELL_DATA_PIN, LOAD_CELL_CLOCK_PIN, 32);
}

void LoadCell::calibrate(float divider, float offset) {
  cell.set_scale(divider);
  cell.set_offset(offset);
}

float LoadCell::read() { return cell.get_units(10); }
