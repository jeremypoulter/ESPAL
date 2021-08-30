#ifndef _ESPAL_H
#error Do not include directly, #include "espal.h"
#endif // !_ESPAL_H

class HalEsp32 : public HalClass
{
  public:
    virtual uint64_t getChipId() {
      return ESP.getEfuseMac();
    }
    virtual uint32_t getFreeHeap() {
      return ESP.getFreeHeap();
    }
    virtual uint32_t getFlashChipSize() {
      return ESP.getFlashChipSize();
    }
    virtual size_t getUpdateSize() {
      // #define UPDATE_SIZE_UNKNOWN 0xFFFFFFFF
      return 0xFFFFFFFF;
    }
    virtual void reset() {
      ESP.restart();
    }
    virtual void eraseConfig() {
    }
    virtual String getChipInfo() {
      esp_chip_info_t info;
      esp_chip_info(&info);
      String infoString =
        String(CHIP_ESP32 == info.model ? "ESP32" : "UNKOWN") +
        "r" + String(info.revision) +
        " " + String(info.cores) + " core";
      if(info.features & CHIP_FEATURE_WIFI_BGN) {
        infoString += " WiFi";
      }
      if(info.features & CHIP_FEATURE_BLE) {
        infoString += " BLE";
      }
      if(info.features & CHIP_FEATURE_BT) {
        infoString += " BT";
      }
      if(info.features & CHIP_FEATURE_EMB_FLASH) {
        infoString += " Flash";
      }
      return infoString;
    }
};
