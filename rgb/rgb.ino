int red = 9;
int green = 10;
int blue = 11;

void setColor(int r, int g, int b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  setColor(0, 0, 255);
  delay(5);
}
