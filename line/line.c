#define F_CPU 12000000UL  // define MCU Clock speed
#include <avr/io.h>       // include avr header file
#include <util/delay.h>   // include delay header file

// use _delay_ms(ms) for delaying

int main(void)  		  // main function
{
DDRA=0b00000000;          // declare PortA as a input port connected to the sensors
DDRC=0b11111111;          // declare PortC as a output port connected to the motors

int ls=0, rs=0;
int flag = 1;
int speed = 1;

 
while(1) 				  // infinite loop
	{
	ls=PINA&0b00010000;    // mask PA4 bit of Port A
	rs=PINA&0b00100000;   // mask PA5 bit of Port 

	 
	if((ls==0b00000000) && (rs==0b00000000))      // if both sensors "off"
		{
		PORTC=0b00000000;  // stop	

		}

    if((ls==0b00010000) && (rs==0b00100000))      // if both sensors "on"
		{
        	if(flag >= speed){
			flag = 0;
			PORTC=0b00001001;  // move straight
		}
		else
			PORTC=0b00000000;  // stop	

		flag++;

		}
			
	if((ls==0b00000000) && (rs==0b00100000)) 	 // if left sensor off but right sensor on
        {
		PORTC=0b00010001;  // turn left
        }

	if((ls==0b00010000)&&(rs==0b00000000))  	 	 // if left sensor on but right sensor off
        {
		PORTC=0b00011000;  // turn right
		}


	}      				   // while closed
	
}         				   // main closed-
