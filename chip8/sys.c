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
    if (init_mem() == 1){
        printf("Error: exited memory init early, quitting interpreter\n");
        return 1;
    }
    printf("Memory initialized\n");
    timer_init();
    stack_init();
    display_init();
    if (loadrom(argv[1]) != 0){
	printf("Error: Please check the spelling of your rom file\n");
	return 1;
    }
    while (!dead){
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT: {
			dead = 1;
			break;
		} case SDL_KEYDOWN: {
			switch(event.key.keysym.sym){
				case SDLK_ESCAPE:dead = 1;break;
				case SDLK_x:keyboard[0] = 1;break;
				case SDLK_1:keyboard[1] = 1;break;
				case SDLK_2:keyboard[2] = 1;break;
				case SDLK_3:keyboard[3] = 1;break;
				case SDLK_q:keyboard[4] = 1;break;
				case SDLK_w:keyboard[5] = 1;break;
				case SDLK_e:keyboard[6] = 1;break;
				case SDLK_a:keyboard[7] = 1;break;
				case SDLK_s:keyboard[8] = 1;break;
				case SDLK_d:keyboard[9] = 1;break;
				case SDLK_z:keyboard[0xA] = 1;break;
				case SDLK_c:keyboard[0xB] = 1;break;
				case SDLK_4:keyboard[0xC] = 1;break;
				case SDLK_r:keyboard[0xD] = 1;break;
				case SDLK_f:keyboard[0xE] = 1;break;
				case SDLK_v:keyboard[0xF] = 1;break;
			} break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym){
				case SDLK_x:keyboard[0] = 0;break;
				case SDLK_1:keyboard[1] = 0;break;
				case SDLK_2:keyboard[2] = 0;break;
				case SDLK_3:keyboard[3] = 0;break;
				case SDLK_q:keyboard[4] = 0;break;
				case SDLK_w:keyboard[5] = 0;break;
				case SDLK_e:keyboard[6] = 0;break;
				case SDLK_a:keyboard[7] = 0;break;
				case SDLK_s:keyboard[8] = 0;break;
				case SDLK_d:keyboard[9] = 0;break;
				case SDLK_z:keyboard[0xA] = 0;break;
				case SDLK_c:keyboard[0xB] = 0;break;
				case SDLK_4:keyboard[0xC] = 0;break;
				case SDLK_r:keyboard[0xD] = 0;break;
				case SDLK_f:keyboard[0xE] = 0;break;
				case SDLK_v:keyboard[0xF] = 0;break;
					}
					break;
		}
	}
	execute();
	display_draw();
	if(delay_timer > 0) --delay_timer;
  	if(sound_timer > 0)
  	{
  		if(sound_timer == 1)
     	 		printf("BEEP!\n");
    		--sound_timer;
 	}  
	SDL_Delay(16);
    }
    return 0;
}

