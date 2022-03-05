#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL_rotozoom.h>
#include "perso.h"
#include "background.h"
#include "map.h"
#include "enemi.h"
SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y);
int collision_sol(background *bg,Personnage *per); // collision personage principale avec obstacle
