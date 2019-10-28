#include <DHT.h>
DHT dht;

int dhtPin = 0;


void setup() {

  Serial.begin(9600);

}

void loop() {

  dht.read11(dhtPin);
  Serial.println("Vlaznost = ");
  Serial.print(dht.humidity);
  Serial.print("%");
  Serial.println("Temperatura = ");
  Serial.print(dht.temperature);
  Serial.print("C");

  delay(5000);

}
