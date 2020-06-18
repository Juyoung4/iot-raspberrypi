#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#define TOUCH 2
#define LED 0

int main(void) {
	if (wiringPiSetup() == -1)
		return 1;
	pinMode(TOUCH, INPUT);
	pinMode(LED, OUTPUT);
	
	while(1) {
		if(digitalRead(TOUCH) == HIGH) {
			printf("TOUCH DETECTED!! \n");
			digitalWrite(LED, HIGH);
		} else {
			printf("TOUCH NOT DETECTED!! \n");
			digitalWrite(LED, LOW);
		}
		usleep(500000);
	}
	return 0;
}
