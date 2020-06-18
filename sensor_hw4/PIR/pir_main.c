#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#define PIR_D 7

char pir_flag=0;
void PIR_interrupt()
{
	pir_flag=1;
}

int main(void)
{
	if(wiringPiSetup()==-1)
		return -1;
	pinMode(PIR_D,INPUT);
	
	wiringPiISR(PIR_D, INT_EDGE_RISING, PIR_interrupt);

	while(1)
	{
		if(pir_flag==1)
		{
			printf("PIR DETECTED!! %d\n",pir_flag);
			pir_flag=0;
		}
		else
		{
			printf("PIR NOT DETECTED!! %d\n",pir_flag);
		}
		usleep(500000);
	}
	return 0;
}
