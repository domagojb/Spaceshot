#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "globalneVar.h"
#include "konstante.h"
#include "spaceship.h"
#include "target.h"
#include "weapon.h"
#include "timer.h"
#include <vector>
#include <time.h>
#include "izbornik.h"





using namespace std;

bool sudar(SDL_Rect kord1 , SDL_Rect kord2){
		int gornja1 , gornja2 ;
		int lijeva1 , lijeva2 ;
		int desna1 , desna2 ;
		int donja1 , donja2 ;

		gornja2 = kord1.y ;
		lijeva2 = kord1.x ;
		desna2 = kord1.x + kord1.w ;
		donja2 = kord1.y + kord1.h ;

		gornja1 = kord2.y ;
		lijeva1 = kord2.x ;
		desna1 = kord2.x + kord2.w ;
		donja1 = kord2.y + kord2.h ;

		if( donja1 <= gornja2 )
            return false;
        
    
        if( gornja1 >= donja2 )
            return false;
        
    
        if( desna1 <= lijeva2 )
            return false;
        
    
        if( lijeva1 >= desna2 )
            return false;
        
    
    
        return true;

	}    


bool sudarProzor(SDL_Rect kord , bool ulaz ){

	if (ulaz)
	{

		if (kord.x < REZOLUCIJA_S - SIRINA_TARGETA) return false ;
		else return true;
	}

	else
	{

		if (kord.x > 0 ) return false;
		else return true ;

	}

	

}
bool sudarKraj(SDL_Rect kord){

	if ( (kord.y + kord.h)  >= 400 ) return true;
	
	
	return false;

}






SDL_Surface *ucitavanjeSlike(string imeDatoteke){

	SDL_Surface *ucitanaSlika = NULL ;
    SDL_Surface *optimiziranaSlika = NULL ;

	ucitanaSlika = IMG_Load( imeDatoteke.c_str() ) ;

	optimiziranaSlika = SDL_DisplayFormat ( ucitanaSlika );
	Uint32 colorkey = SDL_MapRGB( optimiziranaSlika->format,255,255, 255 );
	SDL_SetColorKey( optimiziranaSlika, SDL_SRCCOLORKEY, colorkey );

	SDL_FreeSurface( ucitanaSlika );

	return optimiziranaSlika;

}


void initSve(){

	SDL_Init(SDL_INIT_EVERYTHING);

	prozor = SDL_SetVideoMode(REZOLUCIJA_S , REZOLUCIJA_V , BPP , SDL_SWSURFACE);

	SDL_WM_SetCaption("SpaceShot","Grafika/introPozadina.jpg");

	TTF_Init();

	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

}

void ucitajSve(){

	brod =               ucitavanjeSlike( "Grafika/Spaceship4.png"    );
    wepn =               ucitavanjeSlike( "Grafika/wepn2.png"         );
	targetWepn =         ucitavanjeSlike( "Grafika/wepn1.png"         );
	pozadina =           ucitavanjeSlike( "Grafika/space.png"         );
	introPozadina =      ucitavanjeSlike( "Grafika/Intropozadina.jpg" );
	targetp =            ucitavanjeSlike( "Grafika/spritetarget.png"  );
	
	font =               TTF_OpenFont( "Font/BAUHS93.TTF" , 25 );
	font2 =              TTF_OpenFont( "Font/BAUHS93.TTF" , 60 );
	optionsFont =        TTF_OpenFont( "Font/BAUHS93.TTF" , 50 );
	
	gameMusic =          Mix_LoadMUS( "Music/Gamemusic2.mp3" );
	shot =               Mix_LoadWAV( "Music/Shot.wav"       );
	killTarget =         Mix_LoadWAV( "Music/killTarget.wav" );
	startPlay =          Mix_LoadWAV( "Music/Start.wav"      );
	Gameover =           Mix_LoadWAV( "Music/Gameover.wav"   );
	abouttoshot =        Mix_LoadWAV( "Music/abouttoshot.wav"   );
	bshot =              Mix_LoadWAV( "Music/bshot.wav"   );
	introMusic =         Mix_LoadMUS( "Music/intromusic.mp3" );
	newHighscore =       Mix_LoadWAV( "Music/newHighscore.wav" );
	
	play_button =         ucitavanjeSlike( "Grafika/Buttons/b1.png"  );
	options_button =      ucitavanjeSlike( "Grafika/Buttons/b2.png"  );
	music_button =        ucitavanjeSlike( "Grafika/Buttons/b3.png"  );
	difficulty_button =   ucitavanjeSlike( "Grafika/Buttons/b4.png"  );
	sound_button =        ucitavanjeSlike( "Grafika/Buttons/b5.png"  );
	back_button =         ucitavanjeSlike( "Grafika/Buttons/b10.png" );
	quit_button =         ucitavanjeSlike( "Grafika/Buttons/b11.png" );
	highscore_button =    ucitavanjeSlike( "Grafika/Buttons/b12.png" );
	easy_button =         ucitavanjeSlike( "Grafika/Buttons/b7.png" );
	medium_button =       ucitavanjeSlike( "Grafika/Buttons/b8.png" );
	hard_button =         ucitavanjeSlike( "Grafika/Buttons/b9.png" );
	
	
}




void prikaziSliku(int x , int y , SDL_Surface *slika , SDL_Surface *podrucje)
{

	SDL_Rect kord;

	kord.x = x;
	kord.y = y;

	SDL_BlitSurface(slika , NULL  , podrucje , &kord );

}

void zatvoriSve()
{
    
	SDL_FreeSurface( brod );
	SDL_FreeSurface( wepn );
	SDL_FreeSurface( targetWepn );
	SDL_FreeSurface( pozadina );
	SDL_FreeSurface( introPozadina );
	SDL_FreeSurface( introText );
	SDL_FreeSurface( targetp );
	SDL_FreeSurface( score );
	SDL_FreeSurface( soundText );
	SDL_FreeSurface( musicText );
	SDL_FreeSurface( difficultyText );
	SDL_FreeSurface( startText );
	SDL_FreeSurface( play_button );
	SDL_FreeSurface( options_button );
	SDL_FreeSurface( music_button );
	SDL_FreeSurface( sound_button );
	SDL_FreeSurface( difficulty_button );
    SDL_FreeSurface( back_button );
	SDL_FreeSurface( quit_button );
	SDL_FreeSurface( highscore_button );
	SDL_FreeSurface( easy_button );
	SDL_FreeSurface( medium_button );
	SDL_FreeSurface( hard_button );
	
	TTF_CloseFont( font );
	TTF_CloseFont( font2 );
	
	Mix_FreeChunk( killTarget );
    Mix_FreeChunk( shot );
    Mix_FreeChunk( startPlay );
	Mix_FreeChunk( Gameover );
	Mix_FreeChunk( newHighscore );
	Mix_FreeChunk( bshot );
	Mix_FreeChunk( abouttoshot );
    Mix_FreeMusic( gameMusic );
	Mix_FreeMusic( introMusic );

}




void krajPrikaz(izbornik meni){

	bool radi = true;

	Mix_HaltMusic();

	

	if(!meni.handleHighscore())
	{
		if ( meni.getSound() ) Mix_PlayChannel(-1 ,Gameover , 0);
		
		while (radi)
		{
			
			SDL_BlitSurface(pozadina,NULL,prozor,NULL);
		
			kraj = TTF_RenderText_Solid ( font2 , "Game over!" , bojaTexta );
			prikaziSliku(180 , 180 , kraj ,prozor);
       
			kraj = TTF_RenderText_Solid ( font , "Press ESC to return to menu!" , bojaTexta );
			prikaziSliku(175 , 240 , kraj ,prozor);
		
			prikaziSliku(260,290,score,prozor);

			while (SDL_PollEvent(&event))
			{

			
				if ( event.type == SDL_QUIT ) radi = false;

			
				if ( event.type == SDL_KEYDOWN ) 
				
					switch ( event.key.keysym.sym )
					   case SDLK_ESCAPE: radi = false ; break;
			}
	

		    SDL_Flip (prozor);
		
		}

	}

	

}






void pause(izbornik meni){

	int i = 1 ;

	SDL_Rect podrucje ;

	podrucje.x = 170 ;
	podrucje.y = 0 ;

	if ( !Mix_PausedMusic() ) Mix_PauseMusic();

	while(i == 1){
		SDL_BlitSurface ( TTF_RenderText_Solid( font2 , " @PAUSED " , bojaTexta ) , NULL , prozor , &podrucje ) ;
		SDL_Flip (prozor);
         
        while (SDL_PollEvent( &event) )
		{

		     if ( event.type == SDL_KEYDOWN ) 

				  switch ( event.key.keysym.sym)
			 {

					     case SDLK_p : i = 0;
		     }
		}

	}

	if (meni.getMusic()) Mix_ResumeMusic();



	
}

void mainLoop(izbornik meni, bool *izlaz , bool *flag){

	bool radi = true ;
    bool targetLaser ;
	
	int randomX;
	bool glazba = false;
	bool Paused = false;

	

	Timer fps ;
	Spaceship myShip;
	Weapon laser;
	

	// GLOBALNE BEGIN

	scoreBroj =  0 ;
    levelBroj = 0 ;
    livesBroj = 3 ;
	brojTarget = 0;
    
	if ( meni.getDifficulty() == 1 )
	{
		randomY = 2000;
		targetPomakx = 1;
	} 
	else if ( meni.getDifficulty() == 2 )
	{
		randomY = 1000 ;
	    targetPomakx = 2;
	} 
	else 
	{
		randomY = 500 ;
	    targetPomakx = 2;
	}
	// GLOBALNE END
	
	

	// Random pucanje			
	srand( (unsigned)time(NULL) );

	radi = true;

	while (radi)
	{

		// NOVI LEVEL BEGIN
		if (brojTarget == 0 || ponoviLevel == true)
		{
 
			for ( int i=0 ; i<picajzleX ; ++i )
				for ( int j=0 ; j<picajzleY ; ++j )
				{
					
					if ( i==0 && j==0 ) aliens[i][j] = Target() ;
					else if ( j==0 ) aliens[i][j] = Target(i);
			        else aliens[i][j] = Target( aliens[i][j-1].getKord() );
			        
				}

				if ( Mix_PlayingMusic() == 1 ) Mix_PauseMusic();
				glazba = false;

				if ( !meni.getMusic() )
				{
					Mix_PauseMusic();
					Paused = true ;
				}
				else Paused = false ;
                
				if ( ponoviLevel )
				{
					
					ponoviLevel = false ;
					
					if (levelBroj == 1) scoreBroj  = 0;
					else scoreBroj /= 2 ;

				}
				else
				{
					levelBroj += 1 ;
					if (randomY>100) randomY /= 2;
					
				}

				if ( meni.getDifficulty() == 1 ) brojTarget = 30;
				else if( meni.getDifficulty() == 2 ) brojTarget = 35 ;
				else brojTarget = 50;

				

				if (levelBroj == 5 )
				{
					if ( meni.getDifficulty() == 1 ) targetPomakx = 2;
					else targetPomakx = 3;
				}

				if (levelBroj == 10)
				{

					randomY = 10 ;
					if ( meni.getDifficulty() == 1 ) targetPomakx = 3 ;
					else if ( meni.getDifficulty() == 2 ) targetPomakx = 4;
					else targetPomakx = 5;
				}
                // inicijalizacija normalnog levela
				if (levelBroj<10)
				{
					
					SDL_BlitSurface(pozadina,NULL,prozor,NULL);
				
				    sprintf(scoreChar, "%d" , scoreBroj);
		            scoreString = (string)"POINTS ";
		            scoreString +=  scoreChar;
		            score = TTF_RenderText_Solid ( font , scoreString.c_str() , bojaTexta );
				    prikaziSliku( 250 , 250 , score , prozor );

				    sprintf(levelChar, "%d" , levelBroj);
		            levelString = (string)"Level ";
		            levelString +=  levelChar;
		            level = TTF_RenderText_Solid ( font2 , levelString.c_str() , bojaTexta );
		            prikaziSliku( 220, 180 , level , prozor );

					sprintf(livesChar, "%d" , livesBroj);
					livesString = (string)"LIVES LEFT ";
		            livesString +=  livesChar;
		            lives = TTF_RenderText_Solid ( font , livesString.c_str() , bojaTexta );
		            prikaziSliku( 250 , 280 , lives , prozor );

				
				
				}


				//insane level
			    if (levelBroj==10)
				{
					SDL_BlitSurface(pozadina,NULL,prozor,NULL);
				
				    sprintf(scoreChar, "%d" , scoreBroj);
		            scoreString = (string)"POINTS ";
		            scoreString +=  scoreChar;
		            score = TTF_RenderText_Solid ( font , scoreString.c_str() , crvena );
				    prikaziSliku( 250 , 250 , score , prozor );

				    sprintf(levelChar, "%d" , levelBroj);
		            levelString = (string)" INSANE LEVEL ";
		            level = TTF_RenderText_Solid ( font2 , levelString.c_str() , crvena );
		            prikaziSliku( 140, 180 , level , prozor );

				    sprintf(livesChar, "%d" , livesBroj);
					livesString = (string)"LIVES LEFT ";
		            livesString +=  livesChar;
		            lives = TTF_RenderText_Solid ( font , livesString.c_str() , crvena );
		            prikaziSliku( 250 , 280 , lives , prozor );


				}
				
				SDL_Flip ( prozor );
			    SDL_Delay(4000);

			
		
		}
        // NOVI LEVEL END


		if (livesBroj > 0 && levelBroj < 11)
		{

			if (!glazba)
			{
			   if ( Mix_PausedMusic() == 1 && (!Paused) )
				   Mix_ResumeMusic();
			   else
			   if (!Paused) Mix_PlayMusic( gameMusic , -1 );
			   glazba = true ;
			}
        
		
			
	    // pocetak frame-a  
		fps.start();
		  
		  //ulaz tipkovnice
		  while (SDL_PollEvent( &event) )
		  {

			myShip.ulazTipkovnice();

			if ( event.type == SDL_QUIT)
			{
				
				radi = false ;
				*izlaz = true ;
				*flag = false;
			}

			if ( event.type == SDL_KEYDOWN ) 
				switch ( event.key.keysym.sym)
			{

					case SDLK_SPACE : if ( !laser.alive() )
									  {

						                    laser.setXY( myShip.getX(),myShip.getY() );
											if ( meni.getSound() ) Mix_PlayChannel( -1, shot , 0 );
									        
									  }
									  break;
					case SDLK_ESCAPE : radi = false;
						               *izlaz = true;
						               break;

					case SDLK_p : pause(meni);
						              break;

					
								   
                                    
				}

		  }

	    //provjera za shoot targeta
        for ( int i=0; i<picajzleX ; ++i  )
			for ( int j=0; j<picajzleY ; ++j)
			{
				targetLaser = true;
				if ( aliens[i][j].alive() )
					
					if (i < 4)
					{
						for ( int b=i+1; b<picajzleX ; ++b )
							if ( aliens[b][j].alive() ) targetLaser = false;
					}
				
					if ( targetLaser && aliens[i][j].alive() )
					{
					    randomX = rand() % randomY;
				        if (randomX == 3)
						{
							if ( !aliens[i][j].laserAlive() ) aliens[i][j].setLaser();
						}
					}
			} 

	    // pomicanje svega 
		myShip.pomak();
		laser.Pomak();	

		
		for ( int i=0; i<picajzleX ; ++i  )
			for ( int j=0; j<picajzleY ; ++j)
			{
				aliens[i][j].Pomak(desno);
				if ( aliens[i][j].laserAlive() ) aliens[i][j].laserPomak();
			}

		// provjera sudara lasera i targeta
		if (laser.alive() )
		{
			for (int i=0; i<picajzleX; i++)
			 for ( int j=0; j<picajzleY ; j++)
			 {
				 if (aliens[i][j].alive() )
			     {
					if ( sudar( laser.getKord() , aliens[i][j].getKord() ) )
					{
						aliens[i][j].setDeadhp();
						laser.setSudar();
						--brojTarget;
						scoreBroj += 10;
						if ( meni.getSound() ) Mix_PlayChannel( -1, killTarget, 0 );
					}
			     }
			} 
		}

		//sudar targetlasera i broda
		for ( int i=0; i<picajzleX ; ++i  )
			for ( int j=0; j<picajzleY ; ++j)
				if ( sudar(aliens[i][j].getLaserkord() ,myShip.getKord()  ) )
				{
					--livesBroj ;
					if (livesBroj>0) ponoviLevel = true;
					else radi = false;
					if ( meni.getSound() ) Mix_PlayChannel( -1, killTarget, 0 );
				}

        
		//Sudar targeta sa rubovima 
		for ( int i=0; i<picajzleX ; ++i  )
			for ( int j=0; j<picajzleY ; ++j)
				if ( aliens[i][j].alive() && sudarProzor ( aliens[i][j].getKord() , desno ) ) 
				{
						if (desno) desno = false;
						else desno = true;
						
						for ( int i=0; i<picajzleX ; ++i  )
							for ( int j=0; j<picajzleY ; ++j)
							{
								aliens[i][j].setY();
						    }
				}

		//Prijelaz iz ekrana 
		for (int i=0; i<picajzleX; i++)
		{
			 if (ponoviLevel) break;
			 for ( int j=0; j<picajzleY ; j++)
			 {
				 if (ponoviLevel) break;
				 if (aliens[i][j].alive() )
			     {
					 if (aliens[i][j].getKord().y + aliens[i][j].getKord().h > 400)
					 {
						 --livesBroj ;
						 if (livesBroj>0)
						 {
							 ponoviLevel = true;
						 }
					     else radi = false;
					     if ( meni.getSound() ) Mix_PlayChannel( -1, killTarget, 0 );
					 }
				 }
			 }
		}

			
		
        
		//Prikaz svega
		
		SDL_BlitSurface(pozadina,NULL,prozor,NULL);
        
		// prikaz bodova
		sprintf(scoreChar, "%d" , scoreBroj);
		scoreString = (string)"Points ";
		scoreString +=  scoreChar;
		score = TTF_RenderText_Solid ( font ,scoreString.c_str() , bojaTexta );
		prikaziSliku( 0 , 450 , score , prozor );

		//prikaz levela
        sprintf(levelChar, "%d" , levelBroj);
		levelString = (string)"Level ";
		levelString +=  levelChar;
		level = TTF_RenderText_Solid ( font ,levelString.c_str() , bojaTexta );
		prikaziSliku( 550 , 450 , level , prozor );

		myShip.prikaz();
		
		if (laser.alive()) laser.prikaz();
		
		for (int i=0 ; i<picajzleX ; i++ )
		{
			for (int j=0 ; j<picajzleY ; j++)
			{
				if ( aliens[i][j].alive() ) aliens[i][j].Prikaz();
				if ( aliens[i][j].laserAlive() ) aliens[i][j].laserPrikaz();
			}
		}
		
        SDL_Flip ( prozor ) ;
		

		// provjera FPS 
		if ( fps.getVrijeme() < (1000/FPS) )
		{
			
			SDL_Delay( (1000/FPS)-fps.getVrijeme());

		}

        }
		
		//ako nije preostalo zivota
        else radi = false;
	}
}
int main(int argc, char* argv[]){
    
    initSve();
    ucitajSve();

	SDL_WM_SetIcon( introPozadina , NULL );
	
    bool flag = true;
	izbornik meni;
	bool izlaz = false ;
	bool raniIzlaz = false;


    // HIGHSCORE INIT
	struct Player
	{
		int bodovi ;
		string ime ;
	};
	Player igrac ;
	igrac.bodovi = 000;
	igrac.ime = "NUL" ;

	FILE *datoteka ;

	datoteka = fopen("hse.bin","w+b");

	for( int i = 0; i<5 ; ++i )
	{
		fwrite(&igrac , sizeof(Player) , 1 , datoteka);
	}
	fclose(datoteka);

	datoteka = fopen("hsm.bin","w+b");

	for( int i = 0; i<5 ; ++i )
	{
		fwrite(&igrac , sizeof(Player) , 1 , datoteka);
	}
	fclose(datoteka);

	datoteka = fopen("hsh.bin","w+b");

	for( int i = 0; i<5 ; ++i )
	{
		fwrite(&igrac , sizeof(Player) , 1 , datoteka);
	}
	fclose(datoteka);
	// HIGHSCORE INIT END  

	
    // game loop BEGIN
	while ( flag )
	{	
			
		izlaz = false ;
    
	        if (meni.pocetakPrikaz())
			{
				
				if ( meni.getSound() ) Mix_PlayChannel( -1, startPlay, 0 );
		
				mainLoop(meni , &izlaz , &flag);

			}

	       else 
		   {

			   raniIzlaz = true;
		       flag = false ;

		   }

	       if (!izlaz && !raniIzlaz) krajPrikaz(meni);

	}

	// game loop END 
    
    
	zatvoriSve();
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();

	return 0 ;

}
	
