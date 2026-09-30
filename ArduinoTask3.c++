#include <Arduino.h>

int pins[4] = {5, 4, 3, 2}; 

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < 4; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {

  int num = Serial.parseInt();

  if (num >= 0 && num <= 15) {
    String binary = "";
    int temp = num;

    while(temp>0){
      int bit = temp % 2;
      binary = String(bit) + binary;
      temp = temp / 2;
    }

    for (int i = 0; i < 4; i++) {
      if (binary[i] == '1') {
        digitalWrite(pins[i], HIGH); 
      } else {
        digitalWrite(pins[i], LOW);  
      }
    }
  }

  delay(1000);
}