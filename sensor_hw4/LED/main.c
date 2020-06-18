#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <time.h>
#define LED_RED 1
#define LED_BLUE 7

int main(void) {
	if (wiringPiSetup() == -1)
		return 1;
   
	pinMode(LED_RED, OUTPUT);
	digitalWrite(LED_RED, 0);
	digitalWrite(LED_BLUE, 0);
	return 0;
}
