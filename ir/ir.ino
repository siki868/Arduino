#include <IRremote.h>
#include <IRremoteInt.h>

int pin = 11;
IRrecv receiver(pin);
decode_results res;



void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
}

void loop() {
  if(receiver.decode(&res)){
    Serial.println(res.value, HEX);
    receiver.resume();
  }
}
