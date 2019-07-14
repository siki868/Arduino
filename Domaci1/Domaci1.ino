
//String str = "200 123456";
int t = 0;                            //milisekunde za delay
String sablon = "";                   //redosled ukljucivanja dioda od prve do seste(1-6)
int ledovi[6] = {3, 5, 6, 9, 10, 11}; //pinovi za diode po redosledu(3. pin za 1. diodu, 5. za 2. itd..)
int knob  = 5;                        //analog pin za potenciometar(A5)


void srediSablon(String s){           //obradjuje string i smesta vrednost u globalne varijable t i sablon
  sablon = "";
  t = 0;
  String tajmer = "";
  int i;
  boolean josT = true;
  for(i = 0; i < s.length(); i++){
    if (josT) tajmer += s.charAt(i);
    if(s.charAt(i) == ' '){
       t = tajmer.toInt();
       josT = false;
       continue;
    }
    if((((s.charAt(i) - '0') >= 0) ||  ((s.charAt(i) - '0') <= 6)) && !josT) sablon += s.charAt(i);
  }
}


void gasiSve(){                     //gasi sve diode
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void pinModes(){                    
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}


void setup() {
  Serial.begin(9600);
  pinModes();
  Serial.println("Upisi string");
}

void loop() {
  
  while(Serial.available()){
    String str = Serial.readString();
    Serial.println("Sting je " + str); 
    srediSablon(str);
    Serial.println("Sablon je " + sablon + " i ceka se " + String(t) + " milisekundi.");
    int i;
    for(i = 0; i < str.length(); i++){
      int val = analogRead(knob);                         //cita vrednost sa potenciometra
      val = map(val, 0, 1023, 0, 255);                    //mapira za dim
      analogWrite(ledovi[sablon.charAt(i) - '0' - 1], val);  //pali diodu direktno iz sablona, tj ako je u sablonu dioda broj 2 znaci da treba da se pali index 1 iz "ledovi"
      delay(t);
      gasiSve();
    }
  }
  
}
