#include "enemi.h"

void init_enemi(ennemi *E){

E->vie=3;
E->vitesse=2;
E->direction=1;

E->indice=0;
E->position.x=700;
E->position.y=400;
E->image[0] = IMG_Load("moster1.png");
E->image[1] = IMG_Load("moster2.png");
E->image[2] = IMG_Load("moster3.png");
E->image[3] = IMG_Load("moster4.png");
}

void affiche(ennemi E,SDL_Surface *ecran)
{


SDL_BlitSurface(E.image[E.indice], NULL, ecran, &E.position);

}



 void animer_ennemi(ennemi *E, int direction)
{
    if(direction == 0)
    {  
        E->indice = 4;
    }

    if(direction == 1)
    {
        if(E->indice < 3)
        {
            E->indice ++;
        }
        else
            E->indice = 0;
    }

   /* if(direction == 2)
    {
        if(E->indice < 7 && E->indice > 3)
        {
            E->indice ++;
        }
        else
            E->indice = 4;
    }
*/
}

void mov_ennemi(ennemi *E)
{


E->position.x -=10; 


}


