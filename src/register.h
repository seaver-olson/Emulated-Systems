#include <stdint.h>
#include <stdio.h>
#include <pthread.h>

//define area
#define MEMORY_SIZE 4096

#define BASE_ADDRESS 0x1000
#define PROGRAM_COUNTER (BASE_ADDRESS)

#define TIMER_CTRL (BASE_ADDRESS + 0x04)
#define TIMER_COUNT (BASE_ADDRESS + 0x08)
#define TIMER_COMPARE (BASE_ADDRESS + 0x0C)
#define TIMER_STATUS (BASE_ADDRESS + 0x10)
#define TIMER_CTRL_ENABLE 0x1

#define R1 (BASE_ADDRESS + 0x1000)
#define R2 (BASE_ADDRESS + 0x1004)
#define R3 (BASE_ADDRESS + 0x1008)

extern uint32_t memory[MEMORY_SIZE];

uint32_t readRegister(uint32_t address);
void writeRegister(uint32_t address, uint32_t value);
void printRegister(uint32_t address);
void printRegisters();
