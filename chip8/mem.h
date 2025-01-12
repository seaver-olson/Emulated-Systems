#include <stdint.h>
#include <stdio.h>
#include<unistd.h>

#define MEMORY_SIZE 4096
#define FONT_WIDTH 5
#define FONT_HEIGHT 16

extern uint8_t memory[MEMORY_SIZE];//4KB of memory

uint16_t index_reg;//index register
uint16_t pc;//program counter
uint16_t stack[12];//12 levels of stack for nested calls
uint8_t delay_timer;//deincremented at 60Hz(60 times per second)
uint8_t sound_timer;//same as delay but gives a beep when not 0
uint16_t sp;//stack pointer

int init_mem();
int load_rom(const char* filename);
int load_fontset(char *fontName);
void display_font();
void print_mem();
void write_block(uint16_t addr, uint8_t val);
uint8_t read_block(uint16_t addr, uint8_t* buffer, int size);
void print_block(uint16_t addr, int size);
