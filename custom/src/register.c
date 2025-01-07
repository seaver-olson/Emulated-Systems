#include "register.h"

uint32_t memory[MEMORY_SIZE];

uint32_t readRegister(uint32_t address){
	return *((uint32_t *)&memory[address]);
}

void writeRegister(uint32_t address, uint32_t value){
	*((uint32_t *)&memory[address]) = value;
}

void printRegister(uint32_t address){
	printf("[REG] %04X : %d\n",address,*((uint32_t *)&memory[address]));
}

void printRegisters() {
    for (uint32_t i = 0x1000; i < 0x1010; i += 4) {
        printf("[REG] %04X : %d\n", i, memory[i]);
    }
}

void printMemory() {
    for (uint32_t i = 0; i < MEMORY_SIZE; i += 4) {
        printf("[MEM] %04X : %d\n", i, memory[i]);
    }
}

void exit(int status){
	printf("Halting system with status %d\n", status);
	printf("causing error to exit system");
	volatile int* invalid_pointer = (int*)0xDEADBEEF;
    	*invalid_pointer = 42;
}


