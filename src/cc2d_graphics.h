#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"


#ifndef CCD2_GRAPHICS_H 
#define CCD2_GRAPHICS_H


#endif

int ccd2_init();


void ccd2_close();

int ccd2_init_window(char* titre, int w , int h);

SDL_Texture* LoadTexture(SDL_Renderer *renderer,char* path);

SDL_Texture* QuickLoadTexture(SDL_Renderer *renderer,char* path);
