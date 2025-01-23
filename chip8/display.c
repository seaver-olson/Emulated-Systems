#include "display.h"

static SDL_Window *window = NULL;
static SDL_Renderer *rdr = NULL;
static SDL_Texture *txr = NULL;

int drawflag = 0;

void display_init(){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  	return;
    }
    window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISPLAY_WIDTH * 10, DISPLAY_HEIGHT * 10, SDL_WINDOW_SHOWN);
    rdr = SDL_CreateRenderer(window, -1, 0);
    txr = SDL_CreateTexture(rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    if (window == NULL || rdr == NULL || txr == NULL){
	printf("[ERROR IN DISPLAY INIT]\n");
	return;
    }
    printf("Display initialized\n");
}


void display_draw(){
	if (drawflag){
		uint32_t screen[DISPLAY_WIDTH*DISPLAY_HEIGHT];
		memset(screen, 0, sizeof(screen));//clear screen
		for (int x=0;x<DISPLAY_WIDTH;x++){
			for(int y=0; y<DISPLAY_HEIGHT;y++){
				if (display[(x) + ((y) * DISPLAY_WIDTH)] == 1){
					screen[(x) + ((y) * DISPLAY_WIDTH)] = UINT32_MAX;
				}
			}
		}
		if (SDL_UpdateTexture(txr, NULL, screen, DISPLAY_WIDTH * sizeof(uint32_t)) < 0) {
			fprintf(stderr, "SDL_UpdateTexture Error: %s\n", SDL_GetError());
		}
		SDL_Rect position = {0,0};
		if (SDL_RenderCopy(rdr, txr, NULL, &position)!=0){
			fprintf(stderr, "SDL_RenderCopy Error: %s\n", SDL_GetError());
		}
		SDL_RenderPresent(rdr);
	}
	drawflag = 0;
}

void display_close(){
	SDL_Quit();
}

