#include "xo.h"



bool commandegestion(){
	
	
	static bool FirstTime=true;
	static	SDL_Rect imgcasesP;
	imgcasesP.x=0;
	imgcasesP.y=0;
	
	static SDL_Event event;
	if(FirstTime || DontWait){
		SDL_BlitSurface(imgcases,NULL,window,&imgcasesP);
		DontWait=false;	
	}
	FirstTime=false;
	
	printResult(v);
	
	while(1){

		if(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT) return false;
			if(event.type==SDL_MOUSEBUTTONDOWN){
				if(event.button.button==SDL_BUTTON_LEFT){
					if(DrawXorO(event)){
						if(result()){
							printResult(v);
							SDL_Flip(window);
							if(DontWait){
								InitialisationDeCaseEtat();
								SDL_Delay(3000);
							}

							if(!commandegestion()) return false;
						}
					}
				}
			}
		}

		SDL_Flip(window);
		SDL_Delay(200);
	}
}
/*----------------------------------------------------------------------*/
void InitialisationDeCaseEtat(){
	int i;
	for(i=0;i<9;i++){
		caseEtat[i]=v;
	}
}
/*----------------------------------------------------------------------*/

											/*	I have to use one function instead 10 functions	*/
bool MouseIn1(SDL_Event event,VXO WeDraw){
	if(caseEtat[0]!=v) return false;
	if((event.motion.x<450 && event.motion.x>350) && (event.motion.y<200 && event.motion.y>100)){
		caseEtat[0]=WeDraw;
		return true;	
	}
	return false;
}
bool MouseIn2(SDL_Event event,VXO WeDraw){
	if(caseEtat[1]!=v) return false;
	if(event.motion.x<550 && event.motion.x>450 && event.motion.y<200 && event.motion.y>100){
		caseEtat[1]=WeDraw;
		return true;	
	}
	return false;
}
bool MouseIn3(SDL_Event event,VXO WeDraw){
	if(caseEtat[2]!=v) return false;
	if(event.motion.x<650 && event.motion.x>550 && event.motion.y<200 && event.motion.y>100){
		caseEtat[2]=WeDraw;
		return true;	
	}
	return false;
}
bool MouseIn4(SDL_Event event,VXO WeDraw){
	if(caseEtat[3]!=v) return false;
	if(event.motion.x<450 && event.motion.x>350 && event.motion.y<300 && event.motion.y>200){
		caseEtat[3]=WeDraw;
		return true;	
	}
	return false;
}
bool MouseIn5(SDL_Event event,VXO WeDraw){
	if(caseEtat[4]!=v) return false;
	if(event.motion.x<550 && event.motion.x>450 && event.motion.y<300 && event.motion.y>200){
		caseEtat[4]=WeDraw;
		return true;	
	}
	return false;
}
bool MouseIn6(SDL_Event event,VXO WeDraw){
	if(caseEtat[5]!=v) return false;
	if(event.motion.x<650 && event.motion.x>550 && event.motion.y<300 && event.motion.y>200){
		caseEtat[5]=WeDraw;
		return true;	
	}
	return false;
}
bool MouseIn7(SDL_Event event,VXO WeDraw){
	if(caseEtat[6]!=v) return false;
	if(event.motion.x<450 && event.motion.x>350 && event.motion.y<400 && event.motion.y>300){
		caseEtat[6]=WeDraw;
		return true;	
	}
	return false;
}
bool MouseIn8(SDL_Event event,VXO WeDraw){
	if(caseEtat[7]!=v) return false;	
	if(event.motion.x<550 && event.motion.x>450 && event.motion.y<400 && event.motion.y>300){
		caseEtat[7]=WeDraw;
		return true;	
	}
	return false;
}
bool MouseIn9(SDL_Event event,VXO WeDraw){
	if(caseEtat[8]!=v) return false;
	if(event.motion.x<650 && event.motion.x>550 && event.motion.y<400 && event.motion.y>300){
		caseEtat[8]=WeDraw;
		return true;	
	}
	return false;
}
/*----------------------------------------------------------------------*/
SDL_Rect XorOPosition(SDL_Event event,VXO WeDraw, bool *isitcorrect){
	SDL_Rect XorOP;
	*isitcorrect=false;
	if(MouseIn1(event,WeDraw)){
		XorOP.x=360;
		XorOP.y=110;
		*isitcorrect=true;
	}
	if(MouseIn2(event,WeDraw)){
		XorOP.x=460;
		XorOP.y=110;
		*isitcorrect=true;
	}
	if(MouseIn3(event,WeDraw)){
		XorOP.x=560;
		XorOP.y=110;
		*isitcorrect=true;
	}
	if(MouseIn4(event,WeDraw)){
		XorOP.x=360;
		XorOP.y=210;
		*isitcorrect=true;
	}
	if(MouseIn5(event,WeDraw)){
		XorOP.x=460;
		XorOP.y=210;
		*isitcorrect=true;
	}
	if(MouseIn6(event,WeDraw)){
		XorOP.x=560;
		XorOP.y=210;
		*isitcorrect=true;
	}
	if(MouseIn7(event,WeDraw)){
		XorOP.x=360;
		XorOP.y=310;
		*isitcorrect=true;
	}
	if(MouseIn8(event,WeDraw)){
		XorOP.x=460;
		XorOP.y=310;
		*isitcorrect=true;
	}
	if(MouseIn9(event,WeDraw)){
		XorOP.x=560;
		XorOP.y=310;
		*isitcorrect=true;
	}

	return XorOP;
}
bool drawX(SDL_Event event){

		SDL_Surface *imgX;
		imgX=IMG_Load("IMG/X.bmp");
		bool isitcorrect;	
		SDL_Rect imgXP=XorOPosition(event,x,&isitcorrect);
		if(isitcorrect==false){
			return false;
		}else{
			SDL_BlitSurface(imgX,NULL,window,&imgXP);
			SDL_FreeSurface(imgX);			
		}

		return true;
}

bool drawO(SDL_Event event){

		SDL_Surface *imgO;
		imgO=IMG_Load("IMG/O.bmp");
		bool isitcorrect;
		SDL_Rect imgOP=XorOPosition(event,o,&isitcorrect);
		if(isitcorrect==false){
			return false;
		}else{
			SDL_BlitSurface(imgO,NULL,window,&imgOP);
			SDL_FreeSurface(imgO);		
		}
		return true;

}
bool DrawXorO(SDL_Event event){

	static VXO XP=x;
	if(XP==x){
		if(!drawX(event)) return false;	
		XP=o;
	}else{
		if(!drawO(event)) return false;
		XP=x;	
	}
	return true;
	
}
/*----------------------------------------------------------------------*/
bool result(){
	
	static bool Jeux=true;
	if(Jeux==false){
			Jeux=true;
			return true;
	}
	
	static bool FirstTime=true;	
		
	static int nbrR=0;
	static int nbrRmax=8;
	
	static VXO s=x;
	
	if(caseEtat[0]==s && caseEtat[1]==s && caseEtat[2]==s){
		SDL_Surface *LingOfVictoire;
			LingOfVictoire=IMG_Load("IMG/4to6.png");
		SDL_Rect LingOfVictoireP;
			LingOfVictoireP.x=360;
			LingOfVictoireP.y=100;
		
		SDL_BlitSurface(LingOfVictoire,NULL,window,&LingOfVictoireP);
		SDL_FreeSurface(LingOfVictoire);
		
		printResult(s);
		
		nbrR=0;
		if(FirstTime){
			FirstTime=false;
			nbrRmax=7;
		}
		Jeux=false;
		DontWait=true;
		return true;
	}
	if(caseEtat[3]==s && caseEtat[4]==s && caseEtat[5]==s){
		SDL_Surface *LingOfVictoire;
			LingOfVictoire=IMG_Load("IMG/4to6.png");
		SDL_Rect LingOfVictoireP;
			LingOfVictoireP.x=360;
			LingOfVictoireP.y=200;
		
		SDL_BlitSurface(LingOfVictoire,NULL,window,&LingOfVictoireP);
		SDL_FreeSurface(LingOfVictoire);
		printResult(s);
		nbrR=0;
		if(FirstTime){
			FirstTime=false;
			nbrRmax=7;
		}
		Jeux=false;
		DontWait=true;
		return true;
	}
	if(caseEtat[6]==s && caseEtat[7]==s && caseEtat[8]==s){
		SDL_Surface *LingOfVictoire;
			LingOfVictoire=IMG_Load("IMG/4to6.png");
		SDL_Rect LingOfVictoireP;
			LingOfVictoireP.x=360;
			LingOfVictoireP.y=300;
		
		SDL_BlitSurface(LingOfVictoire,NULL,window,&LingOfVictoireP);
		SDL_FreeSurface(LingOfVictoire);
		printResult(s);
		nbrR=0;
		if(FirstTime){
			FirstTime=false;
			nbrRmax=7;
		}
		Jeux=false;
		DontWait=true;
		return true;
	}
	if(caseEtat[0]==s && caseEtat[3]==s && caseEtat[6]==s){
		SDL_Surface *LingOfVictoire;
			LingOfVictoire=IMG_Load("IMG/2to8.png");
		SDL_Rect LingOfVictoireP;
			LingOfVictoireP.x=350;
			LingOfVictoireP.y=110;
		
		SDL_BlitSurface(LingOfVictoire,NULL,window,&LingOfVictoireP);
		SDL_FreeSurface(LingOfVictoire);
		printResult(s);
		nbrR=0;
		if(FirstTime){
			FirstTime=false;
			nbrRmax=7;
		}
		Jeux=false;
		DontWait=true;
		return true;
	}
	if(caseEtat[1]==s && caseEtat[4]==s && caseEtat[7]==s){
		SDL_Surface *LingOfVictoire;
			LingOfVictoire=IMG_Load("IMG/2to8.png");
		SDL_Rect LingOfVictoireP;
			LingOfVictoireP.x=450;
			LingOfVictoireP.y=110;
		
		SDL_BlitSurface(LingOfVictoire,NULL,window,&LingOfVictoireP);
		SDL_FreeSurface(LingOfVictoire);
		printResult(s);
		nbrR=0;
		if(FirstTime){
			FirstTime=false;
			nbrRmax=7;
		}
		Jeux=false;
		DontWait=true;
		return true;
	}
	if(caseEtat[2]==s && caseEtat[5]==s && caseEtat[8]==s){
		SDL_Surface *LingOfVictoire;
			LingOfVictoire=IMG_Load("IMG/2to8.png");
		SDL_Rect LingOfVictoireP;
			LingOfVictoireP.x=550;
			LingOfVictoireP.y=110;
		
		SDL_BlitSurface(LingOfVictoire,NULL,window,&LingOfVictoireP);
		SDL_FreeSurface(LingOfVictoire);
		printResult(s);
		nbrR=0;
		if(FirstTime){
			FirstTime=false;
			nbrRmax=7;
		}
		Jeux=false;
		DontWait=true;
		return true;
	}
	if(caseEtat[0]==s && caseEtat[4]==s && caseEtat[8]==s){
		SDL_Surface *LingOfVictoire;
			LingOfVictoire=IMG_Load("IMG/1to9.png");
		SDL_Rect LingOfVictoireP;
			LingOfVictoireP.x=350;
			LingOfVictoireP.y=100;
		
		SDL_BlitSurface(LingOfVictoire,NULL,window,&LingOfVictoireP);
		SDL_FreeSurface(LingOfVictoire);
		printResult(s);
		nbrR=0;
		if(FirstTime){
			FirstTime=false;
			nbrRmax=7;
		}
		Jeux=false;
		DontWait=true;
		return true;
	}
	if(caseEtat[2]==s && caseEtat[4]==s && caseEtat[6]==s){
		SDL_Surface *LingOfVictoire;
			LingOfVictoire=IMG_Load("IMG/3to7.png");
		SDL_Rect LingOfVictoireP;
			LingOfVictoireP.x=350;
			LingOfVictoireP.y=100;
		
		SDL_BlitSurface(LingOfVictoire,NULL,window,&LingOfVictoireP);
		SDL_FreeSurface(LingOfVictoire);
		printResult(s);
		nbrR=0;
		if(FirstTime){
			FirstTime=false;
			nbrRmax=7;
		}
		Jeux=false;
		DontWait=true;
		return true;
	}
	
	printResult(v);
	
	if(s==x) s=o;
	else s=x;
	
	if(nbrR==nbrRmax){
		nbrR=0;
		if(FirstTime){
			FirstTime=false;
			nbrRmax=7;
		}

		DontWait=true;
		return true;
	}
	nbrR++;

	
	return false;
	
}
void printResult(VXO s){
	
	SDL_Surface *hide;
	hide=SDL_CreateRGBSurface(SDL_HWSURFACE,200,400,32,0,0,0,0);
	SDL_FillRect(hide,NULL,SDL_MapRGB(hide->format,0,0,0));
	
	
	SDL_Surface *xR;
	SDL_Surface *oR;
	
	SDL_Color xcolor={255,242,0};
	SDL_Color ocolor={0,255,0};
	
	TTF_Font *font;
	font=TTF_OpenFont("Milano.ttf",300);
	
	static char xvtxt[3]="0", ovtxt[3]="0";
	static int xv=0,ov=0;
	
	if(s==x){
		xv++;
		sprintf(xvtxt,"%d",xv);
	} 
	if(s==o){
		ov++;
		sprintf(ovtxt,"%d",ov);
	}
	
	SDL_Rect xRP;
		xRP.x=80;
		xRP.y=70;
		
	SDL_Rect oRP;
		oRP.x=800;
		oRP.y=70;
		
	xR=TTF_RenderText_Blended(font,xvtxt,xcolor);
	oR=TTF_RenderText_Blended(font,ovtxt,ocolor);
	
	SDL_BlitSurface(hide,NULL,window,&xRP);
	SDL_BlitSurface(hide,NULL,window,&oRP);
	SDL_BlitSurface(xR,NULL,window,&xRP);
	SDL_BlitSurface(oR,NULL,window,&oRP);





	TTF_CloseFont(font);
	SDL_FreeSurface(hide);
	SDL_FreeSurface(xR);
	SDL_FreeSurface(oR);

	
}
