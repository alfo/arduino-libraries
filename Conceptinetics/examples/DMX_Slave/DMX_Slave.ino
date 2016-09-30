#include <Conceptinetics.h>
#include <Servo.h>

#define DMX_SLAVE_CHANNELS   2
#define RXEN_PIN             2

DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS , RXEN_PIN );
Servo motor;

const int ledPin = 13;

void setup() {             



  dmx_slave.enable ();  
  dmx_slave.setStartAddress (1);
  motor.attach(3);
  
  pinMode ( ledPin, OUTPUT );
}

void loop() 
{
  //
  // EXAMPLE DESCRIPTION
  //
  // If the first channel comes above 50% the led will switch on
  // and below 50% the led will be turned off
  
  // NOTE:
  // getChannelValue is relative to the configured startaddress


  
  motor.write(dmx_slave.getChannelValue(1));
    
  
}
