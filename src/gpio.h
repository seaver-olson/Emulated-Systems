#include <stdint.h>

#define MEMORY_SIZE 4096

#define BASE_ADDRESS 0x1000
#define PROGRAM_COUNTER (BASE_ADDRESS)

#define TIMER_CTRL (BASE_ADDRESS + 0x04)
#define TIMER_COUNT (BASE_ADDRESS + 0x08)
#define TIMER_COMPARE (BASE_ADDRESS + 0x0C)
#define TIMER_STATUS (BASE_ADDRESS + 0x10)
#define TIMER_CTRL_ENABLE 0x1
#define TIMER_COMPARE_STATUS 0x1 //shitty ahh practice but I got confused when i used the timer_ctrl_enable flag for the comapre as well

#define R1 (BASE_ADDRESS + 0x1000)
#define R2 (BASE_ADDRESS + 0x1004)
#define R3 (BASE_ADDRESS + 0x1008)
#define R4 (BASE_ADDRESS + 0x100C)
#define R5 (BASE_ADDRESS + 0x1010)
#define R6 (BASE_ADDRESS + 0x1014)
#define R7 (BASE_ADDRESS + 0x1018)
#define R8 (BASE_ADDRESS + 0x101C)
#define R9 (BASE_ADDRESS + 0x1020)
#define R10 (BASE_ADDRESS + 0x1024)
#define R11 (BASE_ADDRESS + 0x1028)
#define R12 (BASE_ADDRESS + 0x102C)
#define R13 (BASE_ADDRESS + 0x1030)
#define R14 (BASE_ADDRESS + 0x1034)
#define R15 (BASE_ADDRESS + 0x1038)
#define R16 (BASE_ADDRESS + 0x103C)

#define SP (BASE_ADDRESS + 0x1040)//stack pointer
#define LR (BASE_ADDRESS + 0x1044)//link register
#define PC (BASE_ADDRESS + 0x1048)//program counter
#define CPSR (BASE_ADDRESS + 0x104C)//current program status register

#define GPIO_BASE (BASE_ADDRESS + 0x2000)
#define GPIO_DATA (GPIO_BASE + 0x00)
#define GPIO_DIR (GPIO_BASE + 0x04)
#define GPIO_INT (GPIO_BASE + 0x08)
#define GPIO_INTEN (GPIO_BASE + 0x0C)
#define GPIO_INTMASK (GPIO_BASE + 0x10)
#define GPIO_INTTYPE (GPIO_BASE + 0x14)
#define GPIO_INTPOL (GPIO_BASE + 0x18)
#define GPIO_INTSTATUS (GPIO_BASE + 0x1C)

#define UART_BASE (BASE_ADDRESS + 0x3000)
#define UART_DATA (UART_BASE + 0x00)
#define UART_FLAG (UART_BASE + 0x04)
#define UART_INTEN (UART_BASE + 0x08)
#define UART_BAUD (UART_BASE + 0x0C)

#define INTERRUPT_BASE (BASE_ADDRESS + 0x4000)
#define INTERRUPT_PENDING (INTERRUPT_BASE + 0x00)
#define INTERRUPT_ENABLE (INTERRUPT_BASE + 0x04)
#define INTERRUPT_CLEAR (INTERRUPT_BASE + 0x08)

#define INTERRUPT_TIMER 0x1
#define INTERRUPT_GPIO 0x2

extern uint32_t memory[MEMORY_SIZE];
