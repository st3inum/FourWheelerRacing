#include<SFML/Graphics.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
// RenderWindow window1;
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");

int highscore;


void Highscore()
{
	sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	while (window1.isOpen())
    {
        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window1.close();
        }

        window1.clear();
        window1.draw(shape);
        window1.display();
    }
}

int main()
{
	Highscore();
}