#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>


void initback (background *b ) 
{
  b->image=IMG_Load("back1.png") ;
  if (b->image == NULL) {
        fprintf(stderr, "Erreur : Chargement de l'image du fond impossible : %s\n", IMG_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
  b->pos.x=0 ;
  b->pos.y=0 ;
}

void afficherback (SDL_Surface *screen,background *b)
{
  if (SDL_BlitSurface(b->image,NULL,screen, &(b->pos)) < 0) {
        fprintf(stderr, "Erreur : Blit du fond d'écran impossible : %s\n", SDL_GetError());
        return;
    }
  
  SDL_Flip(screen) ;


}





void scrolling(SDL_Surface *screen, background *b) {
    SDL_Event event;
	int quit=0;

    SDL_WaitEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            quit = 1;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    if (b->pos.x + screen->w + 20 <= b->image->w) { // Vérifier si le déplacement à droite est possible
                        b->pos.x += 20;
                        SDL_BlitSurface(b->image, &(b->pos), screen, NULL);
                        SDL_Flip(screen);
                    }
                    break;
                case SDLK_LEFT:
                    if (b->pos.x - 20 >= 0) { // Vérifier si le déplacement à gauche est possible
                        b->pos.x -= 20;
                        SDL_BlitSurface(b->image, &(b->pos), screen, NULL);
                        SDL_Flip(screen);
                    }
                    break;
                case SDLK_UP:
                    if (b->pos.y - 20 >= 0) { // Vérifier si le déplacement vers le haut est possible
                        b->pos.y -= 20;
                        SDL_BlitSurface(b->image, &(b->pos), screen, NULL);
                        SDL_Flip(screen);
                    }
                    break;
                case SDLK_DOWN:
                    if (b->pos.y + screen->h + 20 <= b->image->h) { // Vérifier si le déplacement vers le bas est possible
                        b->pos.y += 20;
                        SDL_BlitSurface(b->image, &(b->pos), screen, NULL);
                        SDL_Flip(screen);
                    }
                    break;
            }
            break;
    }

}
#define MAX_SCORES 100

void chargerScores(ScoreInfo t[]) {
    FILE *fichier_scores = fopen("scores.txt", "r"); // Open the score file for reading
    if (fichier_scores == NULL) {
        fprintf(stderr, "Erreur : Impossible d'ouvrir le fichier des scores.\n");
        return;
    }

    // Read scores line by line and store them in the array t[]
    for (int i = 0; i < MAX_SCORES; i++) {
        // Read a line in the format "name score time"
        if (fscanf(fichier_scores, "%s %d %d", t[i].name, &t[i].score, &t[i].temps) != 3) {
            break; // If reading fails, stop the loop
        }
    }

    fclose(fichier_scores); // Close the score file after reading
}

