#include "register.h"

void handle_timer(){
	printf("Timer interrupt occurred! TIMER_COUNT = %d\n", memory[TIMER_COUNT]);
	//handle the rest later
}

void handle_gpio(){
	//handle once i set up a gpio shitmissle
}

void (*interrupt_vector[2])(void) = {
    handle_timer,
    handle_gpio
};

void handle_interrupt(){
	unsigned int pending = memory[INTERRUPT_PENDING] & memory[INTERRUPT_ENABLE];
	if (pending && INTERRUPT_TIMER){
		handle_timer();
		memory[INTERRUPT_PENDING] &= ~INTERRUPT_TIMER;
	}
	if (pending && INTERRUPT_GPIO){
		handle_gpio();
		memory[INTERRUPT_PENDING] &= ~INTERRUPT_GPIO;
	}
}


