int led = 9;
int knob = 0;

int val;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  val = analogRead(knob);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(led, val);
  delay(15);
}
