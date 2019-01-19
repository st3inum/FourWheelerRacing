#include<SFML/Graphics.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
// RenderWindow window1;
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");

/*
class life
{
    Texture pat;
    int pos_x=-1,pos_y=386,pos_w_x=-10,d=1280*2+15,wind_f=1280; // d for total distance you want to travel ;)
    double curr_v=10,uthbe=500.0/2;
    int badha=480;
    int opacity=255,blink_time=0;
    public:
    Sprite pa[9];
    bool f=0;
    int op_cnt=0;
    void scale()
    {
        pa.scale(0.2,0.2);
    }
    void load_life(string txt,int ori)
    {
        // pat.setSmooth(true);
        pat.loadFromFile(txt);
        pa.setColor(Color(255,255,255,255));
        pa.setTexture(pat);
        pa.setOrigin(pa.getLocalBounds().width/2, pa.getLocalBounds().height/2);
        pa.setPosition(ori,10);
        cout<<"# "<<txt<<endl;
    }
    void move()
    {
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
           pa.move(-10,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            pa.move(10,0);
        }

        if(pa.getPosition().y<badha)
        {
            pa.move(0.0,curr_v);
            curr_v+=(9.8/30.0);
        }else
        {
            f=1;
        }
        // cout<<flag<<' '<<pa.getPosition().y<<' '<<curr_v<<endl;
        
    }
    void blink()
    {   
        blink_time++;
        if(blink_time>40)
        {
            op_cnt++;
            opacity+=8;
            opacity%=255;
            // if(opacity<=63)pa.setColor(Color(255,255,255,63));
            if(opacity<=127)pa.setColor(Color(255,255,255,10));
            // else if(opacity<=191)pa.setColor(Color(255,255,255,191));
            else if(opacity<=255)pa.setColor(Color(255,255,255,255));
        }
    }
    void print()
    {
        window1.draw(pa);
    }
};

*/



int main() {
    window1.setFramerateLimit(60);
    int coin_image_number=0,framerate=2;
    Texture heart;
    Sprite hea[10];
    heart.loadFromFile("file/heart.png");
    // heart.loadFromFile("file/heart.png");
    heart.setSmooth(true);


    int i=0;
    hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(0,0,252,217.5));
    hea[0].setOrigin(127.5,108);
    hea[i].scale(0.5,0.5);
    i++;
    hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(276,0,492-276,217.5));
    hea[1].setOrigin(396-276,108);
    hea[i].scale(0.5,0.5);
    i++;
    hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(516,0,694.5-516,217.5));
    hea[2].setOrigin(628.5-516,108);
    hea[i].scale(0.5,0.5);
    i++;
    hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(696.5,0,836.5-696.5,217.5));
    hea[3].setOrigin(790.5-696.5,108);
    hea[i].scale(0.5,0.5);
    i++;
    // hea[4].setOrigin(937.108);
    hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(862,0,938-862,217.5));
    hea[4].setOrigin(902-862,108);
    hea[i].scale(0.5,0.5);
    i++;




    hea[i].setPosition(500-30,400-40);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(919.5,501.0,960-919.5,766.5-501.0));
    hea[i].rotate(180);
    hea[5].setOrigin(937.5-919.5,627.0-501);
    hea[i].scale(-0.5,-0.5);
    i++;
    hea[i].setPosition(500-30,400-40);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(706.5,511.5,817.5-706.5,765-511.5));
    hea[i].rotate(180);
    hea[6].setOrigin(768-706.5,630-511.5);
    hea[i].scale(-0.5,-0.5);
    i++;
    hea[i].setPosition(500-30,400-40);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(489,510,687-489,765-510));
    hea[i].rotate(180);
    hea[7].setOrigin(606-489,631.5-510);
    hea[i].scale(-0.5,-0.5);
    i++;
    hea[i].setPosition(500-30,400-40);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(199.5,489.0,279,277));
    hea[i].rotate(180);
    hea[8].setOrigin(345-199.5,607.5-489);
    hea[i].scale(-0.5,-0.5);
    i++;
    hea[i].setPosition(500-30,400-40);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(0,0,348,351));
    hea[i].rotate(180);
    hea[9].setOrigin(177,151.5);
    hea[i].scale(-0.5,-0.5);
    // hea[4].setOrigin(937.5,627.0);



   /* // hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(919.5,501.0,960-919.5,766.5-501.0));
    hea[i].scale(-0.5,-0.5);
    hea[i].rotate(180);
    i++;
    // hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(706.5,511.5,817.5-706.5,765-511.5));
    hea[i].scale(-0.5,-0.5);
    hea[i].rotate(180);
    i++;
    // hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(489,510,687-489,765-510));
    hea[i].scale(-0.5,-0.5);
    hea[i].rotate(180);
    i++;
    // hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(199.5,489.0,279,277));
    hea[i].scale(-0.5,-0.5);
    hea[i].rotate(180);
    i++;
    // hea[i].setPosition(500,400);
    hea[i].setTexture(heart);
    hea[i].setTextureRect(IntRect(0,0,348,351));
    hea[i].scale(-0.5,-0.5);
    hea[i].rotate(180);*/
    
    // hea[0].setOrigin(177,151.5);
    // hea[1].setOrigin(345,607.5);
    // hea[2].setOrigin(606,631.5);
    // hea[3].setOrigin(768,630);
    // hea[4].setOrigin(937.5,627.0);
    // hea[5].setOrigin(937.5,627.0);
    // hea[6].setOrigin(768,630);
    // hea[7].setOrigin(606,631.5);
    // hea[8].setOrigin(345,607.5);
    // hea[9].setOrigin(177,151.5);

    // for(int p=0;p<10;p++)hea[p].setPosition(400,500);

    i=0;
    int j=0;
    while(window1.isOpen()) {
        Event event;
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
        }
        i++;
        if(i==9)j++;
        i%=10;
        j%=10;
        window1.clear();
        // for(j=0;j<10;j++)
        window1.draw(hea[j]);
        // hea[j].print();
        window1.display();
        
    }

}
