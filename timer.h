#ifndef TIMER_H
#define TIMER_H

#include "SDL/SDL.h"

class Timer{

private:

	int vrijeme;

public:

	Timer();

	void start();

	int getVrijeme();

};

#endif 
