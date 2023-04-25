int sensorPin = A0; // select the "analog zero" input pin for probing the photoresistor
int onboardLED = 13; // select the pin for the HERO's built-in LED
int sensorValue = 0; // variable thatwe'll use to store the value reading from the sensor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(onboardLED, OUTPUT);
}

void loop() {
  // Read the analog sensor value and send it to serial
  sensorValue = analogRead(sensorPin);
  digitalWrite(onboardLED, HIGH);
  delay(sensorValue);
  digitalWrite(onboardLED, LOW);
  delay(sensorValue);
  
  //Read the analog sensor value and send it to the serial monitor
  Serial.println(sensorValue);
  delay(sensorValue);
}