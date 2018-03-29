#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
  using namespace sf;
  using namespace std;

  class ball{
    public: ///*this class contains position of x axis of ball...it is used while Keypressed right or left..*/
       int x,y,z=0,posx=0,posy=0,direction=0,go=0,stop=0,is_out=0,colision=0;
       void check_colision(int a)
       {
         colision=a;
       }
     
  void ball_direc(int a,int b,int c)
  {
        direction=c;
        x=a,y=b;
        posx=a,posy=b;
        if(direction==0)
        { x=0,y=0;
          stop=1;
        }

/////////////////////////////////
      if(direction==1)
        {
             if(colision==1)
               {   y=3;
                  colision=0;
               }

               if(y>=495)
               {  go=1;
               }///when the ball touch down


               else if(x<=5)
               {  go=2;
               }//when the ball touch left


               else if(y<=5)
               {   go=3;
               }///when the ball touch up


              else if(x>=570)
               {   go=4;
               }///when the ball touch right


           while(1)
           {
               if(go==1)
                {   x=-6,y=-4;
                    break;
                }

                else if(go==2)
                {    x=4,y=-3;
                     break;
                }
            
                else if(go==3)
                {   x=6,y=5;
                break;
                }
            
                else if(go==4)
                {   x=-4,y=6;
                break;
                }
           }
       } 
///////////////////////////////////////////////////////
   if(direction==2)
   {
          if(colision==1)
            { y=0;
              colision=0;
            }
            
            
          if(y>=495)
            {   go=3;
            }///when the ball touch down
            
         else if(x<=5)
            {   go=4;
            }///when the ball touch left
            
         else if(y<=1)
            {   go=1;
            }///when the ball touch up
            
         else if(x>=570)
            {   go=2;
            }///when the ball touch right
            
            
       while(1)
       {
           if(go==3)
             { x=6,y=-4;/// x=3,y=-2;
               break;
             }
             
           else if(go==2)
             { x=-4,y=-3;///x=-2,y=-2;
               break;
             }
             
          else if(go==1)
             { x=-5,y=6;///x=-3,y=3;
               break;
             }
             
          else if(go==4)
             { x=4,y=6;/// x=2,y=3;
               break;
             }
       }
    }
 }

 




  int set_box(RectangleShape &x,int y)
  {
       if(y>=1&&y<=9)
         {  x.setPosition(y*55,0);
         }
         
       if(y>9&&y<=16)
         {  y=y-8;
            x.setPosition((y*55),35);
         }
         
       if(y>16&&y<=20)
         {  y=y-13;
            x.setPosition((y*55),72);
         }
   }



  };



    int main(){
        ball ob;
        int x=5,y=2,start=0,a=250,b=530,direction=0,win=0;
        char score[2];
        RenderWindow window(VideoMode(600,600),"DX_Ball V0.3");
        Event event;


        Font font;
        font.loadFromFile("black.ttf");
        Text text;
        text.setFont(font);
        text.setCharacterSize(35);
        text.setColor(Color::Black);
        text.setPosition(420,560);
        text.setString("SCORE:");
 
  //////text to show scores///////
        Text scores;
        scores.setFont(font);
        scores.setColor(Color::Black);
        scores.setCharacterSize(35);
        scores.setPosition(550,560);
        scores.setString("0");


///////text to show game starting words//////
        Text starts;
        starts.setFont(font);
        starts.setColor(Color::Black);
        starts.setPosition(80,250);
        starts.setString("Prees Key to start");
        starts.setCharacterSize(45);

        RectangleShape show_texture;
        show_texture.setSize(Vector2f(400,350));
        show_texture.setPosition(100,100);

        Texture texture;


//////Bricks,,which have to braek by ball...//////
        RectangleShape box[25];
        for(int m=1;m<20;m++)
         {
             box[m].setSize(Vector2f(50,30));
             box[m].setFillColor(Color::Red);
             box[m].setOutlineColor(Color::Black);
             box[m].setOutlineThickness(5);
         }


        for(int n=1;n<20;n++)
         {
            set_box(box[n],n);
         }


        CircleShape ball(15);
        ball.setPosition(310,500);
        ball.setFillColor(Color::Black);


        RectangleShape back(Vector2f(600,600));
        back.setFillColor(Color::Cyan);


        RectangleShape danda(Vector2f(150,25));
        danda.setFillColor(Color::Black);
        danda.setPosition(a,b);

        Clock Clock;
        
        
 ///////game loop start from here.......
       while(window.isOpen()){


            window.setFramerateLimit(40);
            window.draw(back);
            window.draw(ball);
            window.draw(danda);
            window.draw(starts);
            window.draw(text);
            window.draw(scores);

      if(win>=19)
       {  direction=0;
       }


      for(int l=1;l<=20;l++)
       {
           window.draw(box[l]);
       }

    
      if((ob.posy>=0&&ob.posy<=100&&start==1))
       {
           ob.colision=0;
      
           if(ob.posy>=61&&ob.posy<=101)
             {
                for(int k=16;k<=19;k++)
                 {
    
                    Vector2f boxpos=box[k].getPosition();
                    if(ob.posx>=boxpos.x-5&&ob.posx<=boxpos.x+55)
                     {
                        box[k].setPosition(-500,-500);
                        win=win+1;
                    
                        if(win<=9)
                          {  score[0]=win+48;
                          }

                        else
                          {  score[0]='1';
                             score[1]=win+38;
                          }

                         scores.setString(score);
                         ob.colision=1;
                         break;
                     }
                 }
              }



          else if(ob.posy>=31&&ob.posy<=60)
          {
             for(int k=10;k<=15;k++)
             {
               Vector2f boxpos=box[k].getPosition();
               if(ob.posx>=boxpos.x-5&&ob.posx<=boxpos.x+55)
                {
                     box[k].setPosition(-500,-500);
                     win=win+1;
                    
                     if(win<=9)
                      { score[0]=win+48;
                      }

                     else
                      {
                        score[0]='1';
                        score[1]=win+38;
                      }
                     
                     scores.setString(score);
                     ob.colision=1;
                     break;
                } 
              }
            }



          else if(ob.posy>=0&&ob.posy<=30)
          {
         
             for(int k=1;k<=9;k++)
             {
                Vector2f boxpos=box[k].getPosition();
         
               if(ob.posx>=boxpos.x-5&&ob.posx<=boxpos.x+55)
               {
                   box[k].setPosition(-500,-500);
                   win=win+1;
                   
                   if(win<=9)
                    { score[0]=win+48;
                    }

                   else
                    {
                      score[0]='1';
                      score[1]=win+38;
                    }
                    
                   scores.setString(score);
                   ob.colision=1;
                   break;
               }
            }
          }




      }


     if(start>=1)
      {
           Vector2f position=ball.getPosition();
           ob.ball_direc(position.x,position.y,direction);
           ball.move(ob.x,ob.y);
           
           if(position.y>=490&&y<=505)
            { 
               if(position.x>=a-5&&position.x<=a+155)
                 {
                 }
               else
                 {
                   direction=0;
                   start=2;
                 }
            }


           if(ob.stop==1)
           {
              ball.setPosition(-100,-100);
              ball.move(0,0);

              if(win>=19)
               {
                 texture.loadFromFile("winner.jpg");
                 show_texture.setTexture(&texture);
               }
              
             else
               {
                 texture.loadFromFile("lose.png");
                 show_texture.setTexture(&texture);
               }
             window.draw(show_texture);
          }
           

       }
    window.display();



    while(window.pollEvent(event))
        {
           if(event.type==Event::Closed)
             {
                window.close();
             }
           if(Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::Right))
             {
               if(start==0)
                {
                  starts.setPosition(-500,-500);
                  start=start+1;

                  if(Keyboard::isKeyPressed(Keyboard::Left))
                     direction=1;

                  if(Keyboard::isKeyPressed(Keyboard::Right))
                     direction=2;

                }
            }///for first time start the ball moving..



          if(Keyboard::isKeyPressed(Keyboard::Left))
              {
                  if(start==1)
                    {
                         a=a-20;
                         if(a<=0)
                           {
                                 a=0;
                           }/// direction=1;


                         danda.setPosition(a,b);
                       ///*when the ball near to down*/
                         if(ob.posy>=490&&ob.posy<=505)
                         {
                            if(ob.posx>=a-10&&ob.posx<=a+160)
                              {
                                  direction=1;
                              }

                             else
                              { direction=0;
                                ///if direction 0 the game will stop
                              }
                         }
                      }
               }


         if(Keyboard::isKeyPressed(Keyboard::Right))
           {
              if(start==1)
                {
                   a=a+30;

                   if(a>=450)
                     {  a=450;
                     }/// direction=2;
                     
                   danda.setPosition(a,b);
 
                   if(ob.posy>=490&&ob.posy<=505)
                     {
                      // go right
                         if(ob.posx>=a-10&&ob.posx<=a+160)
                           {  direction=2;
                                 //Right click
                           }
                           
                         else
                           {
                               direction=0;
                           }
                      }
                 }
            }
        }
    }
    
    return 0;
}


