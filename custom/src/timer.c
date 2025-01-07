#include "timer.h"

void reset_compare(){
	memory[TIMER_STATUS] &= ~TIMER_COMPARE_STATUS;
}

void tick(){
	if (memory[TIMER_CTRL] & TIMER_CTRL_ENABLE){
		memory[TIMER_COUNT]++;
		if (memory[TIMER_COUNT] == memory[TIMER_COMPARE]){
			printf("Compare match! TIMER_COUNT = %u\n", memory[TIMER_COUNT]);
			memory[INTERRUPT_PENDING] |= INTERRUPT_TIMER;//send timer interrupt to interrupt system
            		memory[TIMER_STATUS] &= ~TIMER_COMPARE_STATUS;
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
void init_timer(){
	writeRegister(TIMER_CTRL, 0x0);
	writeRegister(TIMER_COUNT, 0x0);
	writeRegister(TIMER_COMPARE, 1000);
	writeRegister(TIMER_STATUS, 0x0);
        memory[TIMER_CTRL] |= TIMER_CTRL_ENABLE;
	pthread_t timer_tid;
	int result = pthread_create(&timer_tid, NULL, timer_thread, NULL);
    	if (result != 0) {
        	printf("pthread_create failed");
        	exit(1); // Exit if thread creation fails
    	}
    	pthread_detach(timer_tid);
	printf("Timer initialized\n");
}
