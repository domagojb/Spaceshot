#ifndef TARGET_H
#define TARGET_H
#include "SDL/SDL.h"

class Target{

private:

	bool zadnji;

	SDL_Rect kord;

	SDL_Rect laserKord;

	SDL_Rect sprite;

	int hp ; int spriteBrojac;

public:
	
	Target();

	Target(SDL_Rect kord2);

	Target(int i);

	void Prikaz();

	void Pomak(bool ulaz);

	void setDeadhp();

	void setLivehp();

	SDL_Rect getKord();

	bool alive();

	void setY();
    
	// POWER UP DA LEJZURZ
	void setLaser();

	bool laserAlive();

	void laserPomak();

	void laserPrikaz();

	SDL_Rect getLaserkord();




};

#endif
