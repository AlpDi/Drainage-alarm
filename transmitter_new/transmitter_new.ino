//transmitter 


#include <VirtualWire.h>

int waterpin = A2;

void setup() 
{
  Serial.begin(9600); 

  // virtual wire
  vw_set_tx_pin(12); // pin
  vw_setup(8000); // bps

  //water sensor
  pinMode(waterpin, INPUT);

}

void loop()
{
  int waterlevel = analogRead(waterpin);
  String str_water = String(waterlevel);
  if (waterlevel < 100) { str_water = "0" + str_water;}
  sendString(str_water, true); 
  delay(100); 
}

void sendString(String message, bool wait)
{
  byte messageLength = message.length() + 1; 

  // convert string to char array
  char charBuffer[messageLength]; 
  message.toCharArray(charBuffer, messageLength);

  vw_send((uint8_t *)charBuffer, messageLength); 

  if (wait) vw_wait_tx(); 

  //Serial.println("sent: " + message);
  Serial.println(message); 
}
