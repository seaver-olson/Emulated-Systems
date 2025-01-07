#include "register.h"


void init_timer();
void tick();
void wait_cycles(unsigned int cycles);
void* timer_thread();
void wait_msec(unsigned int msec);
void wait_sec(unsigned int sec);
