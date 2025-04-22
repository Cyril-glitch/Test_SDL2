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
	TTF_Font* font = cc2d_loadFont("../font/PixelMaster.ttf",50);
	SDL_Texture* titre = cc2d_textureTexte("Hello World !",renderer,font,100,100,255,255,255,255);
	

	//initialisatioon des valeurs de temps
	Uint32 frameStart = 0;
	float deltaTime = 0 ;
	float elapsedTime = 0 ;

	//initialisation des valeurs precises
	Uint64 precise_fst = 0;
	double precise_dt = 0;
	double precise_elapse = 0 ;

	//depart de la gameloop
	while(true)
	{

		 //recupération du delta Time
		 Uint32 now = SDL_GetTicks();
		 elapsedTime  = now / 1000;		
		 deltaTime = (now- frameStart) / 1000.0;
		 frameStart = now ;

		 //recuperation des valeurs precises
		 Uint64 P_now = SDL_GetPerformanceCounter();
		 precise_elapse = (double)P_now / SDL_GetPerformanceFrequency();
		 precise_dt = (double)(P_now - precise_fst) / SDL_GetPerformanceFrequency();
		 precise_fst = P_now ;

		
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
		
		//affichage timer 
		char elpdTime[100];
		sprintf(elpdTime,"TIME : %.6f",elapsedTime); 
	        SDL_Texture* texElapsedTime = cc2d_textureTexte(elpdTime,renderer,font,300,100,255,255,255,255);
		cc2d_Draw(texElapsedTime,renderer,1700,0,150,100,255);

		//affichage delta time
		char timeDt[100];
		sprintf(timeDt,"DELTA : %.6f",deltaTime); 
	        SDL_Texture* tex_DTime = cc2d_textureTexte(timeDt,renderer,font,300,100,255,255,255,255);
		cc2d_Draw(tex_DTime,renderer,1700,100,150,100,255);
		
                //affichage des fps
		char fps[100];
		sprintf(fps,"FPS : %.6f", 1 / deltaTime ); 
	        SDL_Texture* tex_fps = cc2d_textureTexte(fps,renderer,font,300,100,255,255,255,255);
		cc2d_Draw(tex_fps,renderer,1700,200,150,100,255);
                
		//affichage precis du timer 
		char P_elapse[100];
		sprintf(P_elapse,"TIME : %.6f",precise_elapse); 
	        SDL_Texture* P_tex_ElapsedTime = cc2d_textureTexte(P_elapse,renderer,font,300,100,255,255,255,255);
		cc2d_Draw(P_tex_ElapsedTime,renderer,1700,300,150,100,255);


                //affichage precis du  delta time
		char P_Dt[100];
		sprintf(P_Dt,"DELTA : %.6f",precise_dt); 
	        SDL_Texture* tex_P_Dt = cc2d_textureTexte(P_Dt,renderer,font,300,100,255,255,255,255);
		cc2d_Draw(tex_P_Dt,renderer,1700,400,150,100,255);
		
                //affichage precis des fps
		char P_fps[100];
		sprintf(P_fps,"FPS : %.6f", 1 / precise_dt ); 
	        SDL_Texture* tex_P_fps = cc2d_textureTexte(P_fps,renderer,font,300,100,255,255,255,255);
		cc2d_Draw(tex_P_fps,renderer,1700,500,150,100,255);

                
	






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
		/*cc2d_fpsLimiter(frameStart , 60);*/
		cc2d_Precise_FpsLimiter(precise_fst , 60);


	}

	cc2d_close(window,renderer);       //libere la memoire
}
