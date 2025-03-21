#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"

#include "cc2d_graphics.h"

int cc2d_init()
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

int cc2d_beginDraw(SDL_Renderer* renderer)
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

	return 1;
}

void cc2d_enddraw(SDL_Renderer* renderer)
{
	SDL_RenderPresent(renderer);
}

void cc2d_close(SDL_Renderer* renderer,SDL_Window* window)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	printf("fermeture du programme...\n");
}


int cc2d_init_window(char* titre ,int w ,int h,SDL_Renderer* renderer,SDL_Window* window)
{
	//ici on créer la fenetre : son nom ça taille ça position etc...

	 window = SDL_CreateWindow(
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

	 renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


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

SDL_Texture* quickLoadTexture(SDL_Renderer *renderer,char* path)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer,path);


	if(texture == NULL)
	{
		printf("SDL can't creat texture From %s error : %s\n",path,IMG_GetError());
		return NULL;
	}

	return texture;
}

SDL_Texture* cc2d_newImage(SDL_Renderer *renderer,const char* path,int texW,int texH)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer,path);


	if(texture == NULL)
	{
		printf("SDL can't creat texture From %s error : %s\n",path,IMG_GetError());
		return NULL;
	}
	SDL_QueryTexture(texture,NULL,NULL,&texW,&texH);

	return texture;

}

int cc2d_drawImage(SDL_Texture* tex,SDL_Renderer* renderer,int texX, SDL_texture* tex->w , SDL_texture* tex->y)
{
	SDL_Rect* textDstRect(texX,TexY)
	SDL_RenderCopy(texture,renderer,NULL,texDstRect)

}













