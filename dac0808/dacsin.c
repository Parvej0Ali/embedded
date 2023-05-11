#include<reg51.h>
#define DAC P2

void main()
{
int i,j;
while(1)
{
for(i=0;i<255;i++)
{
 	DAC = i;
 	for(j=0;j<2;j++);
 }
for(i=255;i>0;i--)
{
 	DAC = i;
 	for(j=0;j<2;j++);
 }
}
}
