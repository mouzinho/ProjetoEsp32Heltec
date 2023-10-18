#include "IoTreeDisplay.h"

/* Definicoes do OLED */
#define OLED_SDA_PIN    4
#define OLED_SCL_PIN    15
#define SCREEN_WIDTH    128 
#define SCREEN_HEIGHT   64  
#define OLED_ADDR       0x3C 
#define OLED_RESET      16
 
/* Offset de linhas no display OLED */
#define OLED_LINE1     0
#define OLED_LINE2     10
#define OLED_LINE3     20
#define OLED_LINE4     30
#define OLED_LINE5     40
#define OLED_LINE6     50

/* Variaveis e objetos globais */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void IoTreeDisplay::display_init()
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) 
    {
        Serial.println("Falha ao inicializar comunicacao com OLED");        
    }
    else
    {
        Serial.println("Comunicacao com OLED inicializada com sucesso");
     
        /* Limpa display e configura tamanho de fonte */
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
    }
}

