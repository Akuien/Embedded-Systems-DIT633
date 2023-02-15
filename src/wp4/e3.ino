// C++ code
//
#include <Adafruit_NeoPixel.h>
#define LED_PIN 8
#define LED_PIN_RED 7
#define BUZZER_PIN 6
#define LIGHTS 12
#define TEMP_PIN A1

Adafruit_NeoPixel strip(LIGHTS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  strip.begin();
  strip.show();
}

void fillColors(int amount) {

  for(int i = 0; i < amount; i++) {
      strip.setPixelColor(i, 64, 156, 255);
      strip.show();
    }
  
   for(int i = 12; i >= amount; i--) {
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
    }

}

void loop()
{
  int temp = ((analogRead(TEMP_PIN)* 5.0 / 1023.0)-0.5)*100;
 
  
  if(temp < 0) {
  
    fillColors(1);
  } else if(temp >= 0 && temp < 10) {
    
    fillColors(3);
  } else if(temp >= 10 && temp < 20) {
      
    fillColors(6);
  } else if(temp >= 20 && temp < 30) {
     
    fillColors(9);
    
  } else if(temp >= 30) {
  
    fillColors(12);
    digitalWrite(LED_PIN_RED, HIGH);
    tone(BUZZER_PIN, 50);
  }

  digitalWrite(LED_PIN_RED, LOW);
  delay(50);
  noTone(BUZZER_PIN);
}