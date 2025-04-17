#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "cc2d_graphics.h"
#include "cc2d_font.h"
#include "cc2d_keyboard.h"


int main( int agrc , const char argv [])
{
	//initialisation SDL + Fenetre
	int true = 1;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;


	cc2d_init();
	cc2d_init_window("window test" ,2000,1000,&renderer,&window);
	
	//intialisation graphics
	SDL_Texture* texplanet = cc2d_loadImage(renderer,"../img/planet.png");
	int xp = 0;
	int yp = 0;

	//initialisation font et textes
	TTF_Font* font = cc2d_loadFont("../font/PixelMaster.ttf",100);
	SDL_Texture* titre = cc2d_textureTexte("Hello World !",renderer,font,100,100,255,255,255,255);
	


	//depart de la gameloop
	while(true)
	{
		
		SDL_SetRenderDrawColor(renderer,0,0,10,255);        //initialise le render en bleu
		if(cc2d_beginDraw(renderer) == 0 )                  //efface le renderer
		{
			break;
		}
		
		//chargement du contenue

		SDL_SetRenderDrawColor(renderer,255,0,255,255);      //dessine la ligne
		SDL_RenderDrawLine(renderer,0,0,2000,1000);

		cc2d_Draw(texplanet,renderer,xp,yp,150,150,255);     //affiche la planet 
		cc2d_Draw(titre,renderer,300,500,200,100,255);


		if(cc2d_downKey(SDL_SCANCODE_D))
		{
			xp++;
		}
		if(cc2d_downKey(SDL_SCANCODE_A))
		{
			xp--;
		}
		if(cc2d_downKey(SDL_SCANCODE_S))
		{
			yp++;
		}
		if(cc2d_downKey(SDL_SCANCODE_W))
		{
			yp--;
		}

		cc2d_enddraw(renderer);    //affiche le resultat


	}

	cc2d_close(window,renderer);       //libere la memoire
}
