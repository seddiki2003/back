#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


#define SCREEN_W 1000
#define SCREEN_H 400




typedef struct 
{
 
SDL_Surface *image;
SDL_Rect pos;
	
}background;


typedef struct {
    char name[50];
    int score;
    int temps;
    SDL_Surface *text_score;
    SDL_Rect positionscore;
    TTF_Font *police;
} ScoreInfo;


void initback (background *b) ;
void afficherback(SDL_Surface *screen, background *b) ;
void scrolling (SDL_Surface *screen,background *b);
void chargerScores(ScoreInfo t[]);
void trierScores(ScoreInfo t[]);
void afficherBest(SDL_Surface* ecran, ScoreInfo t[]);

