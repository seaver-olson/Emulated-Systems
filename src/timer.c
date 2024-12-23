#include "timer.h"

void timer_init(){
	writeRegister(TIMER_CTRL, 0x0);
	writeRegister(TIMER_COUNT, 0x0);
	writeRegister(TIMER_COMPARE, 0x0);
	writeRegister(TIMER_STATUS, 0x0);
}
