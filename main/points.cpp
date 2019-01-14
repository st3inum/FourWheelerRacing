#include<SFML/Graphics.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");


int main()
{
    srand(time(NULL));
    window1.setFramerateLimit(60);
    sf::Text text;
    Font font;
    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("Hello world");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    //text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);



    // inside the main loop, between window.clear() and window.display()
    
    while(window1.isOpen()) {
        Event event;
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
        }
        
        window1.clear(Color::White);
        
        window1.draw(text);

        window1.display();
    }
}