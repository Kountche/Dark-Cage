#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL_rotozoom.h>

typedef struct Personnage
{
    int vie;//nombre de vie du joueur 
    int score;//score du joueur
    int indice;
    int jumpindice;
    char nom[20];//nom du joueur
    int vitesse;//vitesse du perso
    int direction;//direction du perso
    int onground;
    int jump;
    Sint16 Ysaut;
    int ground;

    
    SDL_Rect position;//position de l image par rapport a l ecran
    SDL_Rect post_coeur;
    SDL_Rect post_dollar;  

    SDL_Surface *dollar;
    SDL_Surface *coeur;                                                           
    SDL_Surface *imagesprite[8];//image sur forme de sprite c est a dire une image constitue de plusieurs posture du perso
    SDL_Surface *imagesjump[12];
} Personnage;
//Prototype des fonctions
void initialiser_Personnage(Personnage *P);
void afficher_perso(Personnage P, SDL_Surface *ecran);//afficher un 1er et unique perso
void deplacer_Perso(Personnage *P, int direction);//deplacer un perso moyennant le clavier dans un cadre fixe de la map 
void animer_perso(Personnage *P, int direction);//animer le perso lors du deplacement
void Player_Jump (Personnage* perso);
void UpdatePlayer(Personnage* perso);
#endif

