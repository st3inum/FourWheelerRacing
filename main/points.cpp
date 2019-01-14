#include<SFML/Graphics.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");


int main()
{

    Texture coin_point;
    Sprite coin[10];
    coin_point.loadFromFile("file/coin.png");

    for(int i=0;i<10;i++)
    {
        coin[i].setPosition(400,300);
        coin[i].setTexture(coin_point);
        coin[i].setTextureRect(IntRect(85*i-1,252,85.00,80));
        coin[i].scale(0.5,0.5);
    }
    coin[0].setOrigin(41.3-85*0,290.00-252);
    coin[1].setOrigin(127.3-85*1,290.00-252);
    coin[2].setOrigin(207.3-85*2,290.00-252);
    coin[3].setOrigin(299.3-85*3,290.00-252);
    coin[4].setOrigin(388.3-85*4,290.00-252);
    coin[5].setOrigin(472.3-85*5,290.00-252);
    coin[6].setOrigin(544.3-85*6,290.00-252);
    coin[7].setOrigin(630.3-85*7,290.00-252);
    coin[8].setOrigin(718.3-85*8,290.00-252);
    coin[9].setOrigin(803.3-85*9,290.00-252);



    // srand(time(NULL));
    // window1.setFramerateLimit(60);
    // sf::Text text;
    // Font font;
    // // select the font
    // text.setFont(font); // font is a sf::Font

    // // set the string to display
    // text.setString("Hello world");

    // // set the character size
    // text.setCharacterSize(24); // in pixels, not points!

    // // set the color
    // //text.setFillColor(sf::Color::Red);

    // // set the text style
    // text.setStyle(sf::Text::Bold | sf::Text::Underlined);



    // inside the main loop, between window.clear() and window.display()
    int i=0;
    while(window1.isOpen()) {
        Event event;
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
        }
        
        // window1.clear(Color::White);
        
        // window1.draw(text);
        window1.clear();
        i++;
        i%=10*50;
        // coin[5].rotate(i/50);
        window1.draw(coin[i/50]);
        window1.display();

    }
}