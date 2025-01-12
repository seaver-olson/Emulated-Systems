#include "timer.h"

void *timer_pthread(){
    while (1){
        usleep(16667);
        if (delay_timer > 0) delay_timer--;
        if (sound_timer > 0) sound_timer--;
    }
}

void timer_init(){
    pthread_t timer_thread;
    pthread_create(&timer_thread, NULL, timer_pthread, NULL);
    printf("Timers initialized\n");
}