#include "espal.h"

#include <base64.h>
#include <stdio.h>

#if defined(EPOXY_DUINO)
HalEpoxyDuino ESPAL = HalEpoxyDuino();
#elif defined(ESP32)
HalEsp32 ESPAL = HalEsp32();
#elif defined(ESP8266)
HalEsp8266 ESPAL = HalEsp8266();
#endif

String HalClass::getShortId()
{
  String longId = getLongId();
  unsigned int len = longId.length();
  return longId.substring(len - ESPAL_SHORT_ID_LENGTH);
}

String HalClass::getLongId(int base)
{
// This probably needs to be platform specific, assumes the ChipID is a MAC address, only true on the ESP32
  if(10 == base || 16 == base)
  {
    uint64_t chipId = getChipId();
    // Swap the bytes arround so the unique bit is at right
    chipId = (chipId & 0x00000000FFFFFFFF) << 32 | (chipId & 0xFFFFFFFF00000000) >> 32;
    chipId = (chipId & 0x0000FFFF0000FFFF) << 16 | (chipId & 0xFFFF0000FFFF0000) >> 16;
    chipId = (chipId & 0x00FF00FF00FF00FF) << 8  | (chipId & 0xFF00FF00FF00FF00) >> 8;
    chipId = chipId >> 16;

    char longId[16];
#ifdef EPOXY_DUINO
    snprintf(longId, sizeof(longId), 10 == base ? "%lu" : "%lx", chipId);
#else
    sniprintf(longId, sizeof(longId), 10 == base ? "%llu" : "%llx", chipId);
#endif

    return String(longId);
  }
  else if(64 == base)
  {
    uint64_t chipId = getChipId();
    uint8_t *idBytes = (uint8_t *)&chipId;

    return base64::encode(idBytes, 6);
  }

  return "Not Supported";
}

void HalClass::begin()
{
}
