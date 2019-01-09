#include<SFML/Graphics.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");
class gari
{
    Texture text_C,text_G,passenger_body,passenger_matha,bg1,bg2,bg3,text_c;
    Sprite chaka1,chaka2,gari,pass_body,pass_matha,bg_w_1,bg_w_2,bg_w_3;
    int pos_x=-10,pos_y=386,pos_w_x=-10,d=12800*2+15,wind_f=1280; // d for total distance you want to travel ;)
public:
    void load_chaka(string txt)
    {
        text_C.loadFromFile(txt);
        chaka1.setTexture(text_C);
        chaka1.setOrigin(chaka1.getLocalBounds().width/2, chaka1.getLocalBounds().height/2);
        chaka1.setPosition(37,500);
        chaka2.setTexture(text_C);
        chaka2.setOrigin(chaka2.getLocalBounds().width/2, chaka2.getLocalBounds().height/2);
        chaka2.setPosition(200,500);
        chaka1.scale(0.4,0.4);
        chaka2.scale(0.4,0.4);
    }
    void load_chaka(string txt1,string txt2)
    {
        text_C.loadFromFile(txt1);
        text_c.loadFromFile(txt2);
        chaka1.setTexture(text_C);
        chaka1.setOrigin(chaka1.getLocalBounds().width/2, chaka1.getLocalBounds().height/2);
        chaka1.setPosition(37,500);
        chaka2.setTexture(text_c);
        chaka2.setOrigin(chaka2.getLocalBounds().width/2, chaka2.getLocalBounds().height/2);
        chaka2.setPosition(200,500);
        chaka1.scale(0.4,0.4);
        chaka2.scale(0.2,0.2);
    }
    void load_bg(string txt)
    {
        bg1.loadFromFile(txt);
        bg2.loadFromFile(txt);
        bg3.loadFromFile(txt);
        bg_w_1.setTexture(bg1);
        bg_w_2.setTexture(bg2);
        bg_w_3.setTexture(bg3);
        bg_w_1.setPosition(1280*-1-10,-14);
        bg_w_2.setPosition(1280*0-10,-14);
        bg_w_3.setPosition(1280*1-10,-14);
    }
    void load_gari(string txt)
    {
        text_G.loadFromFile(txt);
        gari.setTexture(text_G);
        gari.setPosition(-10,386);
    }
    void load_passenger_body(string txt)
    {
        passenger_body.loadFromFile(txt);
        pass_body.setTexture(passenger_body);
        pass_body.setPosition(96,402);
        pass_body.scale(0.5,0.5);
    }
    void load_passenger_matha(string txt)
    {
        passenger_matha.loadFromFile(txt);
        pass_matha.setTexture(passenger_matha);
        pass_matha.setPosition(80,360);
        pass_matha.scale(0.5,0.5);
    }
    void move()
    {
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            if(pos_w_x-163/2<d)
            {
                pos_w_x+=10;
                chaka1.rotate(10);
                chaka2.rotate(10);
                {
                    bg_w_1.move(-10,0);
                    bg_w_2.move(-10,0);
                    bg_w_3.move(-10,0);
                    wind_f-=10;
                }
                if(wind_f<=0)
                {
                    bg_w_1.move(1280,0);
                    bg_w_2.move(1280,0);
                    bg_w_3.move(1280,0);
                    wind_f=1280;
                }
                if((pos_w_x*3<=win_W || 3*pos_w_x>=3*d-win_W))
                {
                    pos_x+=10;
                    chaka1.move(10, 0);
                    chaka2.move(10, 0);
                    gari.move(10, 0);
                    pass_body.move(10,0);
                    pass_matha.move(10,0);
                }
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            if(pos_w_x>-10)
            {
                pos_w_x-=10;
                chaka1.rotate(-10);
                chaka2.rotate(-10);
                {
                    bg_w_1.move(10,0);
                    bg_w_2.move(10,0);
                    bg_w_3.move(10,0);
                    wind_f+=10;
                }
                if(wind_f>=1280)
                {
                    bg_w_1.move(-1280,0);
                    bg_w_2.move(-1280,0);
                    bg_w_3.move(-1280,0);
                    wind_f=0;
                }
                if((3*pos_w_x<=win_W || 3*pos_w_x>=3*d-win_W))
                {
                    pos_x-=10;
                    chaka1.move(-10, 0);
                    chaka2.move(-10, 0);
                    gari.move(-10, 0);
                    pass_body.move(-10,0);
                    pass_matha.move(-10,0);
                }
            }
        }
        //cout<<pos_x<<' '<<pos_w_x<<' '<<d<<endl;
        //cout<<pos_w_x<<' '<<wind_f<<' '<<wind_n<<endl;
        //if(Keyboard::isKeyPressed(Keyboard::Up)) chaka1.move(0, -10),chaka2.move(0, -10),gari.move(0, -10),pass_body.move(0,-10),pass_matha.move(0,-10);
        //if(Keyboard::isKeyPressed(Keyboard::Down)) chaka1.move(0, 10),chaka2.move(0, 10),gari.move(0, 10),pass_body.move(0,10),pass_matha.move(0,10);
    }
    void print()
    {
        // window1.clear(Color::White);
        window1.draw(bg_w_1);
        window1.draw(bg_w_2);
        window1.draw(bg_w_3);
        window1.draw(pass_matha);
        window1.draw(pass_body);
        window1.draw(chaka1);
        window1.draw(chaka2);
        window1.draw(gari);
        // window1.display();
    }
};

class points
{

    Texture pat;
    int pos_x=-1,pos_y=386,pos_w_x=-10,d=1280*2+15,wind_f=1280; // d for total distance you want to travel ;)
    double curr_v=10,uthbe=500.0/2;
    int badha=500,flag=1;
    int opacity=255;
    public:
    Sprite pa;
    bool f=0;
    int op_cnt=0;
    void scale()
    {
        pa.scale(0.06,0.06);
    }
    void load_points(string txt,int ori)
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

class pathor
{

    Texture pat;
    int pos_x=-1,pos_y=386,pos_w_x=-10,d=1280*2+15,wind_f=1280; // d for total distance you want to travel ;)
    double curr_v=10,uthbe=500.0/2;
    int badha=500;
    int opacity=255;
    public:
    Sprite pa;
    bool f=0;
    int op_cnt=0;
    void scale()
    {
        pa.scale(0.2,0.2);
    }
    void load_points(string txt,int ori)
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


int main() {
    window1.setFramerateLimit(60);


    srand(time(NULL));
    
    int n=1;
    std::vector<points> stone_coin;
    std::vector<pathor> pat;
    points tmp;
    pathor tmp_pat;
    tmp.scale();

    for(int i=0;i<n;i++)
    {
        int x=rand()%win_W;
        tmp.load_points("file/stone.png",x);
        stone_coin.push_back(tmp);

    }
    
    tmp_pat.scale();

    for(int i=0;i<n;i++)
    {
        int x=rand()%win_W;
        tmp_pat.load_points("file/fattor1.png",x);
        pat.push_back(tmp_pat);
    }



    int timer_stone=0,timer_fattor=0;

    gari new_gari;
    new_gari.load_bg("file/bg_3.jpg");
    new_gari.load_chaka("file/car_gravel_tire_ultra_lowres.png");
    new_gari.load_gari("file/Car.png");
    new_gari.load_passenger_body("file/driver-body.png");
    new_gari.load_passenger_matha("file/passanger2-head.png");

    while(window1.isOpen()) {
        Event event;
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
        }

        if(timer_stone>20){//coin er timer_stone
            int x=rand()%win_W;
            tmp.load_points("file/stone.png",x);
            stone_coin.push_back(tmp);
            timer_stone=0;
        }else{
            timer_stone++;
        }

        if(timer_fattor>20){//fattor er timer_fattor
            int x=rand()%win_W;
            tmp_pat.load_points("file/fattor1.png",x);
            pat.push_back(tmp_pat);
            timer_fattor=0;
        }else{
            timer_fattor++;
        }

        window1.clear(Color::White);
        new_gari.move();
        new_gari.print();
        for(int i=0;i<stone_coin.size();i++)
        {
            for(int j=0;j<stone_coin.size();j++){
                if(i!=j){
                    if(stone_coin[i].pa.getGlobalBounds().intersects(stone_coin[j].pa.getGlobalBounds())){
                        stone_coin.erase(stone_coin.begin()+j);
                    }
                }
            }
        }
        for(int i=0;i<pat.size();i++)
        {
            for(int j=0;j<pat.size();j++){
                if(i!=j){
                    if(pat[i].pa.getGlobalBounds().intersects(pat[j].pa.getGlobalBounds())){
                        pat.erase(pat.begin()+j);
                    }
                }
            }
        }
        for(int i=0;i<stone_coin.size();i++)
        {
            for(int j=0;j<pat.size();j++){
                if(stone_coin[i].pa.getGlobalBounds().intersects(pat[j].pa.getGlobalBounds())){
                    pat.erase(pat.begin()+j);
                }
            }
        }
        for(int i=0;i<stone_coin.size();i++){
            stone_coin[i].move();
            if(stone_coin[i].f){
                stone_coin[i].blink();
                if(stone_coin[i].op_cnt>=80) stone_coin.erase(stone_coin.begin()+i);
            }
        }
        for(int i=0;i<stone_coin.size();i++){
            stone_coin[i].print();
        }

        for(int i=0;i<pat.size();i++){
            pat[i].move();
            if(pat[i].f){
                pat[i].blink();
                if(pat[i].op_cnt>80)
                    pat.erase(pat.begin()+i);
            }
        }
        for(int i=0;i<pat.size();i++){
            pat[i].print();
        }



        window1.display();
    }
    return 0;
}
