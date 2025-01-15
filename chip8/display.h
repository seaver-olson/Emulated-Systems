//64 by 32 display for the chip8
#include "mem.h"
#include <SDL2/SDL.h>

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32

extern uint8_t display[DISPLAY_WIDTH * DISPLAY_HEIGHT];

void display_clear();
void display_draw(uint8_t x, uint8_t y, uint8_t val);
void display_print();
void display_print_block(uint16_t addr, int size);
void display_write_block(uint16_t addr, uint8_t val);
