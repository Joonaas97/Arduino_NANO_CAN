/****************************************************************************
CAN Write Demo for the SparkFun CAN Bus Shield. 

Written by Stephen McCoy. 
Original tutorial available here: http://www.instructables.com/id/CAN-Bus-Sniffing-and-Broadcasting-with-Arduino
Used with permission 2016. License CC By SA. 

Distributed as-is; no warranty is given.
*************************************************************************/

#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

//********************************Setup Loop*********************************//

void setup() {
  Serial.begin(9600);
  Serial.println("CAN Write - Testing transmission of CAN Bus messages");
  delay(1000);
  
  if(Canbus.init(CANSPEED_500))  //Initialise MCP2515 CAN controller at the specified speed
    Serial.println("CAN Init ok");
  else
    Serial.println("Can't init CAN");
    
#define OUTPUT_PIN
  pinMode(0, OUTPUT);
  #define OUTPUT_PIN
  pinMode(1, OUTPUT);

delay(1000);
}

//********************************Main Loop*********************************//

void loop() 
{
  
for (int i=0; i<=14 ;i++){
            //Serial.print(i);
tCAN message;
        message.id = 0x1D0; //formatted in HEX
        message.header.rtr = 0;
        message.header.length = 8; //formatted in DEC
          message.data[0] = 0x68; // 
          message.data[1] = 0x68;
          message.data[2] = 0x60 + i;  //
	        message.data[3] = 0xCB; // 
	        message.data[4] = 0x67;// 
        	message.data[5] = 0x26; //
        	message.data[6] = 0x00; //
        	message.data[7] = 0x00; //
mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
mcp2515_send_message(&message);
delay(100);
}
}
