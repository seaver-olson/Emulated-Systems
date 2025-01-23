//64 by 32 display for the chip8
#include "mem.h"
#include <SDL2/SDL.h>

void display_init();
void display_draw();
void display_close();
void draw_sprite(uint8_t x, uint8_t y, uint8_t *sprite, uint8_t num_bytes);
