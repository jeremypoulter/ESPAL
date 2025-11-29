#ifndef _ESPAL_H
#define _ESPAL_H

#include <Arduino.h>

#ifndef ESPAL_ID_ENCODING_BASE
#define ESPAL_ID_ENCODING_BASE 16
#endif

#ifndef ESPAL_SHORT_ID_LENGTH
#define ESPAL_SHORT_ID_LENGTH 4
#endif

class HalClass
{
  public:
    virtual uint64_t getChipId() = 0;
    virtual uint32_t getFreeHeap() = 0;
    virtual uint32_t getFlashChipSize() = 0;
    virtual size_t getUpdateSize() = 0;

    virtual void reset() = 0;
    virtual void eraseConfig() = 0;

    virtual String getShortId();
    virtual String getLongId(int base = ESPAL_ID_ENCODING_BASE);
    virtual void begin();

    virtual String getChipInfo() = 0;
};

#if defined(EPOXY_DUINO)
#include "espal_epoxyduino.h"
extern HalEpoxyDuino ESPAL;
#elif defined(ESP32)
#include "espal_esp32.h"
extern HalEsp32 ESPAL;
#elif defined(ESP8266)
#include "espal_esp8266.h"
extern HalEsp8266 ESPAL;
#else
#error Platform not supported
#endif

#endif // !_ESPAL_H
