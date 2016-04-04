/*
  ATmega128RFA1 Dev Board Basic Chat
  by: Jim Lindblom
      SparkFun Electronics
  date: July 3, 2012
  License: Beerware. Feel free to use, reuse, and modify this code
  as you please. If you find it useful, you can buy me a beer.
  This code sets up the ATmega128RFA1's wireless transciever in
  the most basic way possible to serve as a serial gateway.
  Serial into the ATmega128RFA1's UART0 will go out the RF radio.
  Data into the RF radio will go out the MCU's UART0.
*/

#include "RadioFunctions.h"

unsigned long time=0;
void setup()
{
  Serial.begin(115200);  // Start up serial
  Serial1.begin(115200);
   
  rfBegin(15);  // Initialize ATmega128RFA1 radio on channel 11 (can be 11-26)
  
  // Send a message to other RF boards on this channel
  //rfPrint("ATmega128RFA1 Dev Board Online!\r\n");
}

// Max amount of data can be sent through the radio
//void loop()
//{  
//  time=micros();
//  if (time<1000000)
//  {
//    Serial.println("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456");
//    rfPrint("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456"); // ...send it out the radio.
//  }
//}

// For one way communication Trx
//void loop()
//{  
//  time=micros();
//  if (time<1000000)
//  {
//    Serial.println("012345678912345678");
//    rfPrint("012345678912345678"); // ...send it out the radio.
//  }
//}

// For two way communication acts as TX and RX
void loop()
{  
  time=micros();
  if (time<1000000)
  {
    Serial.println("012345678912345678");
    rfPrint("012345678912345678"); // ...send it out the radio.
  }
  if (rfAvailable())
  {
    Serial.print(rfRead());
  }
}



