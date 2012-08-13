#include "highscore.h"
#include "globalneVar.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <stdio.h>
#include "izbornik.h"

using namespace std;

HighScores::HighScores(){}

void HighScores::upisHighscore(){

	bool flag = true  ;

	izbornik meni ;

	if (meni.getDifficulty() == 1) datoteka = fopen("hse.bin","rb");
	else if ( meni.getDifficulty() == 2 ) datoteka = fopen("hsm.bin","rb");
	else datoteka = fopen("hsh.bin","rb");

	vector<Player> Igrac;
	
	
	Player ucitaniIgrac , pomocniIgrac;

	for(int i = 0 ; i < 5 ; i++ )
	{
		fread(&ucitaniIgrac , sizeof(Player) , 1 , datoteka );
		Igrac.push_back(ucitaniIgrac);
	}
    
	
	int i = 0;

	for(vector<Player>::iterator it = Igrac.begin() ; (it < Igrac.end() ) && (flag == true) ; ++i )
	{
		if (Igrac[i].bodovi <= scoreBroj)
		{
			pomocniIgrac.bodovi = scoreBroj ;
			pomocniIgrac.ime = "P" ;
			
			//Igrac.pop_back();
			Igrac.insert(it , pomocniIgrac );
			it = Igrac.begin();
			flag = false ;
		}
		else ++it ;
		 
	}
    
	fclose(datoteka);
	
    if (meni.getDifficulty() == 1) datoteka = fopen("hse.bin","rb");
	else if ( meni.getDifficulty() == 2 ) datoteka = fopen("hsm.bin","rb");
	else datoteka = fopen("hsh.bin","rb");
	
	for(int i = 0 ; i < 5 ; i++ )
	{
		//fseek( datoteka , sizeof(Player)*i , SEEK_SET );
		fwrite(&Igrac[i] , sizeof(Player) , 1 , datoteka );
	}

	fclose(datoteka);


}

bool HighScores::isHighscore(){

	izbornik meni ;

	if (meni.getDifficulty() == 1) datoteka = fopen("hse.bin","rb");
	else if ( meni.getDifficulty() == 2 ) datoteka = fopen("hsm.bin","rb");
	else datoteka = fopen("hsh.bin","rb");
    
    Player igrac ;

	for(int i = 0 ; i<5 ; i++ )
	{
		fread(&igrac , sizeof(Player) , 1 , datoteka );

		if (scoreBroj > igrac.bodovi)
		{
			fclose(datoteka);
			return true;
		}

	}
    
	fclose(datoteka);
	return false ;
  
	
}

void HighScores::handleHighscore(){

	if (isHighscore())
	{
		upisHighscore();
	}



}

void HighScores::prikaziHighscore(){
    
    SDL_Surface *ispisHighscore ;
	SDL_Rect kord ;

	izbornik meni ;

	

	if (meni.getDifficulty() == 1) datoteka = fopen("hse.bin","rb");
	else if ( meni.getDifficulty() == 2 ) datoteka = fopen("hsm.bin","rb");
	else datoteka = fopen("hsh.bin","rb");

	Player Igrac ;
	string ispis ;
    char charBodovi[50];
	char place[50];

	SDL_BlitSurface( introPozadina , NULL , prozor , NULL );

    for(int i = 0 ; i<5 ; i++)
	{
		//fseek( datoteka , sizeof(Player)*i , SEEK_SET );
		fread(&Igrac , sizeof(Player) , 1 , datoteka );
		
		sprintf(charBodovi , "%d" , Igrac.bodovi );
		sprintf(place , "%d" , i+1 );
		ispis = place[0] + (string)". " + Igrac.ime + (string)" " + charBodovi;

		ispisHighscore = TTF_RenderText_Solid( font2 , ispis.c_str() , bojaTexta );
		
		kord.x = 180 ;
		kord.y = 70 +  70 * i  ;
		
		SDL_BlitSurface( ispisHighscore , NULL , prozor , &kord );
        
		
		
	}
	SDL_Flip(prozor);
	

	fclose(datoteka);

	


}




 

