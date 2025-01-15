#include "display.h"

uint8_t display[DISPLAY_WIDTH * DISPLAY_HEIGHT];

void display_init(){
    SDL_Window *window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISPLAY_WIDTH * 10, DISPLAY_HEIGHT * 10, SDL_WINDOW_SHOWN);
    SDL_Surface *screen = NULL;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        screen = SDL_GetWindowSurface( window );
        SDL_FillRect( screen, NULL, SDL_MapRGB( screen->format, 0, 0, 0 ) );
        SDL_UpdateWindowSurface( window );
        SDL_Delay( 2000 );
    }
}

