#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},  // 1st row
  {'4', '5', '6', 'B'},  // 2nd row
  {'7', '8', '9', 'C'},  // 3rd row
  {'*', '0', '#', 'D'}   // 4th row
};

Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS); // This maps the characters for our buttons onto the relevant pins of the HERO

//* Original frequencies
int tones[ROWS][COLS] = {  // a frequency tone for each button
  {31, 93, 147, 208},
  {247, 311, 370, 440},
  {523, 587, 698, 880},
  {1397, 2637, 3729, 4978}

/* Alternative mapping of frequencies on the keyboard
int tones[ROWS][COLS] = {  // a frequency tone for each button - in semitones
  {261, 277, 294, 311},
  {330, 350, 370, 392},
  {415, 440, 466, 494},
  {523, 554, 587, 622}
};
*/

int buzzer = 10; // pin 10 drives the buzzer

void setup() {
  Serial.begin(9600); // Begin monitoring via the serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:

  int toneFreq = 0; // we set this to zero because when no button is pressed, we want no sound to be generated
  char result = myAwesomePad.getKey();

  if(result){  // If button is pressed

    for (byte j=0; j<ROWS; j++) {
      for (byte i=0; i<COLS; i++) {
        if (result == buttons[j][i]) {  // found it, get the corresponding tone
          toneFreq=tones[i][j];
        }
      } // end i loop
    }  // end j loop

    Serial.print("Key: ");  // send the result to serial monitor...
    Serial.print(result);
    Serial.print("  Freq:  ");
    Serial.println(toneFreq);

    tone(buzzer, toneFreq, 500); // ... and play the tone for half a second
    delay(100);
    noTone(buzzer);
  }
}

