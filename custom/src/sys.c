#include "timer.h"
#include "interrupts.h"
#include "uart.h"

int main(){
	init_timer();
	init_interrupts();
	writeRegister(TIMER_STATUS,1);
	printRegister(TIMER_COUNT);
	while(1){
		printf("main loop reached\n");
	}
	return 0;
}
