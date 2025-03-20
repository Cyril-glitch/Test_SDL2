#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include "cc2d_graphics.h"



int main( int agrc , const char argv [])
{
	int true = 1;

	ccd2_init();

	ccd2_init_window("window test" ,2000,1000);


	while(true)
	{
		SDL_Event event;
		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				return 0 ;
			}
		}


	}

	ccd2_close();
}
