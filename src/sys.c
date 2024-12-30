#include "timer.h"
#include "uart.h"

int main(){
	timer_init();
	writeRegister(TIMER_STATUS,1);
	while(1){
		printf("main loop reached\n");
		wait_sec(1);
	}
	return 0;
}
