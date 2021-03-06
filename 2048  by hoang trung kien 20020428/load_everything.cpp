#include "load_everything.h"
#include"game_play.h"

void loadscore()
{
    ghighscore();
    std::string scorestring=std::to_string(score);
std::string highscorestring=std::to_string(highscore);
    SDL_Color textcolor={0,0,100};
    gFont =TTF_OpenFont("lazy.ttf",40);
    Drawscore.loadFromRenderedText(scorestring,textcolor);
    Drawhighscore.loadFromRenderedText(highscorestring,textcolor);

}



void loadmenu()
{
    if (!gamemenu.loadFromFile("menu.png"))
    printf("failed to load menu image!\n");

}

void load_number()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        { if (board[i][j]==0)
        {
            if (!gFooTexture[i][j].loadFromFile("0.png"))
            {
                printf("failed to load image \n");
            }
        }
            if(board[i][j]==2)
            {
                if (!gFooTexture[i][j].loadFromFile("2.png"))
                {
                    printf("failed to load image\n");
                }
            }
            if(board[i][j]==4)
            {
                if (!gFooTexture[i][j].loadFromFile("4.png"))
                {
                    printf("failed to load image\n");
                }
            }
            if(board[i][j]==8)
            {
                if (!gFooTexture[i][j].loadFromFile("8.png"))
                {
                    printf("failed to load image\n");
                }
            }if(board[i][j]==16)
            {
                if (!gFooTexture[i][j].loadFromFile("16.png"))
                {
                    printf("failed to load image\n");
                }
            }if(board[i][j]==32)
            {
                if (!gFooTexture[i][j].loadFromFile("32.png"))
                {
                    printf("failed to load image\n");
                }
            }if(board[i][j]==64)
            {
                if (!gFooTexture[i][j].loadFromFile("64.png"))
                {
                    printf("failed to load image\n");
                }
            }if(board[i][j]==128)
            {
                if (!gFooTexture[i][j].loadFromFile("128.png"))
                {
                    printf("failed to load image\n");
                }
            }if(board[i][j]==256)
            {
                if (!gFooTexture[i][j].loadFromFile("256.png"))
                {
                    printf("failed to load image\n");
                }
            }if(board[i][j]==512)
            {
                if (!gFooTexture[i][j].loadFromFile("512.png"))
                {
                    printf("failed to load image\n");
                }
            }if(board[i][j]==1024)
            {
                if (!gFooTexture[i][j].loadFromFile("1024.png"))
                {
                    printf("failed to load image\n");
                }
            }
            if(board[i][j]==2048)
            {
                if (!gFooTexture[i][j].loadFromFile("2048.png"))
                {
                    printf("failed to load image\n");
                }
            }
        }
    }
}

