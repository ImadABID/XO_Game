#ifndef __GeneralesVariables_h__
#define __GeneralesVariables_h__

#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

typedef enum{
	false,true
}bool;

typedef enum{
	v,x,o
}VXO;


VXO *caseEtat;
void InitialisationDeCaseEtat();

SDL_Surface *window;
SDL_Surface *imgcases;


bool commandegestion();

bool MouseIn1(SDL_Event event,VXO WeDraw);
bool MouseIn2(SDL_Event event,VXO WeDraw);
bool MouseIn3(SDL_Event event,VXO WeDraw);
bool MouseIn4(SDL_Event event,VXO WeDraw);
bool MouseIn5(SDL_Event event,VXO WeDraw);
bool MouseIn6(SDL_Event event,VXO WeDraw);
bool MouseIn7(SDL_Event event,VXO WeDraw);
bool MouseIn8(SDL_Event event,VXO WeDraw);
bool MouseIn9(SDL_Event event,VXO WeDraw);

SDL_Rect XorOPosition(SDL_Event event,VXO WeDraw, bool *isitcorrect);
bool drawX(SDL_Event event);
bool drawO(SDL_Event event);
bool DrawXorO(SDL_Event event);
bool DontWait;

bool result();
void printResult(VXO s);

#endif
