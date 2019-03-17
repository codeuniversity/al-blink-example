
//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//http://www.genotronex.com/
//..................................
#include <VirtualWire.h>

void setup()
{
  // vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4000); // Bits per sec
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  vw_rx_start(); // Start the receiver PLL running
}
void loop()
{
  uint8_t buf[1];
  uint8_t buflen = 1;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    digitalWrite(7, HIGH);
    Serial.println(buf[0]);
  }
}
