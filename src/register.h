#include <stdio.h>
#include <pthread.h>
#include "gpio.h"

uint32_t readRegister(uint32_t address);
void writeRegister(uint32_t address, uint32_t value);
void printRegister(uint32_t address);
void printRegisters();
void printMemory();
