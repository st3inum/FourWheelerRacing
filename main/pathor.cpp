#include<SFML/Graphics.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");

class pathor
{

    Texture pat;
    Sprite pa;
    int pos_x=-1,pos_y=386,pos_w_x=-10,d=1280*2+15,wind_f=1280; // d for total distance you want to travel ;)
    double curr_v=10,uthbe=500.0/2;
    int badha=500,flag=1;
    int opacity=255;
    public:
    bool f=0;
    int op_cnt=0;
    void scale()
    {
        pa.scale(0.09,0.09);
    }
    void load_pathor(string txt,int ori)
    {
        // pat.setSmooth(true);
        pat.loadFromFile(txt);
        pa.setColor(Color(255,255,255,255));
        pa.setTexture(pat);
        pa.setOrigin(pa.getLocalBounds().width/2, pa.getLocalBounds().height/2);
        pa.setPosition(ori,10);
        // pa.scale(0.09,0.09);
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
        if(uthbe>10)
        {
            if(flag==1)
            {
                if(pa.getPosition().y<badha)
                {
                    pa.move(0.0,curr_v);
                    curr_v+=(flag*9.8/30.0);
                }
                else 
                {
                    flag*=-1;
                    curr_v/=2;
                    pa.move(0.0,-curr_v);
                    curr_v+=(flag*9.8/30.0);
                }
            }
            else
            {
                if(pa.getPosition().y>badha-uthbe && curr_v>0)
                {
                    pa.move(0.0,-curr_v);
                    curr_v+=(flag*9.8/30.0);
                }
                else 
                {
                    uthbe/=3;
                    flag*=-1;
                    // curr_v=0;
                    pa.move(0.0,curr_v);
                    curr_v+=(flag*9.8/30.0);
                }
            }
        }
        else
        {
            if(pa.getPosition().y<badha)
            {
                f=1;
                pa.move(0.0,curr_v);
                curr_v+=(flag*9.8/30.0);
            }
        }
        // cout<<flag<<' '<<pa.getPosition().y<<' '<<curr_v<<endl;
    }
    void blink()
    {   
        op_cnt++;
        opacity+=8;
        opacity%=255;
        // if(opacity<=63)pa.setColor(Color(255,255,255,63));
        if(opacity<=127)pa.setColor(Color(255,255,255,10));
        // else if(opacity<=191)pa.setColor(Color(255,255,255,191));
        else if(opacity<=255)pa.setColor(Color(255,255,255,255));
    }
    void print()
    {
        window1.draw(pa);
    }
};

int main()
{
    srand(time(NULL));
    window1.setFramerateLimit(60);
    int n=6;
    std::vector<pathor> pat(n);
    pathor tmp;
    tmp.scale();
    for(int i=0;i<n;i++)
    {
        int x=rand()%win_W;
        tmp.load_pathor("file/stone.png",x);
        pat.push_back(tmp);
    }
    while(window1.isOpen()) {
        Event event;
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
        }
        window1.clear(Color::White);
        for(int i=0;i<pat.size();i++){
            pat[i].move();
            if(pat[i].f){
                pat[i].blink();
                if(pat[i].op_cnt>=80) pat.erase(pat.begin()+i);
            }
        }
        for(int i=0;i<pat.size();i++){
            pat[i].print();
        }
        window1.display();
    }
}