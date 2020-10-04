#include <dht.h>
#include "sensors_avr.h"
#include "sensors_pic32.h"
#include <stdio.h>
#include <Arduino.h>
#define dht_apin A1
int smokeA5 = A5;
int SmokeParameter = 0;

dht DHT;

void setup() {
  pinMode(smokeMQ-2, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pin_write(LED_PIN, LOW);

  Serial.begin(GPS_BAUDRATE);
  Serial.println("RESET");
  buzzer_setup();
  gps_setup();
  sensors_setup()
  Serial.begin(9600);
  delay(1500);

void loop() {

  
  while (analogSmokeSensor >= SmokeParameter)
  { 
    Serial.print("Smoke Reading: ");
    Serial.println(analogSmokeSensor);
    Serial.print("Temperature Reading (Celsius): ");
    Serial.println(DHT.temperature); 
    Serial.print("Transmitted. \n");

    Serial.print("============================================\n");
    
        gps_reset_parser();
      
        do {
          if (Serial.available())
            valid_pos = gps_decode(Serial.read());
        } while ( (millis() - timeout < VALID_POS_TIMEOUT) && ! valid_pos) ;
      
        if (valid_pos) {
          if (gps_altitude > BUZZER_ALTITUDE) {
            buzzer_off();   
          } else {
            buzzer_on();
          }
        }
        while (Serial.available()) {
          Serial.read();
        }
    delay(1000);
  }
  if (analogSmokeSensor < SmokeParameter)
  {
    Serial.begin(9600);
    Serial.print("\nUnder Threshold. \n");
  }
  
  delay(1000);
}
