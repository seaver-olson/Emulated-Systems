#include "display.h"

uint8_t display[DISPLAY_WIDTH * DISPLAY_HEIGHT];

void display_clear(){
    for (int i = 0; i < DISPLAY_WIDTH * DISPLAY_HEIGHT; i++){
        display[i] = 0;
    }
}

void display_draw(uint8_t x, uint8_t y, uint8_t val){
    display[x + y * DISPLAY_WIDTH] = val;
}

void display_print(){
    for (int i = 0; i < DISPLAY_HEIGHT; i++){
        for (int j = 0; j < DISPLAY_WIDTH; j++){
            if (display[j + i * DISPLAY_WIDTH] == 0) printf(" ");
            else printf("X");
        }
        printf("\n");
    }
}

void display_print_block(uint16_t addr, int size){
    for (int i = 0; i < size; i++){
        printf("%02x ", display[addr + i]);
    }
    printf("\n");
}

void display_write_block(uint16_t addr, uint8_t val){
    display[addr] = val;
}
