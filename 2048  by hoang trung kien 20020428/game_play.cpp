#include "game_play.h"
void savescore(int &score)
{
   std::ifstream input("score.txt");
    int bestscore;
    input>>bestscore;
    std::ofstream output("score.txt");
    if (score>bestscore)
    {
        output<<score;
    }
    else {
        output<<bestscore;
    }
    input.close();
    output.close();
}
void gameplay()
{deptrai:



display();
 Mix_PlayMusic(gMusic,-1);
deptraiz:
     bool check_=true;
bool check=true;
    	bool a2048=true;
bool QUIT=false;
		    while (!QUIT){
		    while (a2048){
		    load_number();
		    loadscore();
			bool quit = false;
			SDL_Event e;
			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if(e.type==SDL_QUIT)
                    {
                        quit=true;
                        a2048=false;
                         QUIT=true;
                    }



					else if (e.type==SDL_KEYUP)
                   {
if (e.key.keysym.sym==SDLK_ESCAPE)
{
                        quit=true;
                        a2048=false;
                         QUIT=true;
}
                        if (e.key.keysym.sym==SDLK_RIGHT||e.key.keysym.sym==SDLK_d)
                        {
                            moveright();
                       quit =true;
                        }
                        if (e.key.keysym.sym==SDLK_LEFT||e.key.keysym.sym==SDLK_a)
                        {
                            moveleft();
                            quit=true;

                        }
                        if (e.key.keysym.sym==SDLK_DOWN||e.key.keysym.sym==SDLK_s)
                           {
                            movedown();
                        quit =true;}
                        if (e.key.keysym.sym==SDLK_UP||e.key.keysym.sym==SDLK_w)
                        {
                            moveup();
                            quit=true;
                        }

           }
           else if(e.type==SDL_MOUSEBUTTONUP)
           {
               if (e.button.x<770&&e.button.x>700&&e.button.y>121&&e.button.y<200)
               {if (Mix_PlayingMusic()==0)
                            {
                                Mix_PlayMusic(gMusic,-1);
                       }else{ if(Mix_PausedMusic()==1)
                       {
                           Mix_ResumeMusic();
                       }
                       else Mix_PauseMusic();
               }}
               else if (e.button.x<875&&e.button.x>800&&e.button.y>10&&e.button.y<85){
                   for(int i=0;i<4;i++)
                {
                    for (int j=0;j<4;j++)
                        board[i][j]=0;
                }
                score=0;
//                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
//                    SDL_RenderClear(gRenderer);

goto deptrai;
               }
               else if (e.button.x<775&&e.button.x>700&&e.button.y>10&&e.button.y<85){
        //        board[4][4]=copy_board[4][4];
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                board[i][j]=copy_board[i][j];
            }
        }
               score=lastscore;
               goto deptraiz;

               }
           }
				}
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
gBackgroundTexture.render( 0, 0 );
for (int i=0;i<4;i++)
    for(int j=0;j<4;j++)
{
   gFooTexture[i][j].render((i+1)*100,(j+1)*100);
}
Drawscore.render(230,33);
Drawhighscore.render(323,551);
				//Update screen
				SDL_RenderPresent( gRenderer );
//SDL_Delay(35);
SDL_RenderClear(gRenderer);

if (check_over()==1)
{
    savescore(score);
     bool gm=true;
//     int sc;
//     hscore>>sc;
//     if (sc<score)
//     {hscore<<score;
//     hscore.close();
//            }
    while (gm)
    {
        while(SDL_PollEvent(&e)!=0)
        {
           if(e.type==SDL_QUIT)
           {
               gm=false;
           }
           SDL_RenderClear(gRenderer);
           ggameover.render(0,0);
           Drawscore.render(370,280);
           SDL_RenderPresent(gRenderer);

           if (e.type==SDL_MOUSEBUTTONUP){
            if(e.button.x<700&&e.button.x>200&&e.button.y<500&&e.button.y>350)
            {
                for(int i=0;i<4;i++)
                {
                    for (int j=0;j<4;j++)
                        board[i][j]=0;
                }
                score=0;
goto deptrai;
               // gm=false;
            }
            else if (e.button.x<700&&e.button.x>200&&e.button.y<700&&e.button.y>600){
                gm=false;
            }
           }
        }
    }


 quit=true;
 a2048=false;
 QUIT=true;

}
if (check_win()==1)
{
 bool gmww=true;
    while (gmww)
    {
        while(SDL_PollEvent(&e)!=0)
        {
           if(e.type==SDL_QUIT)
           {
               gmww=false;
           }
           SDL_RenderClear(gRenderer);
           gamewin.render(0,0);
           SDL_RenderPresent(gRenderer);
           if (e.type==SDL_MOUSEBUTTONUP){
            if(e.button.x<700&&e.button.x>200&&e.button.y<500&&e.button.y>350)
            {
                for(int i=0;i<4;i++)
                {
                    for (int j=0;j<4;j++)
                        board[i][j]=0;
                }
                score=0;
goto deptrai;
               // gm=false;
            }
            else if (e.button.x<700&&e.button.x>200&&e.button.y<700&&e.button.y>600){
                gmww=false;
            }
           }
        }
    }


 quit=true;
 a2048=false;
 QUIT=true;

}


			}

		}


	}



}
