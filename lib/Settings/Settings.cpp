#include "Settings.hpp"

DeviceSettings Settings::init() {
  auto settings = DeviceSettings();
  const auto eepromUsed = EEPROM.length();

  if (eepromUsed > 0) {
    EEPROM.get(0, settings);
  } else {
    settings.displayUnits = DisplayUnits::GRAMS;
    settings.loadCellDivider = 1;
    settings.loadCellOffset = 0;
    write(settings);
  }

  return settings;
}

void Settings::write(const DeviceSettings settings) {
  EEPROM.put(0, settings);

  if (!EEPROM.getCommitASAP()) {
    EEPROM.commit();
  }
}
