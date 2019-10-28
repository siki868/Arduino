// Kontrola autica preko bt
 
const int motorA1      = 3;  
const int motorA2      = 4; 
const int motorAspeed  = 5;
const int motorB1      = 7; 
const int motorB2      = 8; 
const int motorBspeed  = 6;
  

int state;
int vSpeed = 200; // 0-255

void setup() {
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
   
    Serial.begin(9600);
}
 
void loop() {
  
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
   Serial.println(state); 
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}
     
  /***********************Napred****************************/
  if (state == 'F') {
    digitalWrite (motorA1,LOW);
    delay(1);
    digitalWrite(motorA2,HIGH);                       
    delay(1);
    
    digitalWrite (motorB1,LOW);
    delay(1);
    digitalWrite(motorB2,HIGH);
  
    analogWrite (motorAspeed, vSpeed);
    analogWrite (motorBspeed, vSpeed);
  }
  /**********************Napred levo************************/
  else if (state == 'I') {
    digitalWrite (motorA1,LOW);
    delay(1);
    digitalWrite(motorA2,HIGH);                       
    delay(1);
    
    digitalWrite (motorB1,LOW);
    delay(1);
    digitalWrite(motorB2,HIGH);
  
    analogWrite (motorAspeed, 0);
    analogWrite (motorBspeed, vSpeed);
  }
  /**********************Pravo desno************************/
  else if (state == 'G') {
    digitalWrite (motorA1,LOW);
    delay(1);
    digitalWrite(motorA2,HIGH);                       
    delay(1);
    
    digitalWrite (motorB1,LOW);
    delay(1);
    digitalWrite(motorB2,HIGH);
  
    analogWrite (motorAspeed, vSpeed);
    analogWrite (motorBspeed, 0);
  }
  /***********************Nazad****************************/
  else if (state == 'B') {
    digitalWrite (motorA1,HIGH);
    delay(1);
    digitalWrite(motorA2,LOW);                       
    delay(1);
    
    digitalWrite (motorB1,HIGH);
    delay(1);
    digitalWrite(motorB2,LOW);
  
    analogWrite (motorAspeed, vSpeed);
    analogWrite (motorBspeed, vSpeed);
  }
  /**********************Nazad levo************************/
  else if (state == 'J') {
    digitalWrite (motorA1,HIGH);
    delay(1);
    digitalWrite(motorA2,LOW);                       
    delay(1);
    
    digitalWrite (motorB1,HIGH);
    delay(1);
    digitalWrite(motorB2,LOW);
  
    analogWrite (motorAspeed, 0);
    analogWrite (motorBspeed, vSpeed);
  }
  /**********************Nazad desno************************/
  else if (state == 'H') {
    digitalWrite (motorA1,HIGH);
    delay(1);
    digitalWrite(motorA2,LOW);                       
    delay(1);
    
    digitalWrite (motorB1,HIGH);
    delay(1);
    digitalWrite(motorB2,LOW);
  
    analogWrite (motorAspeed, vSpeed);
    analogWrite (motorBspeed, 0);
  }
  /***************************Levo*****************************/
  else if (state == 'L') {
    digitalWrite (motorA2,HIGH);
    delay(1);
    digitalWrite(motorA1,LOW);                       
    delay(1);
    
    digitalWrite (motorB2,LOW);
    delay(1);
    digitalWrite(motorB1,HIGH);
  
    analogWrite (motorAspeed, vSpeed);
    analogWrite (motorBspeed, vSpeed);
  }
  /***************************Desno*****************************/
  else if (state == 'R') {
    digitalWrite (motorA2,LOW);
    delay(1);
    digitalWrite(motorA1,HIGH);                       
    delay(1);
    
    digitalWrite (motorB2,HIGH);
    delay(1);
    digitalWrite(motorB1,LOW);
  
    analogWrite (motorAspeed, vSpeed);
    analogWrite (motorBspeed, vSpeed);    
  }
     /************************Staje*****************************/
  else if (state == 'S'){
    analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
    analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
  }
 
    
}
