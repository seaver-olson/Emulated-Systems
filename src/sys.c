#include "timer.h"
#include "uart.h"

int main(){
	timer_init();
	writeRegister(TIMER_STATUS,1);
	uart_send("hello\n");
	uart_recv();
	wait_sec(1);
	wait_sec(10);
	return 0;
}
