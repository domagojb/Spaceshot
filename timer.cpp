#include "timer.h"
#include "konstante.h"
#include "SDL/SDL.h"

Timer::Timer(){}

void Timer::start(){

	vrijeme = SDL_GetTicks();

}

int Timer::getVrijeme(){

	int trenutnoVrijeme = SDL_GetTicks() - vrijeme;

	return trenutnoVrijeme ;

}

