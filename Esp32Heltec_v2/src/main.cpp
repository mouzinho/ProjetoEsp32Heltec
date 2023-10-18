/* Inclusão de Bibliotecas */
#include "IoTreeLoRa.h"
#include "sensorDendrometro.h"
#include "IoTreeDisplay.h"
 
/* Declaração de Objetos */
ioTreeLoRa dts;
sensorDendometro sensor;
IoTreeDisplay tela;

/* Declaração de Variaveis */
const int pinoPoT = 13;   //Pino analógico do sensor
const char* id = "SDEN";  //ID do sensor Dendrometro
#define BAUDRATE 115200   //Taxa de transmissão de dados
#define uS_TO_S_FACTOR 1000000  //Fator de conversão de microssegundos para segundos
#define TIME_TO_SLEEP 10        //Tempo que o ESP32 irá dormir (em segundos)

RTC_DATA_ATTR int tempo = 0;

/* Configuração de Parâmetros */ 
void setup() 
{    
    tela.display_init();
    while(dts.init_comunicacao_lora() == false); /* Tenta, até obter sucesso, comunicacao com o chip LoRa */
}
 
/* Programa principal */
void loop() 
{
    
    delay(10);
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
    float dados = sensor.lerValor(3000, pinoPoT);
    dts.enviarDados(dados, id);
    Serial.println("Indo dormir agora");
    ++tempo;
    Serial.println("Boot number: " + String(tempo));
    Serial.println("================= ++++++++++++ =================");
    delay(10);
    esp_deep_sleep_start();
    Serial.flush();
}