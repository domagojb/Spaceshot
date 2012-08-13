#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "globalneVar.h"
#include <string>
#include "SDL/SDL.h"
#include <stdio.h>
#include "konstante.h"
#include <iostream>

class HighScores{

private: 

	struct Player
	{
		int bodovi;
		string ime ;
	};

	FILE *datoteka;

	

	int spot ;
	

public:

	HighScores();

	void prikaziHighscore();
    
	bool isHighscore();
	
	void upisHighscore();

	void handleHighscore();
	

};

#endif 
