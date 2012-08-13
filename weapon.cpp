#include "SDL/SDL.h"
#include "weapon.h"
#include "globalneVar.h"
#include "konstante.h"

Weapon::Weapon(){}

void Weapon::setXY(int a , int b ){

		kord.x = a + SIRINA_BRODA / 2;
		kord.y = b ;
		kord.w = DUZINA_LASERA ;
		kord.h = SIRINA_LASERA ;
		sudar = false;

	}

bool Weapon::alive(){
		
		if (kord.y < 0) return false;

		if (!sudar) return true;

		return false;

	}

void Weapon::setSudar(){

		sudar = true ;

	}

void Weapon::Pomak(){

		kord.y -= DUZINA_LASERA + 3 ;

	}

void Weapon::prikaz(){
		
		SDL_BlitSurface(wepn , NULL  , prozor , &kord );

	}

SDL_Rect Weapon::getKord(){

		return kord ;

	}
                     


