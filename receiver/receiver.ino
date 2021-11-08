#include <VirtualWire.h>
#include "lcdgfx.h"
#include "lcdgfx_gui.h"
//receiver 

byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message


//specifies display
//DisplaySSD1306_128x64_I2C display(-1);

void setup()
{
  Serial.begin(9600);
  Serial.println("device is ready...");

  vw_set_rx_pin(12);
  vw_setup(8000); // bps
  vw_rx_start();
/*
  //inizializes display
  display.setFixedFont( ssd1306xled_font6x8 );
  display.begin();
  display.clear();
*/
}

void loop()
{
  if (vw_get_message(message, &messageLength)) // non-blocking
  {
    Serial.print("received: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.print(message[i]);    //normalerweise Serial.write() 
    }
    Serial.println();
  }
}
