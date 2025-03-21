#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include "cc2d_graphics.h"



int main( int agrc , const char argv [])
{
	int true = 1;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;


	cc2d_init();


	cc2d_init_window("window test" ,2000,1000,renderer,window);


	while(true)
	{
		
		if(cc2d_beginDraw(renderer) == 0 )
		{
			break;
		}
		
		cc2d_enddraw(renderer);


	}

	cc2d_close(window,renderer);
}
