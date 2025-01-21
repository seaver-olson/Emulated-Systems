#include "display.h"

static SDL_Window *window = NULL;
static SDL_Renderer *rdr = NULL;
static SDL_Texture *txr = NULL;


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

void display_letter(char letter){
	
}

void display_close(){
	SDL_Quit();
}

