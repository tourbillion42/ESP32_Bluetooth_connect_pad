#include "BluetoothSerial.h"

BluetoothSerial BTS;

int PirLed = 26;
int PirInput = 13;

void setup() {
  Serial.begin(9600);
  BTS.begin("ESP32_Control");
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode(PirLed, OUTPUT);
  pinMode(PirInput, INPUT);
}

void loop() {
  int pir = digitalRead(PirInput);

  if(pir == HIGH) {
    digitalWrite(PirLed, HIGH);
    Serial.println(pir);
    BTS.println(pir);
    delay(100);
  }
  else {
    digitalWrite(PirLed, LOW);
    Serial.println(pir);
    BTS.println(pir);
    delay(100);
  }
}
