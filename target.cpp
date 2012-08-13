#include "target.h"
#include "SDL/SDL.h"
#include "globalneVar.h"
#include "konstante.h"
#include <time.h> 

	
Target::Target(){
		
	    kord.x = (REZOLUCIJA_S - (10* ( SIRINA_TARGETA+SIRINA_TARGETA/2 ) ) ) / 2;
	    kord.y = 50;
		kord.w = SIRINA_TARGETA;
		kord.h = DUZINA_TARGETA;

		laserKord.y = 481;
		laserKord.w = SIRINA_LASERA;
		laserKord.h = DUZINA_LASERA;
		
		hp = 1;
		
		spriteBrojac = 0;
}

Target::Target(SDL_Rect kord2){

	    kord.x = kord2.x + SIRINA_TARGETA + SIRINA_TARGETA/2;
	    kord.y = kord2.y;
		kord.w = SIRINA_TARGETA;
		kord.h = DUZINA_TARGETA;

		laserKord.y = 481;
		laserKord.w = SIRINA_LASERA;
		laserKord.h = DUZINA_LASERA;

		hp = 1;
		
        spriteBrojac = 0;
}

Target::Target(int i){

	    kord.x = (REZOLUCIJA_S - (10* ( SIRINA_TARGETA+SIRINA_TARGETA/2 ) ) ) / 2;
	    kord.y = 50+DUZINA_TARGETA * i;
	    kord.w = SIRINA_TARGETA;
	    kord.h = DUZINA_TARGETA;
  
	    laserKord.y = 481;
		laserKord.w = SIRINA_LASERA;
		laserKord.h = DUZINA_LASERA;

     	hp = 1;
    		
        spriteBrojac = 0;

}

void Target::Prikaz(){
        
		spriteBrojac++;
		if ( spriteBrojac > 20 ) spriteBrojac = 0;

		

		if (spriteBrojac < 10 ){

			sprite.x = 0;
		    sprite.y = 0;
			sprite.w = SIRINA_TARGETA;
			sprite.h = DUZINA_TARGETA;
			

		}
		else {
			
			sprite.x = 34;
		    sprite.y = 0;
			sprite.w = SIRINA_TARGETA;
			sprite.h = DUZINA_TARGETA;
			
		}

		SDL_BlitSurface(targetp , &sprite , prozor , &kord);



}

void Target::Pomak(bool ulaz){

	if (ulaz) {

		kord.x += targetPomakx;
	}

	else {

		kord.x -= targetPomakx;

	}
}


void Target::setDeadhp(){

		hp = 0;
}

void Target::setLivehp(){
	    
	    hp = 1;

}



	
SDL_Rect Target::getKord(){

		return kord;
}

bool Target::alive(){

	    if (hp == 0 ) return false;


		return true;

}

void Target::setY(){

	kord.y += 5;

}

void Target::setLaser(){

	laserKord.x = kord.x;
	laserKord.y = kord.y + kord.h;

}

bool Target::laserAlive(){

	if (laserKord.y < 480) return true;
	else return false;

}

void Target::laserPomak(){

	laserKord.y += DUZINA_LASERA / 2 ;

}

void Target::laserPrikaz(){

	SDL_BlitSurface( targetWepn , NULL , prozor , &laserKord );

}

SDL_Rect Target::getLaserkord(){

	return laserKord;

}



