int LED1 = 10; //pins 10-12 are LED outputs
int LED2 = 11;
int LED3 = 12;
int Switch1 = 2; //pins 2-4 will be attached to our switch inputs
int Switch2 = 3;
int Switch3 = 4;

void setup() {
// We set up the input and outputs here
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  pinMode(Switch3, INPUT);
}

void loop() {

//now within loop we will take actions based on the status of the input switch

//This is a conditional test..

  if (digitalRead(Switch1)==HIGH) {                // Check Switch #1
    digitalWrite(LED1, HIGH); // turn LED ON)
  }
  else{
    digitalWrite(LED1, LOW); // turn LED OFF
  }

    if (digitalRead(Switch2)==HIGH) {                // Check Switch #2
    digitalWrite(LED2, HIGH); // turn LED ON)
  }
  else{
    digitalWrite(LED2, LOW); // turn LED OFF
  }

    if (digitalRead(Switch3)==HIGH) {                // Check Switch #3
    digitalWrite(LED3, HIGH); // turn LED ON)
  }
  else{
    digitalWrite(LED3, LOW); // turn LED OFF
  }
}
