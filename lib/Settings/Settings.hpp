#pragma once

#include <FlashStorage_SAMD.h>

enum DisplayUnits { GRAMS, OUNCES };

struct DeviceSettings {
  float loadCellDivider;
  float loadCellOffset;
  DisplayUnits displayUnits;
};

class Settings {
 public:
  static DeviceSettings init();
  static void write(const DeviceSettings settings);
};
