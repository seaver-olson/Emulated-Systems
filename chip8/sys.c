#include "mem.h"

int main(){
    if (init_mem() == 1){
        printf("Error: exited memory init early, quitting interpreter\n");
        return 1;
    }
    printf("Memory initialized\n");

    print_mem();
    write_block(0x200, 0x12);
    write_block(0x201, 0x34);
    write_block(0x202, 0x56);
    print_block(0x200, 3);
    return 0;
}
