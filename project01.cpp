#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
 bool gameover ;
 const int height = 20;
 const int width = 40 ;
 int x,y,fruitx,fruity,score;
 enum eDirection{Stop=0,Left,Right,Up,Down} ;
 eDirection dir;
 int tailx[100], taily[100];
 int nTail;
 int in;
//////////////////////////////////////////////////

void setup()
{
    gameover  = false;
    dir=Stop;
    x=width/2;
    y=height/2;
    fruitx=rand()%(width-1);
    fruity=rand()%(height-1);
    score=0;

}

/////////////////////////////////////////

void draw()
{
    system("cls");
    for(int i=0;i<width+1;i++)
    {
      cout<<"*";
    }
    cout<<endl;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
             if(j==0||j==width-1)
                  {
                   cout<<"*";
                  }
             if(i==y&&j==x)
                  {
                   cout<<"O";
                  }

             else if(i==fruity&&j==fruitx)
                   {
                    cout<<"f";
                   }
             else{
                    bool print = false ;
                    for(int k=0;k<nTail;k++)
                    {

                        if(tailx[k]==j && taily[k]==i)
                        {
                            cout<<"o";
                            print = true;

                        }

                    }
                     if(!print)
                        {
                            cout<<" ";
                        }


                 }

          }
        cout<<endl;
     }



    for(int i=0;i<width+1;i++)
    {
        cout<<"*";
    }
    cout<<endl;

    cout<<"SCORE = "<<score<<endl;




}
/////////////////////////////////////////////////////////////////////

void input()
{
    if(_kbhit())
    {
        switch(_getch())
            {
            case 'a':
                dir=Left;
                break;
            case 's':
                dir=Down;
                break;
            case 'd':
                dir=Right;
                break;
            case 'w':
                dir=Up;
                break;
            case 'x':
                gameover=true;
                break;
            }



    }

}
////////////////////////////////////////////////////////////

void logic()
{
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x, prev2y ;
    tailx[0]=x;
    taily[0]=y;
    for(int z=1;z<nTail;z++)
    { prev2x = tailx[z];
      prev2y =taily[z];
      tailx[z]=prevx;
      taily[z]=prevy;
      prevx=prev2x;
      prevy=prev2y;

    }

   switch(dir)
    {
        case Left:
            x--;
            break;
        case Right:
            x++;

            break;
        case Up:
            y--;

            break;
        case Down:
            y++;

            break;

        default:
            break;
    }
   if(x>width-1||x<0||y>height||y<-1)
   {
     gameover=true;
     cout<<"* * * * * * * *"<<endl;
     cout<<"* you are OUT *"<<endl ;
     cout<<"* * * * * * * *"<<endl;


   }

   for (int i=0;i<nTail ; i++)
   {
       if(tailx[i]==x && taily[i]==y)
       {
           gameover = true ;

       }
   }

    if(x == fruitx && y == fruity)
   {
     score+=10 ;
    fruitx=rand()%width;
    fruity=rand()%height;
    nTail++ ;
   }
            if(gameover == true)
                 {
                    cout<<"want to restart press 1 \n";
                      cin>>in;
                              if(in==1)
                              {

                                setup();
                                          draw();
                                          input();
                                          logic();
                                          Sleep(10);



                              }
                              else{
                                gameover = true ;
                              }

                 }

}
//////////////////////////////////////////////////////////////////////////////

int main()
{ cout<<"\tS N A K E  G A M E\n";
setup();
  while(!gameover)
  {
      draw();
      input();
      logic();
      Sleep(10);


  }

 return 0 ;
}
