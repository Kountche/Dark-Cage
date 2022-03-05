#include "background.h"

void initialiser_background(background *Back)
{
    Back->stage = 0;

    Back->image[0] = IMG_Load("obs.png");
    Back->image[1] = IMG_Load("sans.png");
    Back->image[2] = IMG_Load("Back02.png");

    Back->pos.x = 0;
    Back->pos.y = 0;
    Back->pos.h = Back->image[0]->h;
    Back->pos.w = Back->image[0]->w;

    Back->post_background.x = 0;
    Back->post_background.y = 0;
    Back->post_background.h = Back->image[0]->h;
    Back->post_background.w = Back->image[0]->w;

}

void afficher_background(SDL_Surface *ecran, background Back)
{
    SDL_BlitSurface(Back.image[0], &Back.pos, ecran, &Back.post_background);
}

void scrolling_background(background *Back, int etat)
{
    switch(etat)
    {
    case 0:
        Back->pos.x = Back->pos.x + 10;
        break;

    case 1:
        Back->pos.x = Back->pos.x - 10;
        break;
    }
}
