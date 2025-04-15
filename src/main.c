#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "cc2d_graphics.h"
#include "cc2d_font.h"


int main( int agrc , const char argv [])
{
	int true = 1;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

//initilisation de la sdl , de la fenetre puis du rendu et enfin de la texture

	cc2d_init();
	cc2d_init_window("window test" ,2000,1000,&renderer,&window);
	
	SDL_Texture* texplanet = cc2d_loadImage(renderer,"../img/planet.png");

	TTF_Font* font = cc2d_loadFont("../font/PixelMaster.ttf",100);
	SDL_Texture* titre = cc2d_textureTexte("Hello World !",renderer,font,100,100,255,255,255,255);


	while(true)
	{
		
		SDL_SetRenderDrawColor(renderer,0,0,10,255);//initialise le render en bleu
		if(cc2d_beginDraw(renderer) == 0 )//efface le renderer
		{
			break;
		}
		
		//chargement du contenue

		SDL_SetRenderDrawColor(renderer,255,0,255,255); 
		SDL_RenderDrawLine(renderer,0,0,2000,1000);

		SDL_SetRenderDrawColor(renderer,0,255,255,255); 
		cc2d_drawRect(renderer,"line",1000,500,100,100);
		cc2d_drawRect(renderer,"fill",1100,600,100,100);	
		SDL_SetRenderDrawColor(renderer,0,255,255,122); 
		cc2d_drawRect(renderer,"fill",1100,650,100,100);
		
		cc2d_Draw(texplanet,renderer,10,10,150,150,255);
		cc2d_Draw(titre,renderer,300,500,200,100,255);

		

		cc2d_enddraw(renderer);//affiche le resultat


	}

	cc2d_close(window,renderer);//libere la memoire
}
