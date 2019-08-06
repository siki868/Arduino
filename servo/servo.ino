#include <Servo.h>
#include <SoftwareSerial.h>

// TxD 3
// RxD 2
// levi motor 5
// desni motor 6
// servo 9


#define TxD 3
#define RxD 2
#define leviMotor 5
#define desniMotor 6
#define POMERAJ 1

SoftwareSerial bluetooth(TxD, RxD);
Servo myServo;

int val;
char data;
bool radi = false;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(leviMotor, OUTPUT);
  pinMode(desniMotor, OUTPUT);
  
  myServo.attach(9);
}

void loop() {
  if(bluetooth.available()){
    char data = bluetooth.read();
    
    if (data == 'l'){
      // Rotiraj levo
      val = myServo.read();
      Serial.println(val);
      val -= POMERAJ;
      if (val < 0) val = 0;
      myServo.write(val);
    } else if (data == 'd' ){
      // Rotiraj desno
      val = myServo.read();
      Serial.println(val);
      val += POMERAJ;
      if (val > 180) val = 180;
      myServo.write(val);
    }
    
    if (data == 'p' and !radi){
      analogWrite(desniMotor, 255);
      analogWrite(leviMotor, 255);
      radi = true;
    }
    if (data == 's' and radi){
      analogWrite(desniMotor, 0);
      analogWrite(leviMotor, 0);
      radi = false;
    }
    
    Serial.print(data);
    Serial.print(" - ");
    Serial.println(data - '0');
  }
  delay(15);
}
