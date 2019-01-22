#include<SFML/Graphics.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
// RenderWindow window1;
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");

class menu
{
	Texture menu_tex,menu_bar_w,menu_bar_b;
	Sprite menu_sp,new_game,help,high_score,exit;
	public:
	void init()
	{
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
	}
	void draw()
	{
		window1.draw(menu_sp);
		window1.draw(new_game);
		window1.draw(help);
		window1.draw(high_score);
		window1.draw(exit);
	}
	void move(bool f)
	{
		if(Mouse::isButtonPressed(Mouse::Left) && new_game.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
		{
			cout<<"click\n";
			new_game.setTexture(menu_bar_b);
		}
		if(Mouse::isButtonPressed(Mouse::Left) && help.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
		{
			cout<<"help\n";
			help.setTexture(menu_bar_b);
		}
		if(Mouse::isButtonPressed(Mouse::Left) && high_score.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
		{
			cout<<"high_score\n";
			high_score.setTexture(menu_bar_b);
		}
		if(Mouse::isButtonPressed(Mouse::Left) && exit.getGlobalBounds().contains(window1.mapPixelToCoords(Mouse::getPosition(window1))))
		{
			// cout<<"click\n";
			window1.close();
			exit.setTexture(menu_bar_b);
		}
		if(f)
		{
			new_game.setTexture(menu_bar_w);
			help.setTexture(menu_bar_w);
			high_score.setTexture(menu_bar_w);
			exit.setTexture(menu_bar_w);
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
       new_menu.move(0);
       new_menu.draw();

       
       // cout<<Mouse::getPosition(window1).x<<' '<<Mouse::getPosition(window1).y<<endl;
       // if(Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x>=988 && Mouse::getPosition().x<=1182 && Mouse::getPosition().y>=414 && Mouse::getPosition().y<=448){
       //     cout<<"click\n";
       // }
		if(event.type == event.MouseButtonReleased && event.mouseButton.button== sf::Mouse::Left)new_menu.move(1);

		
		
       window1.display();
    // Mouse is inside the sprite.
 		


   }

}
