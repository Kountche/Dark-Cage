#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL_rotozoom.h>

typedef struct ennemi
{
    int vie;//nombre de vie du joueur 
    int indice;
    int vitesse;//vitesse du perso
    int direction;//direction du perso
    SDL_Rect position;//position de l image par rapport a l ecran                                              
    SDL_Surface *image[4];//image sur forme de sprite c est a dire une image constitue de plusieurs posture du perso

} ennemi;

void init_enemi(ennemi *E);
void affiche(ennemi E,SDL_Surface *ecran);
void animer_ennemi(ennemi *E, int direction);
void mov_ennemi(ennemi *E);
//int arduinoWriteData(char x);// arduino
//int arduinoReadData(char *x);
