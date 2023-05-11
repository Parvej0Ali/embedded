#include <REGX51.H>
#include "delay.h"
sbit m1= P0^0;
sbit m2= P0^1;
sbit m3= P0^2;
sbit m4= P0^3;

void main()
{
	char i;
	while(1){
		for(i=0; i<4; i++){
			m1= 1;
			m2= m3= m4= 0;
			delay(300);
			
			m2= 1;
			m1= m3= m4= 0;
			delay(300);
			
			m3= 1;
			m2= m1= m4= 0;
			delay(300);
			
			m4= 1;
			m2= m3= m1= 0;
			delay(300);
		}
	}
}