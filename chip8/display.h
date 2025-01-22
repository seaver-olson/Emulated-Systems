//64 by 32 display for the chip8
#include "mem.h"
#include <SDL2/SDL.h>

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32

extern uint8_t display[DISPLAY_WIDTH * DISPLAY_HEIGHT];

void display_init();
void display_draw();
void display_close();
