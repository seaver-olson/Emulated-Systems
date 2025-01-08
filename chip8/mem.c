#include "mem.h"

uint8_t memory[MEMORY_SIZE];

int init_mem() {
    //clear memory
    for (int i = 0; i < MEMORY_SIZE; i++) memory[i] = 0;
    //load fontset
    if (load_fontset("font/font1.txt") == 1){
	printf("Error: Could not open font file\n");
	return 1;
    }
    return 0;
}

int load_fontset(char *fontName){
   	FILE *font = fopen(fontName, "rb");
	if (font == NULL){
		return 1;
	}
	fread(memory + 0x50, 1, 80, font);
	fclose(font);
	return 0;
}

void print_mem() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 16 == 0) printf("\n");//print 16 bytes per line
        printf("%02x ", memory[i]);
    }
    printf("\n");
}

void write_block(uint16_t addr, uint8_t val) {
    memory[addr] = val;
}

void print_block(uint16_t addr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%02x ", memory[addr + i]);
    }
    printf("\n");
}

