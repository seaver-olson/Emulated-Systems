#include "display.h"

static SDL_Window *window = NULL;
static SDL_Renderer *rdr = NULL;
static SDL_Texture *txr = NULL;

uint8_t display[DISPLAY_WIDTH*DISPLAY_HEIGHT];

void display_init(){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  	return;
    }
    SDL_Window *window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISPLAY_WIDTH * 10, DISPLAY_HEIGHT * 10, SDL_WINDOW_SHOWN);
    rdr = SDL_CreateRenderer(window, -1, 0);
    txr = SDL_CreateTexture(rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    if (window == NULL || rdr == NULL || txr == NULL){
	printf("[ERROR IN DISPLAY INIT]\n");
	return;
    }
    printf("Display initialized\n");
}

int get_next(){
	//gets next open spot for sprite

}

void display_draw(){
	if (drawflag){
	uint32_t screen[DISPLAY_WIDTH*DISPLAY_HEIGHT];
	memset(screen, 0, (DISPLAY_WIDTH*DISPLAY_HEIGHT)*4);//clear screen
	for (int x=0;x<DISPLAY_WIDTH;x++){
		for(int y=0; y<DISPLAY_HEIGHT;y++){
			if (display[(x) + ((y) * 64)] == 1){
				screen[(x) + ((y) * 64)] = UINT32_MAX;
			}
		}
	}
	SDL_UpdateTexture(txr, NULL, screen, 64 * sizeof(uint32_t));
	SDL_Rect position;
	position.x = 0;
	position.y = 0;
	SDL_RenderCopy(rdr, txr, NULL, &position);
	SDL_RenderPresent(rdr);
	}
	drawflag = 0;
}

void display_close(){
	SDL_Quit();
}

