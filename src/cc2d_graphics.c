#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"

#include "cc2d_graphics.h"

int ccd2_init()
{

//ici on initialise toutes les fonction de SDL en entrant le flag "EVERYTHING"

	printf("initialisation la librairie SDL...\n");

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{

		printf("Impossible d'initialiserSDL \n");
		return -1;
	}
	else
	{
		printf("SDL initialisée avec succés !\n");
		return 0;
	}
}
int ccd2_init_window(char* titre ,int w ,int h)
{
//ici on créer la fenetre : son nom ça taille ça position etc...

	SDL_Window *window = SDL_CreateWindow(
	"Test window",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	w,
	h,
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
}

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
