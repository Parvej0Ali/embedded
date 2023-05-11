//Dealy header file
void delay(int num)
{
int a;
for(a=0;a<=num;a++);
}
//LCD header file
void cmd_lcd (unsigned char dat)    // function to write command at lcd port 
{
	DATA=dat;
	RS=0;			  //clear RS (ie. RS=0) to write command
	E=1;			  // send  H-L pulse	at E pin		
	delay(100);
	E=0;
	delay(100);
}

void data_lcd (unsigned char dat)	// function to write data at lcd port 
{
	DATA=dat;
	RS=1;				// set RS=1 to write DATA
	E=1;			  // send  H-L pulse	at E pin		
	delay(100);
	E=0;
	delay(100);					  
}

void init_lcd()		        	 // function to initialize the LCD at power on time
{
	cmd_lcd(0x38);			 // 2x16 display select
	delay(50000);
	cmd_lcd(0x0c);			 // display on cursor off command
	delay(1000);
	cmd_lcd(0x06);			 // automatic cursor movement to right
	delay(1000);
	cmd_lcd(0x01);			 // lcd clear command 
	delay(5000);
}

void string_lcd(unsigned char *str)	   // function to display string to lcd
{
	 while(*str!='\0')		  		// '\0' is null char as last char of pointer is null
	 {
		 data_lcd(*str);
		 str++;
	 }
 }
//Main code
#include <reg51.h>
sbit RS = P3^3;
sbit E = P3^2;
sbit R0 = P0^3;
sbit R1 = P0^2;
sbit R2 = P0^1;
sbit R3 = P0^0;
sbit C0 = P0^6;
sbit C1 = P0^5;
sbit C2 = P0^4;
#define DATA P1
#include <delay.h>
#include <lcd.h>
void main(){
	init_lcd();
	while(1){
	R0 = R1 = R2 = R3 = 1;
	R0 = 0;
	if(C0 == 0){string_lcd("1");init_lcd();}
	R0 = 0;
	if(C1 == 0){string_lcd("2");init_lcd();}
	R0 = 0;
	if(C2 == 0){string_lcd("3");init_lcd();}
	
	R0 = R1 = R2 = R3 = 1;
	R1 = 0;
	if(C0 == 0){string_lcd("4");init_lcd();}
	R1 = 0;
	if(C1 == 0){string_lcd("5");init_lcd();}
	R1 = 0;
	if(C2 == 0){string_lcd("6");init_lcd();}
	
	R0 = R1 = R2 = R3 = 1;
	R2 = 0;
	if(C0 == 0){string_lcd("7");init_lcd();}
	R2 = 0;
	if(C1 == 0){string_lcd("8");init_lcd();}
	R2 = 0;
	if(C2 == 0){string_lcd("9");init_lcd();}
	
	R0 = R1 = R2 = R3 = 1;
	R3 = 0;
	if(C0 == 0){string_lcd("*");init_lcd();}
	R3 = 0;
	if(C1 == 0){string_lcd("0");init_lcd();}
	R3 = 0;
	if(C2 == 0){string_lcd("#");init_lcd();}
}
}