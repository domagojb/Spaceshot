#include "globalneVar.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <string>
#include <vector>
#include "target.h"

using namespace std;

vector<vector <Target> > aliens(5,vector<Target>(10)); 

bool desno = true;
bool ponoviLevel = false;

int scoreBroj =  0 ;
int levelBroj = 0 ;
int livesBroj = 3 ;
int randomY = 2000;

int picajzleX = 0;
int picajzleY = 0;

int targetPomakx = 1;
int brojTarget = 0;

SDL_Surface *pozadina = NULL ;
SDL_Surface *prozor = NULL ;
SDL_Surface *brod = NULL ;
SDL_Surface *wepn = NULL ;
SDL_Surface *targetWepn = NULL ;
SDL_Surface *targetp = NULL ;
SDL_Surface *score = NULL ;
SDL_Surface *level = NULL ;
SDL_Surface *kraj = NULL ;
SDL_Surface *lives = NULL ;
SDL_Surface *introPozadina = NULL ;
SDL_Surface *introText;
SDL_Surface *soundText;
SDL_Surface *musicText;
SDL_Surface *difficultyText;
SDL_Surface *startText;

//buttons 
SDL_Surface *options_button = NULL;
SDL_Surface *play_button = NULL;
SDL_Surface *sound_button = NULL;
SDL_Surface *music_button = NULL;
SDL_Surface *difficulty_button = NULL;
SDL_Surface *back_button = NULL;
SDL_Surface *quit_button = NULL;
SDL_Surface *highscore_button = NULL;
SDL_Surface *easy_button = NULL;
SDL_Surface *medium_button = NULL;
SDL_Surface *hard_button = NULL;

Mix_Chunk *Gameover = NULL;
Mix_Chunk *killTarget; 
Mix_Chunk *shot;
Mix_Chunk *startPlay = NULL;
Mix_Chunk *newHighscore;
Mix_Chunk *abouttoshot;
Mix_Chunk *bshot;
Mix_Music *gameMusic;
Mix_Music *introMusic;


std::string scoreString = "Bodovi: 0" ;
char scoreChar[50] ;

std::string levelString ;
char levelChar[50] ;

std::string livesString ;
char livesChar[1] ;

SDL_Color bojaTexta = { 0 , 255 , 60 };
SDL_Color crvena = { 255, 0 , 0 };
SDL_Color plava = { 0 , 0 , 255 };
SDL_Color bijela = {255 , 255, 255 };

TTF_Font *font = NULL;
TTF_Font *font2 = NULL;
TTF_Font *optionsFont = NULL;

SDL_Event event;
