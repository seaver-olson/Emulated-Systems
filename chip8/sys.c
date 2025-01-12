#include "timer.h"

int main(){
    if (init_mem() == 1){
        printf("Error: exited memory init early, quitting interpreter\n");
        return 1;
    }
    printf("Memory initialized\n");
    timer_init();
    while (1){
        //main loop
    }
    return 0;
}
