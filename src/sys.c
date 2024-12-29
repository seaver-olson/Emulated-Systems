#include "timer.h"

int main(){
	timer_init();
	

	writeRegister(TIMER_STATUS,1);
	printRegister(TIMER_STATUS);
	wait_sec(1);
	printRegister(TIMER_COUNT);
	wait_sec(10);
	printRegister(TIMER_COUNT);
	return 0;
}
