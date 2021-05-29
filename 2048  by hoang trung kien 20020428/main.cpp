#include "load_everything.cpp"
#include "graphic.cpp"
#include "logic.cpp"
#include "game_play.cpp"


using namespace std;
int main( int argc, char* argv[] )
{
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
gamewin.loadFromFile("gamewin.png");
 menu_button_play.loadFromFile("menu_button_play.png");
 menu_button_exit.loadFromFile("menu_button_exit.png");
		    bool game=true;
		    loadmenu();
		    SDL_Event event;

		    SDL_SetRenderDrawColor(gRenderer,0XFF,0XFF,0XFF,0XFF);
		    SDL_RenderClear(gRenderer);

		    gamemenu.render(0,0);
		    SDL_RenderPresent(gRenderer);
		    while (game)
		   {

		    while (SDL_PollEvent(&event)!=0)
            {
if(event.type==SDL_QUIT)
{
    game=false;
}

             else if(event.type==SDL_MOUSEMOTION)
                {
                    if(event.button.y>320&&event.button.y<422&&event.button.x>250&&event.button.x<640)
                       {
                          SDL_SetRenderDrawColor(gRenderer,0XFF,0XFF,0XFF,0XFF);
                          SDL_RenderClear(gRenderer);
                          menu_button_play.render(0,0);
                          SDL_RenderPresent(gRenderer);
                       }

                      else if (event.button.x>252&&event.button.x<650&&event.button.y<581&&event.button.y>480)
                       {
                           SDL_SetRenderDrawColor(gRenderer,0XFF,0XFF,0XFF,0XFF);
                           SDL_RenderClear(gRenderer);
                           menu_button_exit.render(0,0);
                           SDL_RenderPresent(gRenderer);
                       }
                       else{
                        SDL_SetRenderDrawColor(gRenderer,0XFF,0XFF,0XFF,0XFF);
                          SDL_RenderClear(gRenderer);
                          gamemenu.render(0,0);
                          SDL_RenderPresent(gRenderer);
                       }

                }
                else if (event.type==SDL_MOUSEBUTTONUP)
                {
                    if (event.button.y>320&&event.button.y<422&&event.button.x>250&&event.button.x<640)
                    {
                        gameplay();
                        game=false;
                    }
                    else if(event.button.x>252&&event.button.x<650&&event.button.y<581&&event.button.y>480)
                    {
                        game=false;
                        close();
                    }
                }

            }
		   }
}
	close();

	}

	return 0;
	}

