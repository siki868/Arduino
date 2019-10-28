#include <dht.h>
#define DHTPIN 0

dht DHT11;

//DHT dht(DHTPIN, DHT11);


void setup(){
  Serial.begin(9600);
  pinMode(DHTPIN, INPUT);
}


void loop(){
  int nes = DHT11.read(DHTPIN);
  Serial.println(nes);
  delay(3000);
}
