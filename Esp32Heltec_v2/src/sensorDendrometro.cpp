//Inclusão de Bibliotecas
#include "sensorDendrometro.h"

int sensorDendometro::lerValor(int tempo, int pin) {
  float valor = (analogRead(pin) * 5/4095);
  Serial.print("Valor: ");
  Serial.println(valor, 2);
  delay(tempo);
  return valor;
}