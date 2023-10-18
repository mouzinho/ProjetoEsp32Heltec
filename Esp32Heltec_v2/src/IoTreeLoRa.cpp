#include "IoTreeLoRa.h"


/* Definicoes para comunicação com radio LoRa */
#define SCK_LORA           5
#define MISO_LORA          19
#define MOSI_LORA          27
#define RESET_PIN_LORA     14
#define SS_PIN_LORA        18
#define HIGH_GAIN_LORA     20     //Ganho de Sinal dBm 
#define BAND               915E6  //915MHz de frequencia
 
/* Variaveis globais */
long informacao_a_ser_enviada = 0;
RTC_DATA_ATTR int bootCount = 0;
 
bool ioTreeLoRa::init_comunicacao_lora(void)
{
    Serial.begin(115200);
    bool status_init = false;
    Serial.println("Iniciando Comunicação Radio LoRa...");
    SPI.begin(SCK_LORA, MISO_LORA, MOSI_LORA, SS_PIN_LORA);
    LoRa.setPins(SS_PIN_LORA, RESET_PIN_LORA, LORA_DEFAULT_DIO0_PIN);
    if (!LoRa.begin(BAND)) 
    {
        Serial.println("Falha na comunicação Radio LoRa!");        
        delay(1000);
        status_init = false;
    }
    else
    {
        /* Configura o ganho do receptor LoRa para 20dBm, o maior ganho possível (visando maior alcance possível) */
        LoRa.setTxPower(HIGH_GAIN_LORA); 
        Serial.println("Comunicacao Radio LoRa ok");
        status_init = true;
    }
    return status_init;
}

void ioTreeLoRa::enviarDados(int valorSensor, const char* id) {
   Serial.begin(115200); 
  //Converte os valores para strings
  String idString = String(id);
  String valorLDRString = String(valorSensor);
  //Concatena o ID e o valor do sensor em uma única string
  String mensagem = idString + valorLDRString;
  LoRa.beginPacket();
  LoRa.print(mensagem);  //Envia a mensagem como string
  LoRa.endPacket();
  Serial.println("Dados Enviados: " + mensagem);
}
