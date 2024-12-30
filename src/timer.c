#include "timer.h"

void tick(){
	if (memory[TIMER_CTRL] & TIMER_CTRL_ENABLE){
		memory[TIMER_COUNT]++;
		//add a compare check later
		if (memory[TIMER_COUNT] == memory[TIMER_COMPARE]){
			memory[INTERRUPT_PENDING] |= INTERRUPT_TIMER;
		}
	} else {
		printf("ERROR Timer not enabled\n");
	}
}

void* timer_thread(){
	while (1) tick();
}

void wait_cycles(unsigned int cycles){
	int end = memory[TIMER_COUNT] + cycles;
	while (end>memory[TIMER_COUNT]){
		asm("nop");
	}
}

void wait_msec(unsigned int msec){
	wait_cycles(msec*500000);
}

void wait_sec(unsigned int sec){
	wait_msec(sec*1000);
}
void timer_init(){
	writeRegister(TIMER_CTRL, 0x0);
	writeRegister(TIMER_COUNT, 0x0);
	writeRegister(TIMER_COMPARE, 0x0);
	writeRegister(TIMER_STATUS, 0x0);
        memory[TIMER_CTRL] |= TIMER_CTRL_ENABLE;
	pthread_t timer_tid;
    	pthread_create(&timer_tid, NULL, timer_thread, NULL);
	printf("Timer initialized\n");
	
}
