#ifndef GLOBALNE_H
#define GLOBALNE_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <string>
#include <vector>
#include "target.h"

using namespace std;

extern vector<vector <Target> > aliens; 

extern bool desno;
extern bool ponoviLevel;

extern int scoreBroj;
extern int levelBroj;
extern int livesBroj;
extern int randomY;

extern int picajzleX;
extern int picajzleY;

extern int targetPomakx;
extern int brojTarget;

extern SDL_Surface *pozadina;
extern SDL_Surface *prozor;
extern SDL_Surface *brod;
extern SDL_Surface *wepn;
extern SDL_Surface *targetWepn;
extern SDL_Surface *targetp;
extern SDL_Surface *score;
extern SDL_Surface *level;
extern SDL_Surface *kraj;
extern SDL_Surface *lives;
extern SDL_Surface *introPozadina;
extern SDL_Surface *introText;
extern SDL_Surface *soundText;
extern SDL_Surface *musicText;
extern SDL_Surface *difficultyText;
extern SDL_Surface *startText;

//buttons
extern SDL_Surface *options_button;
extern SDL_Surface *play_button;
extern SDL_Surface *sound_button;
extern SDL_Surface *music_button;
extern SDL_Surface *difficulty_button;
extern SDL_Surface *back_button;
extern SDL_Surface *quit_button;
extern SDL_Surface *highscore_button;
extern SDL_Surface *easy_button;
extern SDL_Surface *medium_button; 
extern SDL_Surface *hard_button; 

extern Mix_Chunk *Gameover;
extern Mix_Chunk *killTarget; 
extern Mix_Chunk *shot;
extern Mix_Chunk *startPlay;
extern Mix_Chunk *newHighscore;
extern Mix_Chunk *abouttoshot;
extern Mix_Chunk *bshot;
extern Mix_Music *gameMusic;
extern Mix_Music *introMusic;


extern std::string scoreString;
extern char scoreChar[50];

extern std::string levelString;
extern char levelChar[50];

extern std::string livesString;
extern char livesChar[1];

extern SDL_Color bojaTexta;
extern SDL_Color crvena;
extern SDL_Color plava;
extern SDL_Color bijela;

extern TTF_Font *font;
extern TTF_Font *font2;
extern TTF_Font *optionsFont;

extern SDL_Event event;

#endif 
