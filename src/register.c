#include "register.h"

uint32_t memory[4096];

uint32_t readRegister(uint32_t address){
	if (address < REG_COUNT){
		return registers[address];
	} else {
		printf("Error: Invalid Register\n");
		return 0;
	}
}

void writeRegister(uint32_t address, uint32_t value){
	if (address < REG_COUNT){
		registers[address] = value;
	} else {
		printf("Error: Invalid Register\n");
	}
}

int main(){
	writeRegister(1000, 50);
	printf("%s", (char *)readRegister(1000));
	return 0;
}
