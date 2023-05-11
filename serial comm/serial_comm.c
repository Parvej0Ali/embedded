#include<reg51.h>
#include"delay.h"
#include"serial.h"

void main()
{
  init_serial(9600);
  delay(10000);
  string_serial("SERIAL COMMUNICATION TEST WITH 8051\n\r");
  while(1)
  {
     trans_serial(rec_serial());
   }
}
