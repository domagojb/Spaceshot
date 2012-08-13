#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL/SDL.h"

class Spaceship{

private:
   
	
	int x , y; 

	int xPomak ;

	SDL_Rect kord;

public:

	Spaceship();

	void ulazTipkovnice();

		

	void pomak();

	void prikaz();


	int getX();

	int getY();

	SDL_Rect getKord();
};

#endif 
