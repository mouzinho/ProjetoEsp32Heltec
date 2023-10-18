#ifndef _sensorDendrometro
#define _sensorDendrometro

//Inclusão de Bibliotecas
#include <Arduino.h>

class sensorDendometro {
public:
  int lerValor(int tempo, int pin);
};

#endif 
