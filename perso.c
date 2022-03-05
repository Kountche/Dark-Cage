#include "perso.h"
void initialiser_Personnage(Personnage *P)
{

    P->vie = 3;
    P->score = 0;
    P->vitesse = 0;
    P->direction = 1;
    P->indice = 0;

    P->coeur = IMG_Load("life.png");
    P->dollar = IMG_Load("dollar.png");
    P->imagesprite[0] = IMG_Load("rc00.png");
    P->imagesprite[1] = IMG_Load("rc01.png");
    P->imagesprite[2] = IMG_Load("rc02.png");
    P->imagesprite[3] = IMG_Load("rc03.png");
    P->imagesprite[4] = IMG_Load("rc04.png");
    P->imagesprite[5] = IMG_Load("rc05.png");
    P->imagesprite[6] = IMG_Load("rc06.png");
    P->imagesprite[7] = IMG_Load("rc07.png");
    P->imagesprite[8] = IMG_Load("rc08.png");
////////////////////////////////////////////////////////////////jump
    P->imagesjump[0] = IMG_Load("jump.r.1.png");
    P->imagesjump[1] = IMG_Load("jump.r.2.png");
    P->imagesjump[2] = IMG_Load("jump.r.3.png");
    P->imagesjump[3] = IMG_Load("jump.r.3.png");
    P->imagesjump[4] = IMG_Load("jump.r.4.png");
    P->imagesjump[5] = IMG_Load("jump.r.5.png");
    P->imagesjump[6] = IMG_Load("jump.l.1.png");
    P->imagesjump[7] = IMG_Load("jump.l.1.png");
    P->imagesjump[8] = IMG_Load("jump.l.1.png");
     P->imagesjump[9] = IMG_Load("jump.l.1.png");
    P->imagesjump[10] = IMG_Load("jump.l.1.png");
    P->imagesjump[11] = IMG_Load("jump.l.1.png");
    P->imagesjump[12] = IMG_Load("jump.l.1.png");

    P->post_coeur.x = 50;
    P->post_coeur.y = 50;

    P->post_dollar.x = 50;
    P->post_dollar.y = 125;

    P->position.x = 50;
    P->position.y = 400;
}

void jump(Personnage *p)
{

}

void afficher_perso(Personnage P, SDL_Surface *ecran)
{
    SDL_BlitSurface(P.imagesprite[P.indice], NULL, ecran, &P.position);
  /* SDL_BlitSurface(P.imagesjump[P.jumpindice], NULL, ecran, &P.position);*/
    SDL_BlitSurface(P.coeur, NULL, ecran, &P.post_coeur);
   // SDL_BlitSurface(P.dollar, NULL, ecran, &P.post_dollar);
}
void deplacer_Perso(Personnage *P, int direction)
{
    switch(direction)
    {
    case 1:
if(P->position.x > 400)
P->position.x -= 10;
else
        P->position.x += 10;
        break;

    case 2:
if(P->position.x <150)
P->position.x += 10;
else
        P->position.x -= 10;
        break;
    }
}
void animer_perso(Personnage *P, int direction)
{
    if(direction == 0)
    {  
        P->indice = 8;
    }

    if(direction == 1)
    {
        if(P->indice < 3)
        {
            P->indice ++;
        }
        else
            P->indice = 0;
    }

    if(direction == 2)
    {
        if(P->indice < 7 && P->indice > 3)
        {
            P->indice ++;
        }
        else
            P->indice = 4;
    }
//////////////////////////////////////////////////////////////////////jump
 if(direction == 0)
    {  
        P->jumpindice = 12;
    }

    if(direction == 1)
    {
        if(P->jumpindice < 5)
        {
            P->jumpindice ++;
        }
        else
            P->jumpindice = 0;
    }

    if(direction == 2)
    {
        if(P->jumpindice <= 12 && P->jumpindice > 5)
        {
            P->jumpindice++;
        }
        else
            P->jumpindice = 5;
    }
}



void Player_Jump (Personnage* perso) /*structure qui contient le personnage (pointeur) */ 
{
	if(perso->jump ==0 && perso->ground == 1) // verification du position 
	{
		perso->jump = 1;//joueur en position de saut
		perso->ground = 0;//joueur en en aire
		perso->Ysaut = -28;
		perso->position.y -= 5;
	}
}

void UpdatePlayer(Personnage* perso)
{
      int collision_sol;
	if(collision_sol==1)
	{
		perso->ground = 1;
		perso->Ysaut = 0;
	}

	if(collision_sol==0 && perso->jump ==0)
	{
		perso->Ysaut = 10;
	}
	
	if(perso->jump == 1 && perso->Ysaut < 0)
	{
		perso->Ysaut += 8;
	}

	else

		perso->jump = 0;
		

	perso->position.y += perso->Ysaut ;
}
