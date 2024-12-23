#include "register.h"

uint32_t readRegister(uint32_t address){
	return *((uint8_t *)&memory[address]);
}

void writeRegister(uint32_t address, uint32_t value){
	*((uint8_t *)&memory[address]) = value;
}

int main(){
	writeRegister(TIMER_CTRL, 0x5);
	printf("%d\n", readRegister(TIMER_CTRL));
	return 0;
}
