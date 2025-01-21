#include "timer.h"
#include "display.h"
#include "stack.h"


int main(){
    if (init_mem() == 1){
        printf("Error: exited memory init early, quitting interpreter\n");
        return 1;
    }
    printf("Memory initialized\n");
    timer_init();
    stack_init();
    display_init();
    return 0;
}

