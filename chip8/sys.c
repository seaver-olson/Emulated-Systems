#include "timer.h"
#include "display.h"
#include "stack.h"

void commandClaim(char *cmd);

int main(){
    if (init_mem() == 1){
        printf("Error: exited memory init early, quitting interpreter\n");
        return 1;
    }
    printf("Memory initialized\n");
    timer_init();
    stack_init();
    //display_init();
    while (1){
	char *cmd;
	printf(">>>");
	scanf("%s", cmd);
        printf("%s\n",cmd);
	commandClaim(cmd);
        wait_sec(2);
	printf("Timer delay: %d\n", delay_timer);
    }
    return 0;
}


void commandClaim(char *cmd){
	if (cmd == "help"){
		printf("Help List:\n");
		printf("	0 - display help list\n");
	}
}
