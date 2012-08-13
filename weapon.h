#ifndef WEAPON_H
#define WEAPON_H

#include "SDL/SDL.h"

class Weapon{

private:
	
	SDL_Rect kord ;

	bool sudar;

public:

	Weapon();

	void setXY(int a , int b );

	bool alive();

	void setSudar();

	void Pomak();

	void prikaz();

	SDL_Rect getKord();

};
#endif 
