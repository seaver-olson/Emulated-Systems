#include "mem.h"

uint8_t memory[MEMORY_SIZE];

void init_mem() {
    //initialize memory to 0
    for (int i = 0; i < MEMORY_SIZE; i++) memory[i] = 0;
    printf("Memory initialized\n");
}

void print_mem() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 16 == 0) printf("\n");
        printf("%02x ", memory[i]);
    }
    printf("\n");
}

int main(){
    init_mem();
    print_mem();
    return 0;
}