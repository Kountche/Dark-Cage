#include "collision.h"
SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y)
{
	SDL_Color color;
	Uint32 col = 0 ;

	//determine position
	char* pPosition = ( char* ) pSurface->pixels ;

	//offset by y
	pPosition += ( pSurface->pitch * y ) ;

	//offset by x
	pPosition += ( pSurface->format->BytesPerPixel * x ) ;

	//copy pixel data
	memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

	//convert color
	SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}

int collision_sol(background *bg,Personnage *per) // collision personage principale avec obstacle
{
	int verif=0;
	int i;
	SDL_Color couleur[3];
	//pixel color perso pri
	couleur[0] = GetPixel (bg->image[1],bg->scroll.x + per->position.x , per->position.y + per->position.h );// foot left
	couleur[1] = GetPixel (bg->image[1],bg->scroll.x + per->position.x + per->position.w ,per->position.y + per->position.h );// foot right
	couleur[2] = GetPixel (bg->image[1],bg->scroll.x + per->position.x + (int)per->position.w/2,per->position.y + per->position.h ); // foot mid
	
	for(i=0;i<3;i++)
	{
		if((couleur[i].r == 255) && ((couleur[i].g == 255) && (couleur[i].b == 255))) // a changer
		{
			verif=1;
			break;
		}
	}
	if (verif==1)
{
		return 1;
}
	else return 0;
}


