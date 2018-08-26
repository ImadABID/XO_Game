#include "xo.h"



int main(int argc,char* argv[]){
	
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	
	SDL_Surface *icon;
	icon=IMG_Load("IMG/X.bmp");
	SDL_WM_SetIcon(icon,NULL);
	SDL_WM_SetCaption("xo","xo_icon");
	
	Mix_Music *music;
	Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
	music=Mix_LoadMUS("The_Mummy.mp3");
	Mix_PlayMusic(music,-1);
	
	caseEtat=malloc(9*sizeof(VXO));
	if(caseEtat==NULL){
		fprintf(stderr,"Probleme d'allocation mémoire!\n"); return -1;
	}
	InitialisationDeCaseEtat();
	
	window=SDL_SetVideoMode(1000,500,32,SDL_HWSURFACE);
	imgcases=IMG_Load("IMG/cases.bmp");
	
	if(!commandegestion()){
		Mix_FreeMusic(music);
		SDL_FreeSurface(imgcases);
		SDL_FreeSurface(window);
		TTF_Quit();
		SDL_Quit();
	}
	return 0;
}
