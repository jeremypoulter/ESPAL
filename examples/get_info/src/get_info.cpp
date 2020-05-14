#include <Arduino.h>
#include <espal.h>

void setup()
{
  Serial.begin(115200);

  Serial.println("");
  Serial.println("ESPAL");
  Serial.println("");

  Serial.printf("Chip ID = %llx\n", ESPAL.getChipId());

  Serial.print("Free Heap = ");
  Serial.println(ESPAL.getFreeHeap());

  Serial.print("Flash Chip Size = ");
  Serial.println(ESPAL.getFlashChipSize());

  Serial.print("Short ID = ");
  Serial.println(ESPAL.getShortId());

  Serial.print("Long ID = ");
  Serial.println(ESPAL.getLongId());

}

void loop()
{
}
