int Light = 12 ; //HERO board 12

void setup() {
  // put your setup code here, to run once:
  pinMode(Light, OUTPUT);
  digitalWrite(Light, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Light, LOW);
  delay(1000);
  digitalWrite(Light, HIGH);
  delay(500);
}