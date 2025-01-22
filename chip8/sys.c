#include "timer.h"
#include "display.h"
#include "stack.h"

int main(int argc, char ** argv){
    SDL_Event event;
    int dead = 0;

    if (argc < 2){
	printf("please select a rom first\n");
	return 1;
    }
    if (loadrom(argv[1]) != 0){
	printf("Error: Please check the spelling of your rom file\n");
	return 1;
    }
    if (init_mem() == 1){
        printf("Error: exited memory init early, quitting interpreter\n");
        return 1;
    }
    printf("Memory initialized\n");
    timer_init();
    stack_init();
    display_init();
    while (!dead){
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT: {
			dead = 1;
			break;
		} case SDL_KEYDOWN: {
			switch(event.key.keysym.sym){
				case SDLK_ESCAPE:dead = 1;break;
				
			}
		} 
	} 
	//execute command
	display_draw();
    }
    return 0;
}

