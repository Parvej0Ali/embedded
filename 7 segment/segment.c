#include <REGX51.H>
void delay(unsigned int time)
{
    unsigned i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1275; j++);
}

void main()
{
    unsigned char arr[] = {0xbf, 0x86, 0xdb, 0xcf, 0xe6, 0xed, 0xfd, 0x87, 0xff, 0xef};
    while (1)
    {
			int i;
			for(i = 0; i < 10; i++){
				P0 = 0x01;
				P1 = arr[i];
				delay(2000);
			}
    }
}