#include "stack.h"

uint16_t stack[12];
uint16_t sp;

void stack_init(){
	for (int i = 0; i < 16; i++){
		stack[i] = 0;
	}
	sp = stack[0];
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

void pop(){
	if (sp == -1){
		printf("Underflow\n");
	} else {
		sp--;
	}
}

void show(){
	for (int i = sp; i >= 0; i--){
		printf("%d\n", stack[i]);
	}
}
