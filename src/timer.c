#include "register.h"


void timer_init(){
	registerWrite(TIMER_CTRL, 0x0);
	registerWrite(TIMER_COUNT, 0x0);
	registerWrite(TIMER_COMPARE, 0x0);
	registerWrite(TIMER_STATUS, 0x0);
}
