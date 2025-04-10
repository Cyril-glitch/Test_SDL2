#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

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


int cc2d_init_window(char* titre ,int w ,int h,SDL_Renderer** renderer,SDL_Window** window)
{

//window = l'adresse du pointeur 
//*window = la valeur du premier pointeur SDL_window *window
//**window = la valeur pointé par le premier pointeur (les donnèes de la struct)

	*window = SDL_CreateWindow(
			"Test window",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			w,
			h,
			SDL_WINDOW_SHOWN
			);

	if(*window == NULL)
	{
		printf("impossible de créer la fenetre %s\n",SDL_GetError());
		return-1;
	}

	 *renderer = SDL_CreateRenderer(*window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	if(*renderer == NULL)
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
	
	if(TTF_Init() == -1)
	{
		printf("impossible d'intialiser la TTF : TTF error : %s\n",TTF_GetError());
		return -1;

	}
	else
	{
		printf("TTF initialisée avec succés !\n");
	}

	SDL_SetRenderDrawBlendMode(*renderer,SDL_BLENDMODE_BLEND);
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

SDL_Texture* cc2d_loadImage(SDL_Renderer *renderer,const char* path)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer,path);


	if(texture == NULL)
	{
		printf("SDL can't creat texture From %s error : %s\n",path,IMG_GetError());



	}

	return texture;

}
//on a besoin d'une fonction qui defini le rectangle de destinantion puis l'affiche

void cc2d_Draw(SDL_Texture* texture ,SDL_Renderer* renderer,int x, int y ,int w,int h,int a )
{

	SDL_Rect rectDst = {x,y,w,h};
	SDL_SetTextureAlphaMod(texture,a);
	SDL_RenderCopy(renderer,texture,NULL,&rectDst);
}

void cc2d_drawRect(SDL_Renderer* renderer,const char* mode , int x ,int y ,int w , int h)
{
	SDL_Rect rect = {x,y,w,h}; 

	if(strcmp(mode,"line") == 0)
	{
		SDL_RenderDrawRects(renderer,&rect,1);
	}
	else if(strcmp(mode,"fill") == 0)
	{
		SDL_RenderFillRects(renderer,&rect,1);
	}
}

TTF_Font* cc2d_loadFont(const char* path ,int ftsize)
{
	TTF_Font* font = TTF_OpenFont(path,ftsize);

	if(font == NULL)
	{
		printf("TTF can't creat font From %s error : %s\n",path,TTF_GetError());
		return NULL;

	}

	return font;
}
	
SDL_Texture* cc2d_textureTexte(char* texte ,SDL_Renderer* renderer,TTF_Font* font,int x,int y,int r,int g,int b,int a)
{

	SDL_Color color = {r,g,b,a};
	SDL_Texture* texture = NULL;


	SDL_Surface* surface = TTF_RenderUTF8_Solid(font,texte,color);
	
	if(surface == NULL)
	{
		printf(" can't load surface error: %s\n",SDL_GetError());
		return NULL;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer,surface);

		if(texture == NULL)
		{
			printf(" can't create texture from surface error: %s\n",SDL_GetError());
			return NULL;
		}
	
	}
	SDL_FreeSurface(surface);

	return texture;
}

	

	














