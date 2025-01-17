#include "stack.h"

uint16_t stack[12];
uint16_t sp;
uint16_t pc;

void stack_init(){
	for (int i = 0; i < 12; i++){
		stack[i] = 0;
	}
	sp = -1;
	pc = 0x200;
	printf("Stack and Stack Pointer initialized\n");
}

void push(uint16_t val){
	if (sp == 11){
		printf("Overflow\n");
	} else {
		sp++;
		stack[sp] = val;
	}
}

uint16_t pop(){
	if (sp == -1){
		printf("Underflow\n");
	} else {
		printf("Popped: %d\n", stack[sp]);
		sp--;
		return stack[sp + 1];
	}
}

void show(){
	printf("Stack (From top to bottom):\n");
	for (int i = sp; i >= 0; i--){
		printf("%d\n", stack[i]);
	}
}
