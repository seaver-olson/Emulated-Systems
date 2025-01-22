#include <stdint.h>
#include <stdio.h>
#include<unistd.h>

#define MEMORY_SIZE 4096
#define FONT_WIDTH 5
#define FONT_HEIGHT 16

extern uint8_t memory[MEMORY_SIZE];//4KB of memory

extern uint16_t index_reg;//index register
extern uint16_t pc;//program counter
extern uint16_t stack[12];//12 levels of stack for nested calls
extern uint8_t delay_timer;//deincremented at 60Hz(60 times per second)
extern uint8_t sound_timer;//same as delay but gives a beep when not 0
extern uint16_t sp;//stack pointer
extern uint16_t opcode;

int init_mem();
int loadrom(char *rom);
int load_fontset(char *fontName);
void display_font();
void print_mem();
void write_block(uint16_t addr, uint8_t val);
uint8_t read_block(uint16_t addr, uint8_t* buffer, int size);
void print_block(uint16_t addr, int size);
void execute();
