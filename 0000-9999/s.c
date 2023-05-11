#include<regx51.h>

void delay(unsigned int time){
	int i, j;
	for(i = 0; i < 1275; i++){
		for(j = 0; j < time; j++){
		}
	}
}

void main(){
	unsigned char arr[] = {0xbf, 0x86, 0xdb, 0xcf, 0xe6, 0xed, 0xfd, 0x87, 0xff, 0xef};
	while(1){
		int a, b, c, d;
		for(d = 0; d < 10; d++){
			for(c = 0; c < 10; c++){
				for(b = 0; b < 10; b++){
					for(a = 0; a < 10; a++){
						P0 = 0x01;
						P1 = arr[a];
						delay(200);
						P0 = 0x02;
						P1 = arr[b];
						delay(200);
						P0 = 0x04;
						P1 = arr[c];
						delay(200);
						P0 = 0x08;
						P1 = arr[d];
						delay(2000);
					}
				}
			}
		}
	}
}