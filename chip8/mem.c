#include "mem.h"

uint8_t memory[MEMORY_SIZE];

void init_mem() {
    //clear memory
    for (int i = 0; i < MEMORY_SIZE; i++) memory[i] = 0;
    //load fontset
    load_fontset();
    printf("Memory initialized\n");
}

int load_fontset(char *fontName){
    
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

int main(){
    init_mem();
    print_mem();
    write_block(0x200, 0x12);
    write_block(0x201, 0x34);
    write_block(0x202, 0x56);
    print_block(0x200, 3);
    return 0;
}