int LED = 12;
int Switch1 = 2; //pin 2 will be attached to our switch

void setup() {
  //setup both an output AND an input on the HERO
  pinMode(LED, OUTPUT);
  pinMode(Switch1, INPUT);
}

void loop() {
  //now within loop() we'll take actions based on the status of the input switch
  //this is a conditional test...
  if (digitalRead(Switch1) == HIGH){
    digitalWrite(LED, HIGH); // turn LED ON
  }
  else {
    digitalWrite(LED, LOW); // turn LED OFF
  }
}