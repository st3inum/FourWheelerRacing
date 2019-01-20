//#include<SFML/Graphics.hpp>
//using namespace sf;
//#include <bits/stdc++.h>
//using namespace std;
//#define win_W 1280
//// RenderWindow window1;
//RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");
//
//
//
//int main() {
//    window1.setFramerateLimit(60);
//    Texture menu_tex;
//    menu_tex.loadFromFile("file/In_Game_Menu.jpg");
//    Sprite menu_sp;
//    menu_sp.setTexture(menu_tex);
//    while(window1.isOpen()) {
//        Event event;
//        while(window1.pollEvent(event)) {
//            if(event.type == event.Closed) window1.close();
//        }
//
//        window1.clear();
//
//        window1.draw(menu_sp);
//        //cout<<Mouse::getPosition().x<<' '<<Mouse::getPosition().y<<endl;
//        if(Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition().x>=988 && Mouse::getPosition().x<=1182 && Mouse::getPosition().y>=414 && Mouse::getPosition().y<=448){
//            cout<<"click\n";
//        }
//        window1.display();
//
//
//    }
//
//}
