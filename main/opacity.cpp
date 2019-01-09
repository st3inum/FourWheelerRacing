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
    RectangleShape rec;
    rec.setPosition(100,200);
    rec.setFillColor(Color(200,200,100,x));
    rec.setSize(Vector2f(20,30));

    while(window1.isOpen()) {
        Event event;
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
        }
        rec.setFillColor(Color(200,200,100,x));
        if(x-10>0)x-=10;
        window1.clear(Color::White);
        window1.draw(rec);

        window1.display();
    }
}