#include "timer.h"

int main(){
	timer_init();
	writeRegister(TIMER_STATUS,1);
	printRegister(TIMER_STATUS);
	wait_cycles(1000);
	printRegister(TIMER_COUNT);
	return 0;
}
