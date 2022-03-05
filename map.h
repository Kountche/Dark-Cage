#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL_rotozoom.h>

typedef struct map
{
    SDL_Rect pos;
    SDL_Rect post_map;//position du background par rapport a l ecran
    SDL_Surface *image;//tableau de background
    
} map;
//Prototype des fonctions
void initialiser_map(map *Mp);
void afficher_map(SDL_Surface *ecran, map Mp);
void scrolling_map( map *Mp, int etat);//scroller verticalement et /ou horizontalement tout le cadre si le perso atteint les limites du cadre
