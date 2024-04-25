#include "header.h"



int main( int argc, char **argv)
{
	
	int quit =0;
	background b;
	SDL_Init( SDL_INIT_VIDEO);
	SDL_Surface *screen, *animation;
	SDL_Event event;
	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,SDL_HWSURFACE | SDL_SRCALPHA);
	if( !screen)
{
	printf("unable to set 1920*1080: %s\n",SDL_GetError());
	return 1; 
}

	initback(&b) ;
  	afficherback(screen,&b) ;
	SDL_EnableKeyRepeat(10, 10);
	
while(!quit)
{
	scrolling (screen ,&b ) ;
        SDL_Flip(screen);
        while(SDL_PollEvent(&event))
{       if(event.type==SDL_QUIT)
        {SDL_FreeSurface(screen);
        quit=1;}	
}
}	



return 0;
}



