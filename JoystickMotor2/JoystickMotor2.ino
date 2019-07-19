/*
 *  SW pin 2
 *  X pin A0
 *  Y pin A1
 *  
 *  Levi motor 6
 *  Desni motor 5
 */


const int sw = 2;
const int pin_X = 0;
const int pin_Y = 1;

const int motor_desno = 5;
const int motor_levo = 6;

int x = 0;
int y = 0;

void setup() {
  pinMode(sw, INPUT);
  digitalWrite(sw, HIGH);
  Serial.begin(9600);
}

void loop() {
  x = analogRead(pin_X);
  y = analogRead(pin_Y);
  if (x < 525){
    x = map(x, 520, 0, 0, 255);
    if (y < 520){
      Serial.println("Desno");
      y = map(x, 520, 0, 0, 255);

      analogWrite(motor_desno, y);
      analogWrite(motor_levo, x);
      // y - desni tocak
      // x - levi tocak
    }else{
      Serial.println("Levo");
      y -= 520;
      y = map(y, 0, 503, 0, 255);

      analogWrite(motor_desno, x);
      analogWrite(motor_levo, y);
      // x - desni tocak
      // y - levi tocak
    }
    if (x > 250 and y < 10){
      analogWrite(motor_desno, x);
      analogWrite(motor_levo, x);
    }
    Serial.println(x);
    Serial.println(y);
    Serial.print("\n\n");
    delay(200);
  }

  
}
