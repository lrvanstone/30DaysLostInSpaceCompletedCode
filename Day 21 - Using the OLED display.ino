#include <U8glib.h>

U8GLIB_SH1106_128X64 My_u8g_Panel(U8G_I2C_OPT_NONE); // I2C / TWI
int DIPswitch1 = 8;
int DIPswitch2 = 9;
int DIPswitch3 = 10;

int CLK2 = 2;
int DT2 = 3;

void setup(void) {
  // flip screen, if required
  // My_u8g_Panel.setRot180();

  // assign default colour value
  My_u8g_Panel.setColorIndex(1); // pixel on - This is an intermediate grey level
  pinMode(DIPswitch1, OUTPUT);
  pinMode(DIPswitch2, OUTPUT);
  pinMode(DIPswitch3, OUTPUT);

  pinMode(CLK2, INPUT);
  pinMode(DT2, INPUT);
}

void draw(void) {
 
  // graphic commands to redraw the complete screen should be placed here
  My_u8g_Panel.setFont(u8g_font_unifont);
  

  String tempStr;
  /*if(digitalRead(DIPswitch1)){
    tempStr = tempStr + "On";
  }
  else{
    tempStr = tempStr + "Off";
  }
  if(digitalRead(DIPswitch2)){
    tempStr = tempStr + " On";
  }
  else{
    tempStr = tempStr + " Off";
  }
  if(digitalRead(DIPswitch3)){
    tempStr = tempStr + " On";
  }
  else{
    tempStr = tempStr + " Off";
  }*/

  tempStr = tempStr + digitalRead(DIPswitch1) + " ";
  tempStr = tempStr + digitalRead(DIPswitch2) + " ";
  tempStr = tempStr + digitalRead(DIPswitch3) + " ";
  tempStr = tempStr + digitalRead(CLK2);

  char drawChar[tempStr.length()+1];
  tempStr.toCharArray(drawChar, tempStr.length()+1);
  My_u8g_Panel.drawStr(0, 22, "DIP Switches");
  My_u8g_Panel.drawStr(0, 44, drawChar);
}


void loop() {
  // picture loop
  My_u8g_Panel.firstPage();
  do {
    draw();
  } while( My_u8g_Panel.nextPage() ); // Continue until this returns a zero
}
