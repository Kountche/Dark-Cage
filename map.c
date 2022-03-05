#include "map.h"
void initialiser_map(map *Mp)
{
    Mp->image = IMG_Load("Map3.jpg");

    Mp->pos.x = 500;
    Mp->pos.y = 500;
    Mp->pos.h = Mp->image->h;
    Mp->pos.w = Mp->image->w;

    Mp->post_map.x = 0;
    Mp->post_map.y = 0;
    Mp->post_map.h = Mp->image->h;
    Mp->post_map.w = Mp->image->w;

}

void afficher_map(SDL_Surface *ecran, map Mp)
{
    SDL_BlitSurface(Mp.image, &Mp.pos, ecran, &Mp.post_map);
}

void scrolling_map(map *Mp, int etat)
{
    switch(etat)
    {
    case 0:
        Mp->pos.x = Mp->pos.x + 10;
        break;

    case 1:
        Mp->pos.x = Mp->pos.x - 10;
        break;

    case 2:
        Mp->pos.y = Mp->pos.y + 10;
        break;

    case 3:
        Mp->pos.y = Mp->pos.y - 10;
        break;
    }
}
