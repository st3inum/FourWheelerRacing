#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
// RenderWindow window1;
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");


class resume
{
    Texture menu_bar_w,menu_bar_b;
    Sprite resume_sp,exit;

    Text resume_sp_t,help_t,high_score_t,exit_t;
    Font font;
    Texture forg;
    Sprite fg;
    public:
        bool f=0;
    void init()
    {
        forg.loadFromFile("file/bg_4.jpg");
        fg.setTexture(forg);
        fg.setColor(Color(255,255,255,180));
        menu_bar_b.loadFromFile("file/button_2.png");
        menu_bar_w.loadFromFile("file/button_1.png");
        menu_bar_w.setSmooth(true);
        menu_bar_b.setSmooth(true);
        resume_sp.setTexture(menu_bar_w);
        exit.setTexture(menu_bar_w);
        resume_sp.scale(0.5,0.5);
        exit.scale(0.5,0.5);
        resume_sp.setPosition(480,400-270);
        exit.setPosition(480,400-0);
        font.loadFromFile("file/font1.ttf");
        resume_sp_t.setFont(font);
        exit_t.setFont(font);
        resume_sp_t.setString("Resume");
        exit_t.setString("Exit");
        resume_sp_t.setFillColor(Color::White);
        exit_t.setFillColor(Color::White);
        resume_sp_t.setPosition(530,420-270);
        exit_t.setPosition(570,420-0);

    }
    void draw()
    {
        if(f)
        {
            window1.draw(fg);
            window1.draw(resume_sp);
            window1.draw(exit);
            window1.draw(resume_sp_t);
            window1.draw(exit_t);
        }
    }
    void move()
    {
        if(resume_sp.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
        {
            resume_sp_t.setFillColor(Color::Red);
            resume_sp.setTexture(menu_bar_b);
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                f=0;
            }
        }
        else
        {
            resume_sp.setTexture(menu_bar_w);
            resume_sp_t.setFillColor(Color::White);
        }
        if(exit.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
        {
            exit_t.setFillColor(Color::Red);
            exit.setTexture(menu_bar_b);
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                window1.close();
            }
        }
        else
        {
            exit.setTexture(menu_bar_w);
            exit_t.setFillColor(Color::White);
        }
    }
};



int main() {
   window1.setFramerateLimit(60);
   
   while(window1.isOpen()) {
       Event event;
       while(window1.pollEvent(event)) {
           if(event.type == event.Closed) window1.close();
       }

       
       if (new_resume.f==0 && event.type == event.MouseButtonReleased && event.mouseButton.button== sf::Mouse::Right )new_resume.f=1;
       window1.clear();
       if(new_resume.f)
       {
       new_resume.move();
       new_resume.draw();
       }
       
       // cout<<Mouse::getPosition(window1).x<<' '<<Mouse::getPosition(window1).y<<endl;
       // if(Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x>=988 && Mouse::getPosition().x<=1182 && Mouse::getPosition().y>=414 && Mouse::getPosition().y<=448){
       //     cout<<"click\n";
       // }
        // if(event.type == event.MouseButtonReleased && event.mouseButton.button== sf::Mouse::Left)new_resume.move(1);

        
        
       window1.display();
    // Mouse is inside the sprite.
        


   }

}
