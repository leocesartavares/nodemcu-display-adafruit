#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include "SSD1306Wire.h"

/**********************************************
 * DEVICES: 
 * Display
 * ADC Adafruit
 *********************************************/
SSD1306Wire  display(0x3c, D6, D7);

Adafruit_ADS1115 ads(0x48);
 
void screen(){
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  
  //Seleciona a fonte
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 2, " 2 Photosensors");
  //Desenha um quadrado
  display.drawRect(00, 20, 63, 43);
  display.drawRect(64, 20, 63, 43);
  //Desenha um quadrado cheio
}

void print_values(){
  int16_t adc0, adc1;

  screen();
  
  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);

  display.drawString(32, 33, String(adc0));
  display.drawString(96, 33, String(adc1));
  display.display();


  Serial.print("AIN0: ");
  Serial.println(adc0);
  Serial.print("AIN1: ");
  Serial.println(adc1);
  Serial.println(" ");
  
}

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Hello!");
 
  ads.begin();
  display.init();
  display.flipScreenVertically();
}


void loop(void)
{
  print_values();
  delay(1000);
}
