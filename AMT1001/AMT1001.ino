#include "amt1001_ino.h"
#define tempPin A5    // White Wire
#define humPin A4     // Yellow Wire 
#define LED 3 
uint16_t step1;
uint16_t step2;
uint16_t temperature;
uint16_t humidity;
double volt;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
   pinMode(LED, OUTPUT);  
}

void loop() {
// Get Temperature
 step1 = analogRead(tempPin);  //White Wire
 temperature = amt1001_gettemperature(step1);
Serial.print("temperature :");
Serial.print(temperature);
Serial.print(" *C");

// Get Humidity
 step2 = analogRead(humPin);  //Yellow Wire 
 volt = (double)step2 * (5.0 / 1023.0);
 humidity = amt1001_gethumidity(volt);  
 Serial.print("    ");
 Serial.print("humidity :");
Serial.print(humidity);
 Serial.print(" %");

 
if(temperature>=23){                          
  digitalWrite(LED,1);
  Serial.println("  :เปิดไฟ");
  }else{
  digitalWrite(LED,0);
  Serial.println("ปิดไฟ");
    }
}
