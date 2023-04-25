#include <U8glib.h>

U8GLIB_SH1106_128X64 My_u8g_Panel(U8G_I2C_OPT_NONE);	// I2C / TWI 

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here
  My_u8g_Panel.setFont(u8g_font_unifont);
  My_u8g_Panel.drawStr(0, 22, "Hello World!"); // 0 is the x position, 22 is the y position, both from top left
}

void setup(void) {
  // flip screen, if required
  // My_u8g_Panel.setRot180();

  // assign default colour value
  My_u8g_Panel.setColorIndex(1); // pixel on - This is an intermediate grey level

  // pinMode(8, OUTPUT);
}

void loop() {
  // picture loop
  My_u8g_Panel.firstPage();
  do {
    draw();
  } while( My_u8g_Panel.nextPage() ); // Continue until this returns a zero
}
