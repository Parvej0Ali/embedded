#include <REGX51.H>
void delay(unsigned int time)
{
    unsigned i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1275; j++)
            ;
}

void main()
{
    unsigned char no_code[] = {0xbf, 0x86, 0xdb, 0xcf, 0xe6, 0xed, 0xfd, 0x87, 0xff, 0xef};
    while (1)
    {
        int a, b, c, d;
        for (d = 0; d < 10; d++)
        {
            for (c = 0; c < 10; c++)
            {
                for (b = 0; b < 10; b++)
                {
                    for (a = 0; a < 10; a++)
                    {
                        int i;
                        for (i = 0; i < 50; i++)
                        {
                            P0 = 0x01;
                            P2 = no_code[a];
                            delay(200);
                            P0 = 0x02;
                            P2 = no_code[b];
                            delay(200);
                            P0 = 0x04;
                            P2 = no_code[c];
                            delay(200);
                            P0 = 0x08;
                            P2 = no_code[d];
                            delay(200);
                        }
                    }
                }
            }
        }
    }
}