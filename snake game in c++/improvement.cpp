#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<windows.h>
using namespace std;
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int width=20,height=20,gameover;
int/*(this x and y are snake dimension)*/fruitX,fruitY,score,flag;
int tailX[100],tailY[100];
int counttail=0;
typedef struct Snake
{
    int x;
    int y;
};
Snake snake;
void setup()
{
    gameover=0;
    //snake starting point
    snake.x=width/2;
    snake.y=height/2;

    srand(time(0));
    //fruit position inside the area through x and y coordinate
    // label1:
    fruitX=((rand()%20));
    if(fruitX==0)
    {
        fruitX=fruitX+3;
        // goto label1;
    }

    // label2:
    fruitY=((rand()%20));
    if(fruitY==0)
    {
        fruit=fruitY+3;
        // goto label2;
    }

    score=0;

    
}
void draw()
{
    int i,j;
    system("cls");
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++){
            if(i==0 || i==(height-1) || j==0 || j==(width-1))
            {
                cout<<"# ";
            }
            else 
            {
                if(i==snake.x && j==snake.y)
                {
                    cout<<"0 ";
                }
                else if(i==fruitX && j==fruitY)
                {
                    cout<<"f ";
                }
                else{
                    int ch=0;
                    for(int k=0;k<counttail;k++)
                    {
                        if(i==tailX[k] && j==tailY[k])
                        {
                            cout<<"o ";
                            ch=1;
                        }
                    }
                    if(ch==0)
                    cout<<"  ";
                }
            }
        
        }
        cout<<endl;
    }
    cout<<"Score = "<<score;

    gotoxy(0,0);
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
                flag=1;
                break;
            case 'd':
                flag=2;
                break;
            case 'w':
                flag=3;
                break;
            case 's':
                flag=4; 
                break;
            case 'x':
                gameover=1;
                break;
        }
    }
}
void logic()
{
    int i;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=snake.x;
    tailY[0]=snake.y;

    for(i=1;i<counttail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(flag)
    {
        case 1:
            snake.y--;
            draw();
            break;
        case 2:
            snake.y++;
            draw();
            break;
        case 3:
            snake.x--;
            draw();
            break;
        case 4:
            snake.x++;
            draw();
            break;
    }

    if(snake.x<=0 || snake.y<=0 ||snake.x>=width ||snake.y>=height )
    {
        gameover=1;
    }
    for(i=0;i<counttail;i++)
        {
            if(snake.x==tailX[i] && snake.y==tailY[i])
            gameover=1;
        }
    if(snake.x==fruitX && snake.y==fruitY )
    {
        // label3:
        fruitX=((rand()%20));
        if(fruitX==0)
        {
            fruitX++;
            // goto label3;
        }

        // label4:
        fruitY=((rand()%20));
        if(fruitY==0)
        {
            fruitY++;

            // goto label4;
        }

        score+=10;
        counttail++;
    }
}
int main()
{
    char c;
    int a;
    system("cls");
    setup();
    while(1){
    draw();
    input();
    logic();
    for(int m=0;m<100;m++)
    {
    for(int m=0;m<100000;){m++;}  //increses the value of m if wanted to speed up the snake
    }
    if(gameover==1)
    {
        cout<<"\t\t\t\t\t\t\tyour score is :"<<score;
        getch();
        system("cls");
        break;
    }
    }
    // srand(time(0));
    // a=rand()%10+1;
    // cout<<a;
    // while(1)
    // {
    //     if(kbhit())
    //     {
    //         ch=getch();
    //         cout<<ch;
    //         break;
    //     }
    //     cout<<"k";
    // }
}