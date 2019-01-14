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
    int x=255;
    RectangleShape heathbar;
    heathbar.setPosition(100,200);
    heathbar.setFillColor(Color(Color::Red));
    double heath=200;
    heathbar.setSize(Vector2f(heath,30));
    while(window1.isOpen()) {
        Event event;
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
        }
        
        window1.clear(Color::White);
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            heath--;
        }
        heathbar.setSize(Vector2f(heath,30));
        window1.draw(heathbar);

        window1.display();
    }
}