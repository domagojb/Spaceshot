#include "SDL/SDL.h"
#include "globalneVar.h"
#include "konstante.h"
#include "spaceship.h"






Spaceship::Spaceship(){
		x = 320;
		y = 400;
		xPomak = 0;
		kord.h = DUZINA_BRODA;
		kord.w = SIRINA_BRODA;
		
}

void Spaceship::ulazTipkovnice(){
		
		if ( event.type == SDL_KEYDOWN )
			
			switch ( event.key.keysym.sym){

				case SDLK_LEFT : xPomak -= 10 ;   break;
				case SDLK_RIGHT : xPomak += 10 ; break;
		}

		if ( event.type == SDL_KEYUP )

			switch ( event.key.keysym.sym){

				case SDLK_LEFT : xPomak += 10 ;   break;
				case SDLK_RIGHT : xPomak -= 10 ; break;
		} 

}

void  Spaceship::pomak(){

		x += xPomak / 2;

		if ( ( x < 0 ) || ( x > REZOLUCIJA_S - SIRINA_BRODA  ) )

			x -= xPomak / 2 ;

		
}

void Spaceship::prikaz(){

		

	    kord.x = x;
	    kord.y = y;

	    SDL_BlitSurface(brod , NULL  , prozor , &kord );
	
}


int Spaceship::getX(){

		return this->x ;

}

int Spaceship::getY(){

		return this->y;

}

SDL_Rect Spaceship::getKord(){

	return kord;

}
