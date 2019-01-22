#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
// RenderWindow window1;
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");
int highscore;

class menu
{
	bool is_high=0;
    //game over
    Texture game_over_t;
    Sprite game_over_s;
    int counter=0;

    Music finish_music;
    


    Texture menu_tex,menu_bar_w,menu_bar_b,men,close_b,close_w;
    Sprite menu_sp,new_game,help,high_score,exit,m_s,c_s_b;

    Text new_game_t,help_t,high_score_t,exit_t;
    Font font;

    Text highscore_t;

    public:
    Music menu_m;
    void init()
    {
    	men.loadFromFile("file/high.png");
    	m_s.setTexture(men);
    	m_s.scale(.7,.7);
    	m_s.setPosition(400,130);
    	men.setSmooth(true);
    	close_b.loadFromFile("file/close.png");
    	c_s_b.setTexture(close_b);
    	// c_s_b.scale(.7,.7);
    	c_s_b.setPosition(830,130);
    	close_w.loadFromFile("file/close_w.png");
    	close_w.setSmooth(true);

        menu_tex.loadFromFile("file/bg_3.jpg");
        menu_bar_b.loadFromFile("file/button_2.png");
        menu_bar_w.loadFromFile("file/button_1.png");
        menu_bar_w.setSmooth(true);
        menu_bar_b.setSmooth(true);
        menu_sp.setTexture(menu_tex);
        new_game.setTexture(menu_bar_w);
        help.setTexture(menu_bar_w);
        high_score.setTexture(menu_bar_w);
        exit.setTexture(menu_bar_w);

        new_game.scale(0.5,0.5);
        help.scale(0.5,0.5);
        high_score.scale(0.5,0.5);
        exit.scale(0.5,0.5);


        new_game.setPosition(480,400-270);
        help.setPosition(480,400-180);
        high_score.setPosition(480,400-90);
        exit.setPosition(480,400-0);


        font.loadFromFile("file/font1.ttf");

        new_game_t.setFont(font);
        help_t.setFont(font);
        high_score_t.setFont(font);
        exit_t.setFont(font);

        // menu_sp_t.setString("New Game");
        new_game_t.setString("New Game");
        help_t.setString("Help");
        high_score_t.setString("HighScore");
        exit_t.setString("Exit");


        new_game_t.setFillColor(Color::White);
        help_t.setFillColor(Color::White);
        high_score_t.setFillColor(Color::White);
        exit_t.setFillColor(Color::White);


        new_game_t.setPosition(507,420-270);
        help_t.setPosition(570,420-180);
        high_score_t.setPosition(510,420-90);
        exit_t.setPosition(570,420-0);

        highscore_t.setFont(font);
        highscore_t.setPosition(540,250);
        highscore_t.setFillColor(Color::Blue);


        //game over


        game_over_t.loadFromFile("file/game_over.png");
        game_over_s.setTexture(game_over_t);
        game_over_s.setPosition(400,300);

        finish_music.openFromFile("file/bgm_finish.ogg");
        finish_music.setVolume(20);
        menu_m.openFromFile("file/OurMountain_v003.ogg");
        menu_m.setVolume(500);

    }
    void draw()
    {
        if(!is_high)
        {
        	if(counter<=0)
	        {
	            if (finish_music.getStatus() == Music::Status::Playing) {
	               finish_music.stop();
	            }
	            if (menu_m.getStatus() == Music::Status::Stopped) {
	               menu_m.play();
	            }
	            window1.draw(menu_sp);
	            window1.draw(new_game);
	            window1.draw(help);
	            window1.draw(high_score);
	            window1.draw(exit);
	            window1.draw(new_game_t);
	            window1.draw(help_t);
	            window1.draw(high_score_t);
	            window1.draw(exit_t);
	        }
	        else
	        {
	            window1.draw(game_over_s);
	            if (finish_music.getStatus() == sf::Music::Status::Stopped) {
	               finish_music.play();
	            }
	        }
        }
        else
        {
        	string ss="High Score:\n\n        ";
        	ss+=to_string(highscore);
        	window1.draw(menu_sp);
        	window1.draw(m_s);
        	window1.draw(c_s_b);
        	highscore_t.setString(ss);
        	window1.draw(highscore_t);
        }
    }
    void move()
    {
        if(!is_high)
        {
        	counter--;
	        if(counter<0)counter=0;
	        if(counter<=0)
	        {
	            if(new_game.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
	            {
	                new_game_t.setFillColor(Color::Red);
	                new_game.setTexture(menu_bar_b);
	                if(Mouse::isButtonPressed(Mouse::Left))
	                    {
	                        if(menu_m.getStatus()==Music::Status::Playing)
	                        {
	                            menu_m.stop();
	                        }
	                        // if(game())counter=200;
	                        
	                    }
	            }
	            else
	            {
	                new_game.setTexture(menu_bar_w);
	                new_game_t.setFillColor(Color::White);
	            }
	            if(help.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
	            {
	                //cout<<"help\n";
	                help_t.setFillColor(Color::Red);
	                help.setTexture(menu_bar_b);
	                if(Mouse::isButtonPressed(Mouse::Left))
	                {
	                    // menu_m.stop();
	                }
	            }
	            else
	            {
	                help.setTexture(menu_bar_w);
	                help_t.setFillColor(Color::White);
	            }
	            if(high_score.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
	            {
	                high_score_t.setFillColor(Color::Red);
	                high_score.setTexture(menu_bar_b);
	                if(Mouse::isButtonPressed(Mouse::Left)){
	                    
	                    // menu_m.stop();
	                    cout<<highscore<<endl;
	                    is_high=1;

	                    // cout<<"high\n";
	                }
	            }
	            else
	            {
	                high_score.setTexture(menu_bar_w);
	                high_score_t.setFillColor(Color::White);
	            }
	            if(exit.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
	            {
	                // cout<<"click\n";
	                exit_t.setFillColor(Color::Red);
	                exit.setTexture(menu_bar_b);
	                if(Mouse::isButtonPressed(Mouse::Left))
	                    {
	                        // menu_m.stop();
	                        window1.close();
	                    }
	            }
	            else
	            {
	                exit.setTexture(menu_bar_w);
	                exit_t.setFillColor(Color::White);
	            }
	        }
        }
        else
        {
        	if(c_s_b.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
            {
                // cout<<"click\n";
                // c_s_w_t.setFillColor(Color::Red);
                c_s_b.setTexture(close_w);
                if(Mouse::isButtonPressed(Mouse::Left))
                    {
                        // menu_m.stop();
                        // window1.close();
                        // cout<<"s"<<endl;
                        is_high=0;
                    }
            }
            else
            {
                c_s_b.setTexture(close_b);
                // c_s_b_t.setFillColor(Color::White);
            }
        }
    }
};




int main() {
   window1.setFramerateLimit(60);
   menu new_menu;
   new_menu.init();
   while(window1.isOpen()) {
       Event event;
       while(window1.pollEvent(event)) {
           if(event.type == event.Closed) window1.close();
       }

       window1.clear();
       // new_menu.move(0);
       new_menu.move();
       new_menu.draw();

       
       // cout<<Mouse::getPosition(window1).x<<' '<<Mouse::getPosition(window1).y<<endl;
       // if(Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x>=988 && Mouse::getPosition().x<=1182 && Mouse::getPosition().y>=414 && Mouse::getPosition().y<=448){
       //     cout<<"click\n";
       // }
		// if(event.type == event.MouseButtonReleased && event.mouseButton.button== sf::Mouse::Left)new_menu.move(1);
		
		
       window1.display();
    // Mouse is inside the sprite.
 		


   }

}
