#include "logic.h"
bool check_win()
{
    bool check=false;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (board[i][j]==MAX)
               {
                   score+=1000;
                check=true;
                break;}

        }
    }
    return check;
}
bool check_over()
{
    bool check=true;
    for(int i=0;i<4;i++){
            for (int j=0;j<3;j++)
            {
                if (board[i][j]==0||board[i][j+1]==0||board[i][j]==board[i][j+1]){
                    check=false;
               break;}
            }
    }
            for(int j=0;j<4;j++){
            for (int i=0;i<3;i++)
            {
                if (board[i][j]==0||board[i+1][j]==0||board[i][j]==board[i+1][j]){
                    check=false;
                    break;
                }


            }
    }
    return check;
}
void display()
{
    int i1,i2,j1,j2;
    while (true){
    i1=rand()%4;
    i2=rand()%4;
    j1=rand()%4;
    j2=rand()%4;
        if (i1==j1&&i2==j2)
            continue;
        else
            break;
    }
    board [i1][i2]=2;
    board [j1][j2]=2;
}
void board_copy()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++){
            copy_board[i][j]=board[i][j];
        }
    }
}
bool check_board_copy()
{
    bool check=1;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (board[i][j]!=copy_board[i][j])
               {

                check=0;
break;
               }


        }
    }
    return check;
}
bool check()
{bool check=true;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++){
            if (board[i][j]==0){
                check=false;
            }
        }
    }
    return check;
}
void add_random()
{
    int i1,i2;
if (!check()){
    while(true)
    {

        i1=rand()%4;
        i2=rand()%4;
        if (board[i1][i2]!=0)
            continue;
        else
            break;
    }
    int a=rand()%4;
    switch(a)
    {
    case 0:
    case 1:
    case 2:


    board[i1][i2]=2;
    break;
    case 3:
        board[i1][i2]=4;
        break;}
    }
}

void moveleft()
{
board_copy();
    for(int i=0;i<4;i++){

    for(int j=0;j<4;j++)
    {
        if(!board[j][i])
        {
    for(int k=j+1;k<4;k++)
    if(board[k][i])
{
    board[j][i]=board[k][i];
    board[k][i]=0;

break;
}
}
}
}
for(int i=0;i<4;i++)
{
    for (int j=0;j<3;j++)
    {
        if (board[j][i]==board[j+1][i])
        {
            board[j][i]+=board[j+1][i];
            board[j+1][i]=0;
            lastscore=score;
            score+=board[j][i]/2;

        }
    }
}
	for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
        if(!board[j][i])
        {
    for(int k=j+1;k<4;k++)
    if(board[k][i])
{
    board[j][i]=board[k][i];
    board[k][i]=0;

break;
}
}
}
if(check_board_copy()==0)
                add_random();
}
void moveright()
{board_copy();
    for(int i=0;i<4;i++)
    {
        for (int j=3;j>=0;j--)
        {
            if(!board[j][i])
            {
                for (int k=j-1;k>=0;k--)
                {
                    if(board[k][i])
                    {
                        board[j][i]=board[k][i];
                        board[k][i]=0;
                        lastscore=score;
                        score+=board[j][i]/2;
                    break;
                    }
                }
            }
        }
    }
    for (int i=0;i<4;i++)
    {
        for (int j=3;j>=0;j--)
        {
            if (board[j][i]==board[j-1][i])
                {board[j][i]+=board[j-1][i];
                board[j-1][i]=0;
                lastscore=score;
                score+=board[i][j]/2;}
        }
    }
     for(int i=0;i<4;i++)
    {
        for (int j=3;j>=0;j--)
        {
            if(!board[j][i])
            {
                for (int k=j-1;k>=0;k--)
                {
                    if(board[k][i])
                    {
                        board[j][i]=board[k][i];
                        board[k][i]=0;
         break;
                    }
                }
            }
        }
    }
    if(check_board_copy()==0)
                add_random();
}
void moveup()
{
    board_copy();
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++){
            if(!board[i][j])
            {
                for (int k=j+1;k<4;k++)
                {
                if (board[i][k])
                {
                    board[i][j]=board[i][k];
                    board[i][k]=0;
    break;
                }
                }
            }
        }
    }
for (int i=0;i<4;i++){
    for (int j=0;j<3;j++)
    {
        if ( board[i][j]==board[i][j+1]){
            board[i][j]=board[i][j]+board[i][j+1];
            board[i][j+1]=0;
            lastscore=score;
            score+=board[i][j]/2;

        }
    }
}
 for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++){
            if(!board[i][j])
            {
                for (int k=j+1;k<4;k++)
                {
                if (board[i][k])
                {
                    board[i][j]=board[i][k];
                    board[i][k]=0;
       break;
                }
                }
            }
        }
    }
    if(check_board_copy()==0)
                add_random();

}
void movedown()
{board_copy();
    for (int i=0;i<4;i++){
        for (int j=3;j>=0;j--){
            if (!board[i][j])
            {
                for (int k=j-1;k>=0;k--)
                {
                    if (board[i][k])
                    {
                        board[i][j]=board[i][k];
                        board[i][k]=0;
break;
                    }
                }
            }
        }
    }
    for (int i=0;i<4;i++){
        for (int j=3;j>0;j--)
        {
            if (  board[i][j]==board[i][j-1])
            {
                board[i][j]+=board[i][j-1];
                board[i][j-1]=0;
                lastscore=score;
                score+=board[i][j]/2;
            }
        }
    }
    for (int i=0;i<4;i++){
        for (int j=3;j>=0;j--){
            if (!board[i][j])
            {
                for (int k=j-1;k>=0;k--)
                {
                    if (board[i][k])
                    {
                        board[i][j]=board[i][k];
                        board[i][k]=0;
                      break;
                    }
                }
            }
        }
    }
    if(check_board_copy()==0)
                add_random();
}
void ghighscore()
{
    std::ifstream tep("score.txt");
    tep>>highscore;
    tep.close();
}
