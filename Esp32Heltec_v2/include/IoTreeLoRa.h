#ifndef _IoTreeLoRa
#define _IoTreeLoRa

#include <LoRa.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

class ioTreeLoRa {
public:
  bool init_comunicacao_lora(void);
  void enviarDados(int valorSensor, const char* id);
};

#endif 
