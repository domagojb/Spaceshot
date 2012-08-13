#include "izbornik.h"
#include "globalneVar.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "konstante.h"


izbornik::izbornik(){

	radi = true ;
	
	pozNaslov.x = 0;
	pozNaslov.y = 150;
	
	introText = TTF_RenderText_Solid ( font2 , "SPACESHOT" , plava );

	sound = true ;
    music = true ;
	difficulty = 1 ;
	picajzleX = 5 ; 
	picajzleY = 6 ;

	soundString = "ON" ;
	musicString = "ON" ;
	difficultyString = "EASY" ;
	

	soundText = TTF_RenderText_Solid ( optionsFont , soundString.c_str() , plava );
    musicText = TTF_RenderText_Solid ( optionsFont , musicString.c_str() , plava );
    difficultyText = TTF_RenderText_Solid( optionsFont , difficultyString.c_str() , plava );
	

	rectInit();

	
	

}

bool izbornik::pocetakPrikaz(){

	

	int alpha = SDL_ALPHA_OPAQUE ;

	if (music) Mix_PlayMusic( introMusic , -1 );

	while(radi){

		fps.start();

		if (pozNaslov.x < 170) pozNaslov.x += 1;
		else radi = false;

		while(SDL_PollEvent(&event)){

			if (event.type == SDL_KEYDOWN) radi = false;

			if (event.type == SDL_QUIT) return false;

		}
        
		SDL_BlitSurface( introPozadina , NULL , prozor , NULL );

		SDL_BlitSurface( introText , NULL , prozor ,&pozNaslov );
		

	    SDL_Flip( prozor );

		if ( fps.getVrijeme() < (1000/FPS) ){
			
			SDL_Delay( (1000/FPS)-fps.getVrijeme());
		}

	 

	}

	radi = true;
	pozNaslov.x = 170;
	

	while(radi)
	{

		

		while(SDL_PollEvent(&event))
		{

			if (event.type == SDL_MOUSEMOTION)
			{
                
				
				// begin PLAY BUTTON
				if ( (event.motion.x > poz_play_button.x) && ( event.motion.x < poz_play_button.x + poz_play_button.w) 
					&& ( event.motion.y > poz_play_button.y ) && (event.motion.y < poz_play_button.y + poz_play_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( play_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha(play_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
				// end PLAY BUTTON
                
				// begin OPTIONS BUTTON
                if ( (event.motion.x > poz_options_button.x) && ( event.motion.x < poz_options_button.x + poz_options_button.w) 
					&& ( event.motion.y > poz_options_button.y ) && (event.motion.y < poz_options_button.y + poz_options_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( options_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha( options_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
				// end OPTIONS BUTTON 

				// begin HIGHSCORE BUTTON
				if ( (event.motion.x > poz_highscore_button.x) && ( event.motion.x < poz_highscore_button.x + poz_highscore_button.w) 
					&& ( event.motion.y > poz_highscore_button.y ) && (event.motion.y < poz_highscore_button.y + poz_highscore_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( highscore_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha( highscore_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
				// end HIGHSCORE BUTTON 

			    // begin QUIT BUTTON
				if ( (event.motion.x > poz_quit_button.x) && ( event.motion.x < poz_quit_button.x + poz_quit_button.w) 
					&& ( event.motion.y > poz_quit_button.y ) && (event.motion.y < poz_quit_button.y + poz_quit_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( quit_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha( quit_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );

				// end QUIT BUTTON 

			}


            
			if (event.type == SDL_MOUSEBUTTONUP)
			{

				// begin PLAY BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_play_button.x) && ( event.button.x < poz_play_button.x+ poz_play_button.w) 
						&& ( event.button.y > poz_play_button.y ) && (event.button.y < poz_play_button.y + poz_play_button.h) )
					{
					    Mix_HaltMusic(); 
						radi = false;
					}
				}
				// end PLAY BUTTON

				// begin OPTIONS BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_options_button.x) && ( event.button.x < poz_options_button.x+ poz_options_button.w) 
						&& ( event.button.y > poz_options_button.y ) && (event.button.y < poz_options_button.y + poz_options_button.h) )
					{
						
				       // otvori options
					   Options();
					   radi = true; 

					}

				}
				// end OPTIONS BUTTON

				// begin HIGHSCORE BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_highscore_button.x) && ( event.button.x < poz_highscore_button.x+ poz_highscore_button.w) 
					&& ( event.button.y > poz_highscore_button.y ) && (event.button.y < poz_highscore_button.y + poz_highscore_button.h) )
					{
				       
					//highscoreobj.prikaziHighscore();
					_High_Score_Menu();
					radi = true ;
					
					}

				}
                // end HIGHSCORE BUTTON

				// begin QUIT BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_quit_button.x) && ( event.button.x < poz_quit_button.x+ poz_quit_button.w) 
					&& ( event.button.y > poz_quit_button.y ) && (event.button.y < poz_quit_button.y + poz_quit_button.h) )
				      
					return false ;

				}
				
				// end QUIT BUTTON
			}

			if (event.type == SDL_QUIT) return false;


		}
        
		SDL_BlitSurface( introPozadina , NULL , prozor , NULL );

		SDL_BlitSurface( introText , NULL , prozor ,&pozNaslov );

		SDL_BlitSurface( play_button , NULL , prozor , &poz_play_button);
		
		SDL_BlitSurface( options_button , NULL , prozor , &poz_options_button);

		SDL_BlitSurface( quit_button , NULL , prozor, &poz_quit_button );

		SDL_BlitSurface( highscore_button , NULL , prozor , &poz_highscore_button );

		SDL_Flip( prozor );

	}

	return true;




}


void izbornik::prikaziSliku(int x , int y , SDL_Surface *slika , SDL_Surface *podrucje){
	SDL_Rect kord;

	kord.x = x;
	kord.y = y;

	SDL_BlitSurface(slika , NULL  , podrucje , &kord );

}


void izbornik::rectInit(){

	poz_play_button.x = 170;
    poz_play_button.y = 250;
	poz_play_button.h = 50;
	poz_play_button.w = 300;
	
	poz_options_button.x = 170;
	poz_options_button.y = 300;
	poz_options_button.h = 50;
	poz_options_button.w = 300;

	poz_highscore_button.x = 170;
	poz_highscore_button.y = 350;
	poz_highscore_button.h = 50;
	poz_highscore_button.w = 300;
	
	poz_sound_button.x = 170;
	poz_sound_button.y = 150;
	poz_sound_button.h = 50;
	poz_sound_button.w = 300;
	
	poz_music_button.x = 170;
	poz_music_button.y = 200;
	poz_music_button.h = 50;
	poz_music_button.w = 300;
	
	poz_difficulty_button.x = 170;
	poz_difficulty_button.y = 250;
	poz_difficulty_button.h = 50;
	poz_difficulty_button.w = 300;
	
	poz_back_button.x = 10;
	poz_back_button.y = 430;
	poz_back_button.h = 40;
 	poz_back_button.w = 123;
	
	poz_back_button_2.x = (640 / 2 ) - (123 / 2);
	poz_back_button_2.y = 430;
	poz_back_button_2.h = 40;
 	poz_back_button_2.w = 123;

	poz_quit_button.x = 195;
	poz_quit_button.y = 400;
	poz_quit_button.h = 50;
	poz_quit_button.w = 245;

	poz_easy_button.x = 170;
	poz_easy_button.y = 150;
	poz_easy_button.h = 50;
	poz_easy_button.w = 300;

	poz_medium_button.x = 170;
	poz_medium_button.y = 200; 
	poz_medium_button.h = 50;
	poz_medium_button.w = 300;

	poz_hard_button.x = 170;
	poz_hard_button.y = 250;
	poz_hard_button.h = 50;
	poz_hard_button.w = 300;
}
void izbornik::Options(){

	bool radi = true;
	int alpha ; 

	while(radi)
	{
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEMOTION)
			{
                
				
				// begin SOUND BUTTON
				if ( (event.motion.x > poz_sound_button.x) && ( event.motion.x < poz_sound_button.x + poz_sound_button.w) 
					&& ( event.motion.y > poz_sound_button.y ) && (event.motion.y < poz_sound_button.y + poz_sound_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( sound_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha(sound_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
				// end SOUND BUTTON
                
				// begin MUSIC BUTTON
                if ( (event.motion.x > poz_music_button.x) && ( event.motion.x < poz_music_button.x + poz_music_button.w) 
					&& ( event.motion.y > poz_music_button.y ) && (event.motion.y < poz_music_button.y + poz_music_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( music_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha( music_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
				// end MUSIC BUTTON 

				// begin DIFFICULTY BUTTON
                if ( (event.motion.x > poz_difficulty_button.x) && ( event.motion.x < poz_difficulty_button.x + poz_difficulty_button.w) 
					&& ( event.motion.y > poz_difficulty_button.y ) && (event.motion.y < poz_difficulty_button.y + poz_difficulty_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( difficulty_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha( difficulty_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
				// end DIFICULTY BUTTON 

				//begin BACK BUTTON
                if ( (event.motion.x > poz_back_button.x) && ( event.motion.x < poz_back_button.x + poz_back_button.w) 
					&& ( event.motion.y > poz_back_button.y ) && (event.motion.y < poz_back_button.y + poz_back_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( back_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha( back_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
               //end BACK BUTTON

				

			}


            
			if (event.type == SDL_MOUSEBUTTONUP)
			{

				// begin SOUND BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_sound_button.x) && ( event.button.x < poz_sound_button.x + poz_sound_button.w) 
						&& ( event.button.y > poz_sound_button.y ) && (event.button.y < poz_sound_button.y + poz_sound_button.h) )
					{
							if (sound)
							{
								
								sound = false;
								soundString = "OFF";
								
							}
							else
							{
								
								sound = true;
								soundString = "ON";

							}
							
							soundText = TTF_RenderText_Solid( optionsFont , soundString.c_str() , plava );

					}
						
				}
				// end SOUND BUTTON

				// begin MUSIC BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_music_button.x) && ( event.button.x < poz_music_button.x + poz_music_button.w) 
						&& ( event.button.y > poz_music_button.y ) && (event.button.y < poz_music_button.y + poz_music_button.h) )
					{
							if (music)
							{
								
								music = false;
								musicString = "OFF";
								Mix_PauseMusic();
								
							}
							else
							{
								
								music = true;
								musicString = "ON";
								Mix_ResumeMusic();
								if (Mix_PlayingMusic() == 0) Mix_PlayMusic( introMusic , -1 );

							}
							
							musicText = TTF_RenderText_Solid( optionsFont , musicString.c_str() , plava );
					}

				}
				// end MUSIC BUTTON

				// begin DIFFICULTY BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_difficulty_button.x) && ( event.button.x < poz_difficulty_button.x + poz_difficulty_button.w) 
						&& ( event.button.y > poz_difficulty_button.y ) && (event.button.y < poz_difficulty_button.y + poz_difficulty_button.h) )
					{
                            if (difficulty == 1)
							{
								difficulty = 2;
								difficultyString = "MED";
								randomY = 1000 ;
								targetPomakx = 2;
 
                                picajzleX = 5 ;
								picajzleY = 7 ;
							}
							else if (difficulty == 2)
							{
								difficulty = 3;
								difficultyString = "HARD";
								randomY = 500 ;
								targetPomakx = 2;

								picajzleX = 5 ;
								picajzleY = 10 ;
							}
							else
							{
								difficulty = 1;
								difficultyString = "EASY";
								randomY = 2000 ;
								targetPomakx = 1;

								picajzleX = 5 ;
								picajzleY = 6 ;
							}
							
							difficultyText = TTF_RenderText_Solid( optionsFont , difficultyString.c_str() , plava );

					}
				       
			    }
				// end DIFFICULTY BUTTON

				//begin BACK BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_back_button.x) && ( event.button.x < poz_back_button.x + poz_back_button.w) 
					&& ( event.button.y > poz_back_button.y ) && (event.button.y < poz_back_button.y + poz_back_button.h) )
					radi = false;

				}
                //end BACK BUTTON 

			}
			
			if (event.type == SDL_QUIT) radi = false;
			if (event.key.keysym.sym == SDLK_ESCAPE) radi = false;
		}
        
		SDL_BlitSurface( introPozadina , NULL , prozor , NULL );

		SDL_BlitSurface( sound_button , NULL , prozor , &poz_sound_button);
		
		SDL_BlitSurface( music_button , NULL , prozor , &poz_music_button);

		SDL_BlitSurface( difficulty_button , NULL , prozor , &poz_difficulty_button);

		SDL_BlitSurface( back_button , NULL , prozor , &poz_back_button );

		prikaziSliku( 500 , 145 , soundText , prozor);
		prikaziSliku( 500 , 195 , musicText , prozor);
		prikaziSliku( 500 , 245 , difficultyText , prozor);

		

		SDL_Flip( prozor );


	}



}

void izbornik::_High_Score_Menu(){

	bool radi = true ;
	int alpha ;

	while(radi)
	{
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEMOTION)
			{
                // begin EASY BUTTON
				if ( (event.motion.x > poz_easy_button.x) && ( event.motion.x < poz_easy_button.x + poz_easy_button.w) 
					&& ( event.motion.y > poz_easy_button.y ) && (event.motion.y < poz_easy_button.y + poz_easy_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( easy_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha(easy_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
				// end EASY BUTTON

				// begin MEDIUM BUTTON
				if ( (event.motion.x > poz_medium_button.x) && ( event.motion.x < poz_medium_button.x + poz_medium_button.w) 
					&& ( event.motion.y > poz_medium_button.y ) && (event.motion.y < poz_medium_button.y + poz_medium_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( medium_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha(medium_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
				// end MEDIUM BUTTON

				// begin HARD BUTTON
				if ( (event.motion.x > poz_hard_button.x) && ( event.motion.x < poz_hard_button.x + poz_hard_button.w) 
					&& ( event.motion.y > poz_hard_button.y ) && (event.motion.y < poz_hard_button.y + poz_hard_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( hard_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha(hard_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
				// end HARD BUTTON

				//begin BACK BUTTON
                if ( (event.motion.x > poz_back_button.x) && ( event.motion.x < poz_back_button.x + poz_back_button.w) 
					&& ( event.motion.y > poz_back_button.y ) && (event.motion.y < poz_back_button.y + poz_back_button.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( back_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha( back_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
               //end BACK BUTTON

			}

			if (event.type == SDL_MOUSEBUTTONUP)
			{

				// begin EASY BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_easy_button.x) && ( event.button.x < poz_easy_button.x+ poz_easy_button.w) 
						&& ( event.button.y > poz_easy_button.y ) && (event.button.y < poz_easy_button.y + poz_easy_button.h) )
					{
						highscorediff = 1;
						prikaziHighscore();
					}
				}
				// end EASY BUTTON

				// begin MEDIUM BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_medium_button.x) && ( event.button.x < poz_medium_button.x+ poz_medium_button.w) 
						&& ( event.button.y > poz_medium_button.y ) && (event.button.y < poz_medium_button.y + poz_medium_button.h) )
					{
					   highscorediff = 2;
					   prikaziHighscore();
					}
				}
				// end MEDIUM BUTTON

				// begin HARD BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_hard_button.x) && ( event.button.x < poz_hard_button.x+ poz_hard_button.w) 
						&& ( event.button.y > poz_hard_button.y ) && (event.button.y < poz_hard_button.y + poz_hard_button.h) )
					{
					   highscorediff = 3;
					   prikaziHighscore();
					   
					}
				}
				// end HARD BUTTON

				//begin BACK BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_back_button.x) && ( event.button.x < poz_back_button.x + poz_back_button.w) 
					&& ( event.button.y > poz_back_button.y ) && (event.button.y < poz_back_button.y + poz_back_button.h) )
					radi = false;

				}
                //end BACK BUTTON 

			}

		}

		SDL_BlitSurface( introPozadina , NULL , prozor , NULL );

		SDL_BlitSurface( easy_button , NULL , prozor , &poz_easy_button);
		
		SDL_BlitSurface( medium_button , NULL , prozor , &poz_medium_button);

		SDL_BlitSurface( hard_button , NULL , prozor , &poz_hard_button);

		SDL_BlitSurface( back_button , NULL , prozor , &poz_back_button );

		SDL_Flip ( prozor );
	}
	

}

int izbornik::getDifficulty(){

	 return difficulty;

}

bool izbornik::getSound(){

	return sound ;

}

bool izbornik::getMusic(){

	return music ;

}

void izbornik::setMusic(bool muzik){

	music = muzik ;

}

//highscore func.

void izbornik::upisHighscore(){

	bool flag = true  ;

	if (difficulty == 1) datoteka = fopen("hse.bin","rb");
	else if ( difficulty  == 2 ) datoteka = fopen("hsm.bin","rb");
	else datoteka = fopen("hsh.bin","rb");

	vector<Player> Igrac;
	Player ucitaniIgrac , pomocniIgrac;

	for(int i = 0 ; i < 5 ; i++ )
	{
		fread(&ucitaniIgrac , sizeof(Player) , 1 , datoteka );
		Igrac.push_back(ucitaniIgrac);
	}

	pomocniIgrac.ime = upisIme();
    
	
	int i = 0;

	for(vector<Player>::iterator it = Igrac.begin() ; (it < Igrac.end() ) && (flag == true) ; ++i )
	{
		if (Igrac[i].bodovi <= scoreBroj)
		{
			pomocniIgrac.bodovi = scoreBroj ;
			
			Igrac.insert(it , pomocniIgrac );
			it = Igrac.begin();
			flag = false ;
		}
		else ++it ;
		 
	}
    
	fclose(datoteka);
	
    if (difficulty  == 1) datoteka = fopen("hse.bin","w+b");
	else if ( difficulty  == 2 ) datoteka = fopen("hsm.bin","w+b");
	else datoteka = fopen("hsh.bin","w+b");
	
	for(int i = 0 ; i < 5 ; i++ )
	{
		fseek( datoteka , sizeof(Player)*i , SEEK_SET );
		fwrite(&Igrac[i] , sizeof(Player) , 1 , datoteka );
	}

	fclose(datoteka);


}

bool izbornik::isHighscore(){



	if (difficulty  == 1) datoteka = fopen("hse.bin","rb");
	else if ( difficulty  == 2 ) datoteka = fopen("hsm.bin","rb");
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

bool izbornik::handleHighscore(){

	if (isHighscore())
	{
		if ( sound ) Mix_PlayChannel(-1 , newHighscore , 0);
		upisHighscore();
		return true ;
	}
	else return false ;



}

void izbornik::prikaziHighscore(){
    
    SDL_Surface *ispisHighscore ;
	SDL_Rect kord ;

    bool flag = true ;
    int alpha;

	if (highscorediff == 1) datoteka = fopen("hse.bin","rb");
	else if ( highscorediff  == 2 ) datoteka = fopen("hsm.bin","rb");
	else datoteka = fopen("hsh.bin","rb");

	Player Igrac ;
	string ispis ;
    char charBodovi[50];
	char place[50];

	SDL_BlitSurface( introPozadina , NULL , prozor , NULL );

	

	while (flag)
	{
		SDL_BlitSurface( introPozadina , NULL , prozor , NULL );
		
		for(int i = 0 ; i<5 ; i++)
		{
			fseek(datoteka , sizeof(Player)*i , SEEK_SET);
			fread(&Igrac , sizeof(Player) , 1 , datoteka );
		
			sprintf(charBodovi , "%d" , Igrac.bodovi );
			sprintf(place , "%d" , i+1 );
		
			ispis = place[0] + (string)". " + Igrac.ime + (string)" " + charBodovi;
			ispisHighscore = TTF_RenderText_Solid( font2 , ispis.c_str() , bojaTexta );
		
			kord.x = 180 ;
			kord.y = 70 +  70 * i  ;
		
			SDL_BlitSurface( ispisHighscore , NULL , prozor , &kord );
        
		}
	
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEMOTION)
			{
				//begin BACK BUTTON
                if ( (event.motion.x > poz_back_button_2.x) && ( event.motion.x < poz_back_button_2.x + poz_back_button_2.w) 
					&& ( event.motion.y > poz_back_button_2.y ) && (event.motion.y < poz_back_button_2.y + poz_back_button_2.h) )
				{
                       alpha = 150;
				       SDL_SetAlpha( back_button , SDL_SRCALPHA , alpha );
				}
				else
					SDL_SetAlpha( back_button , SDL_SRCALPHA , SDL_ALPHA_OPAQUE );
               //end BACK BUTTON
			}
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				//begin BACK BUTTON
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ( (event.button.x > poz_back_button_2.x) && ( event.button.x < poz_back_button_2.x + poz_back_button_2.w) 
					&& ( event.button.y > poz_back_button_2.y ) && (event.button.y < poz_back_button_2.y + poz_back_button_2.h) )
					flag = false;
					radi = true;

				}
                //end BACK BUTTON 
			}
		}
		
        SDL_BlitSurface( back_button , NULL , prozor , &poz_back_button_2 );
		SDL_Flip(prozor);
	}

	fclose(datoteka);


}

std::string izbornik::upisIme(){

	int slovoCount = 0;
	std::string ime = "" ;
	std::string pamtiIme = ime ;
	std::string _upis_do = "Enter your name: " ;
	std::string _new_h = "NEW HIGHSCORE! " ;
	std::string _enter_do = "Press space to continue";

	 SDL_Rect off , off2 , off3 , off4 ;

		 off.x = 280;
		 off.y = 220;

		 off2.x = 100;
		 off2.y = 150;

		 off3.x = 100;
		 off3.y = 50;

		 off4.x = 200;
		 off4.y = 300;

    bool flag = true ;


	while(flag)
	{
		 while (SDL_PollEvent( &event) ) 
		 {
			 if ( event.type == SDL_KEYDOWN ) 
				 switch ( event.key.keysym.sym)
			 {
				 case SDLK_a : if (slovoCount < 3)
							   {
								   ime += 'A';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_b : if (slovoCount < 3)
							   {
								   ime += 'B';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_c : if (slovoCount < 3)
							   {
								   ime += 'C';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_d : if (slovoCount < 3)
							   {
								   ime += 'D';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_e : if (slovoCount < 3)
							   {
								   ime += 'E';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_f : if (slovoCount < 3)
							   {
								   ime += 'F';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_g : if (slovoCount < 3)
							   {
								   ime += 'G';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_h : if (slovoCount < 3)
							   {
								   ime += 'H';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_i : if (slovoCount < 3)
							   {
								   ime += 'I';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_j : if (slovoCount < 3)
							   {
								   ime += 'J';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_k : if (slovoCount < 3)
							   {
								   ime += 'K';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_l : if (slovoCount < 3)
							   {
								   ime += 'L';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_m : if (slovoCount < 3)
							   {
								   ime += 'M';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_n : if (slovoCount < 3)
							   {
								   ime += 'N';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_o : if (slovoCount < 3)
							   {
								   ime += 'O';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_p : if (slovoCount < 3)
							   {
								   ime += 'P';
					               ++slovoCount;
							   }
							   break ;
			     
				 case SDLK_q : if (slovoCount < 3)
							   {
								   ime += 'Q';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_r : if (slovoCount < 3)
							   {
								   ime += 'R';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_s : if (slovoCount < 3)
							   {
								   ime += 'S';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_t : if (slovoCount < 3)
							   {
								   ime += 'T';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_u : if (slovoCount < 3)
							   {
								   ime += 'U';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_v : if (slovoCount < 3)
							   {
								   ime += 'V';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_w : if (slovoCount < 3)
							   {
								   ime += 'W';
					               ++slovoCount;
							   }
							   break ;

				 case SDLK_x : if (slovoCount < 3)
							   {
								   ime += 'X';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_y : if (slovoCount < 3)
							   {
								   ime += 'Y';
					               ++slovoCount;
							   }
							   break ;

			     case SDLK_z : if (slovoCount < 3)
							   {
								   ime += 'Z';
					               ++slovoCount;
							   }
							   break ;

				 case SDLK_SPACE : if (slovoCount == 3) flag = false ; break;

				 case SDLK_BACKSPACE : {
					                   --slovoCount;
					                   pamtiIme = "";
					                   for(int i = 0 ; i < ime.length()-1 ; ++i)
									   {
										   pamtiIme += ime[i] ;
									   }
									   ime = pamtiIme ;
									   }

									   break ;

			 }
		 }

		

		 SDL_BlitSurface( introPozadina , NULL , prozor , NULL );
		 SDL_BlitSurface(TTF_RenderText_Solid( font2 , _new_h.c_str() , plava ) , NULL , prozor , &off3);
		 SDL_BlitSurface(TTF_RenderText_Solid( font2 , _upis_do.c_str() ,plava ) , NULL , prozor , &off2);
		 SDL_BlitSurface(TTF_RenderText_Solid( font2 , ime.c_str() , bojaTexta ) , NULL , prozor , &off);
		 if (slovoCount == 3) SDL_BlitSurface(TTF_RenderText_Solid( font , _enter_do.c_str() , plava ) , NULL , prozor , &off4);
		 SDL_Flip(prozor);
	}

	return ime ;

}
	
