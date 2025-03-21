#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"


#ifndef CCD2_GRAPHICS_H 
#define CCD2_GRAPHICS_H


#endif

int cc2d_init();

void cc2d_close();

int cc2d_beginDraw(SDL_Renderer* renderer);

void cc2d_enddraw(SDL_Renderer* renderer);

int cc2d_init_window(char* titre ,int w ,int h,SDL_Renderer* renderer,SDL_Window* window);

SDL_Texture* cc2d_newImage(SDL_Renderer *renderer,const char* path,int texW,int texH);

int cc2d_drawImage(SDL_Texture* texture ,SDL_Renderer* renderer,int texX, int texY);

SDL_Texture* LoadTexture(SDL_Renderer *renderer,char* path);

SDL_Texture* QuickLoadTexture(SDL_Renderer *renderer,char* path);
