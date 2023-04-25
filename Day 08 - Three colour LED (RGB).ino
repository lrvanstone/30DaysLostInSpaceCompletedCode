int red = 11; // these are our output pins for the three LED colours
int green = 10;
int blue = 9;

void setup() {
// set our pins to drive output to the LEDs (runs once)

  pinMode(red , OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void RGB_color(int red_value, int green_value, int blue_value)
{
// custom function to set three PWM (Pulse Width Modulation) colour channels to any given mixture

  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}

void loop() {
  //Cycle through several different colour settings

  RGB_color(125, 0, 0); // Red
  delay(800);
  RGB_color(0, 125, 0); // Green
  delay(800);
  RGB_color(0, 0, 125); // Blue
  delay(800);
  RGB_color(64, 32, 0); // yellow
  delay(800);
  RGB_color(125, 0, 125); // purple
  delay(800);
  RGB_color(125, 125, 125); // White
  delay(2000);

}
