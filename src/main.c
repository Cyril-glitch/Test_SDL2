#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"

SDL_Texture* LoadTexture(SDL_Renderer *renderer,char* path)
{
	SDL_Texture *texture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path);

	if(loadedSurface == NULL )
	{
		printf("IMG %s can't be loaded error . %s\n",path,IMG_GetError());
		return NULL;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer,loadedSurface); 
		
		if(texture == NULL)
		{
		        printf("texture From %s can't be creat error . %s\n",path,IMG_GetError());
			return NULL;
		}
		else
		{
			SDL_FreeSurface(loadedSurface);
			loadedSurface = NULL;
		}
	}
	return texture;
}

SDL_Texture* QuickLoadTexture(SDL_Renderer *renderer,char* path)
{
	SDL_Texture *texture = NULL;
	texture = IMG_LoadTexture(renderer,path);


	if(texture == NULL)
	{
		printf("SDL can't creat texture From %s error : %s\n",path,IMG_GetError());
		return NULL;
	}

	return texture;
}


int main( int agrc , const char argv [])
{
	int true = 1;

//ici on initialise toutes les fonction de SDL en entrant le flag "EVERYTHING"


	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{

		printf("Impossible d'initialiserSDL \n");
		return -1;

	}

//ici on créer la fenetre : son nom ça taille ça position etc...

	SDL_Window *window = SDL_CreateWindow(
	"Test window",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	2000,
	1000,
	SDL_WINDOW_SHOWN
	);

	if(window == NULL)
	{
		printf("impossible de créer la fenetre %s\n",SDL_GetError());
		return-1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	
	if(renderer == NULL)
	{
		printf("impossible de créer le renderer  %s\n",SDL_GetError());
		return-1;
	}
	else
	{
		int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG ;

		if(!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("impossible d'initialiser SDL_Image : SDL_Image error : %s\n",SDL_GetError());
			return -1;
		}

	}
	


//ici on créer la game loop est on determine sa condition de sortie , ici la condition sera que le system renvoie l'evenement quit
//puis on nettoie et on affiche de renderer


SDL_Texture *texplanet = QuickLoadTexture(renderer,"img/planet.png");

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
