#include "register.h"

uint8_t memory[MEMORY_SIZE];

uint32_t readRegister(uint32_t address){
	return *((uint8_t *)&memory[address]);
}

void writeRegister(uint32_t address, uint32_t value){
	*((uint8_t *)&memory[address]) = value;
}

void printRegister(uint32_t address){
	printf("[REG] %04X : %d\n",address,*((uint8_t *)&memory[address]));
}

void printRegisters() {
    for (uint32_t i = 0x1000; i < 0x1010; i += 4) {
        printf("[REG] %04X : %d\n", i, memory[i]);
    }
}
