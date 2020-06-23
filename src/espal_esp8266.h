#ifndef _ESPAL_H
#error Do not include directly, #include "espal.h" 
#endif // !_ESPAL_H

class HalEsp8266 : public HalClass
{
  public:
    virtual uint64_t getChipId() {
      uint64_t id = ESP.getChipId();
      return id << 24;
    }
    virtual uint32_t getFreeHeap() {
      return ESP.getFreeHeap();
    }
    virtual uint32_t getFlashChipSize() {
      return ESP.getFlashChipSize();
    }
    virtual size_t getUpdateSize() {
      return (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
    }
    virtual void reset() {
      ESP.reset();
    }
    virtual void eraseConfig() {
      ESP.eraseConfig();
    }
};
