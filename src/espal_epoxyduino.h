#ifndef _ESPAL_H
#error Do not include directly, #include "espal.h"
#endif // !_ESPAL_H

class HalEpoxyDuino : public HalClass
{
  public:
    virtual uint64_t getChipId() {
      return 0x1234567890ABCDEF;
    }
    virtual uint32_t getFreeHeap() {
      return 0xFFFFFFFF;
    }
    virtual uint32_t getFlashChipSize() {
      return 0xFFFFFFFF;
    }
    virtual size_t getUpdateSize() {
      // #define UPDATE_SIZE_UNKNOWN 0xFFFFFFFF
      return 0xFFFFFFFF;
    }
    virtual void reset() {
    }
    virtual void eraseConfig() {
    }
    virtual String getChipInfo() {
      return "EpoxyDuino";
    }
};
