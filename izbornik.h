#ifndef IZBORNIK_H
#define IZBORNIK_H

#include "SDL/SDL.h"
#include "timer.h"
#include <string>

using namespace std;


class izbornik{

private:

	Timer fps;

	bool radi ;
    bool sound;
	bool music;
	int difficulty;
	int highscorediff;

	std::string soundString;
	std::string musicString;
	std::string difficultyString;
	
	SDL_Rect pozNaslov;
	SDL_Rect poz_play_button;
    SDL_Rect poz_options_button;
    SDL_Rect poz_difficulty_button;
    SDL_Rect poz_back_button;
	SDL_Rect poz_back_button_2;
    SDL_Rect poz_sound_button;
	SDL_Rect poz_music_button;
	SDL_Rect poz_quit_button;
	SDL_Rect poz_easy_button;
	SDL_Rect poz_medium_button;
    SDL_Rect poz_hard_button;
	SDL_Rect poz_highscore_button;
   
	//highscore vars
	struct Player
	{
		int bodovi;
		string ime ;
	};

	FILE *datoteka;

	int spot ;
	

public:

	izbornik();

	bool pocetakPrikaz();

	void prikaziSliku(int x , int y , SDL_Surface *slika , SDL_Surface *podrucje);
    
	void rectInit();
	
	void Options();

	void _High_Score_Menu();

	int getDifficulty();
	 
    bool getSound();

	bool getMusic();

	void setMusic(bool muzik);

	//highscore func.

	void prikaziHighscore();
    
	bool isHighscore();
	
	void upisHighscore();

	bool handleHighscore();

	std::string upisIme();

	

};



#endif
