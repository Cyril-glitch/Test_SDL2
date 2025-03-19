#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include "cc2d_graphics.h"



int main( int agrc , const char argv [])
{
	int true = 1;

	ccd2_init();


	


//ici on créer la game loop est on determine sa condition de sortie , ici la condition sera que le system renvoie l'evenement quit
//puis on nettoie et on affiche de renderer


SDL_Texture *texplanet = QuickLoadTexture(renderer,"../img/planet.png");

int texplanetW , texplanetH;
int planetx = 10 , planety = 10  ;

SDL_QueryTexture (texplanet ,NULL,NULL,&texplanetW,&texplanetH);
SDL_Rect planetDstRect = {planetx,planety,texplanetW,texplanetH};


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

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer , texplanet ,NULL ,&planetDstRect);
	SDL_RenderPresent(renderer);

	}

//etape finale on libere l'espace memoire du renderer et on quitte proprement la fenetre
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texplanet);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();									       

}
