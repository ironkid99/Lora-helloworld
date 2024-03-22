#include <LoRa.h>

int csPin = 17;      
int resetPin = 4;    
  
long frequency = 433E6;  

void setup() {
  Serial.begin(9600);

  
  LoRa.setPins(csPin, resetPin);
  LoRa.setTxPower(20);
  LoRa.setSpreadingFactor(12);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setCodingRate4(5);
  
  if (!LoRa.begin(frequency)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (true);  // if failed, do nothing
  }

  Serial.println("LoRa init succeeded.");
  Serial.println();
  Serial.println("LoRa Simple Node");
  Serial.println("Transmitter side");
  Serial.println("Tx: invertIQ disable");
  Serial.println("Rx: invertIQ enable");
  Serial.println();
}

void loop() {
  
  String message = "Hello, World!";
  
 
  LoRa.beginPacket();
  
 
  LoRa.print(message);
  
  
  LoRa.endPacket();

  Serial.println("Message sent: " + message);
  
  delay(5000);  
}
