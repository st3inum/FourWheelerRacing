#include<SFML/Graphics.hpp>
using namespace sf;
#include <bits/stdc++.h>
using namespace std;
#define win_W 1280
// RenderWindow window1;
RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");
class life
{
    Texture heart;
    int curr=0,j=0,n=+5;
    public:
    Sprite hea[10];
    int start_point;
    bool f=0;
    void init()
    {
        heart.loadFromFile("file/heart.png");
        heart.setSmooth(true);
        int i=0;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(0,0,252,217.5));
        hea[0].setOrigin(127.5,108);
        //hea[i].scale(0.2,0.2);
        i++;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(276,0,492-276,217.5));
        hea[1].setOrigin(396-276,108);
        //hea[i].scale(0.2,0.2);
        i++;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(516,0,694.5-516,217.5));
        hea[2].setOrigin(628.5-516,108);
        //hea[i].scale(0.2,0.2);
        i++;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(696.5,0,836.5-696.5,217.5));
        hea[3].setOrigin(790.5-696.5,108);
        //hea[i].scale(0.2,0.2);
        i++;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(862,0,938-862,217.5));
        hea[4].setOrigin(902-862,108);
        //hea[i].scale(0.2,0.2);
        i++;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(82.5,217.5,168-82.5,239.5));
        hea[5].setOrigin(124.5-82.5,101);
        //hea[i].scale(0.2,0.2);
        i++;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(192,217.5,334.4-192,239.5));
        hea[6].setOrigin(238.5-192,101);
        //hea[i].scale(0.2,0.2);
        i++;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(333,217.5,516-333,239.5));
        hea[7].setOrigin(396-333,101);
        //hea[i].scale(0.2,0.2);
        i++;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(516,217.5,763.5-516,239.5));
        hea[8].setOrigin(630-516,101);
        //hea[i].scale(0.2,0.2);
        i++;
        hea[i].setPosition(start_point,500);
        hea[i].setTexture(heart);
        hea[i].setTextureRect(IntRect(763.5,217.5,1014-763.5,239.5));
        hea[9].setOrigin(897-763.5,101);
        //hea[i].scale(0.2,0.2);
    }
    void scale()
    {
        for(int i=0;i<10;i++)
        hea[i].scale(0.2,0.2);
    }
    void move()
    {
        j++;
        if(j==n-1)curr++;
        j%=n;
        curr%=10;
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            for(int i=0;i<10;i++)hea[i].move(-10,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            for(int i=0;i<10;i++)hea[i].move(10,0);
        }
        // cout<<flag<<' '<<pa.getPosition().y<<' '<<curr_v<<endl;

    }
    void draw()
    {
        window1.draw(hea[curr]);
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
    int badha=480;
    int opacity=255,blink_time=0;
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



class gari
{
    Texture text_C,text_G,passenger_body,passenger_matha,bg1,bg2,bg3,text_c;

    Sprite chaka1,chaka2,gari,pass_body,pass_matha,bg_w_1,bg_w_2,bg_w_3;

    int opacity=255;
public:
    int pos_x=-10,pos_y=386,pos_w_x=-10,d=1280000*2+15,wind_f=1280; // d for total distance you want to travel ;)
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
    void blink()
    {
        opacity+=20;
        opacity%=255;
        if(opacity<=127)
        {
            gari.setColor(Color(255,255,255,127));
            chaka1.setColor(Color(255,255,255,127));
            chaka2.setColor(Color(255,255,255,127));
            pass_body.setColor(Color(255,255,255,127));
            pass_matha.setColor(Color(255,255,255,127));
        }
        else if(opacity<=255)
        {
            gari.setColor(Color(255,255,255,255));
            chaka1.setColor(Color(255,255,255,255));
            chaka2.setColor(Color(255,255,255,255));
            pass_body.setColor(Color(255,255,255,255));
            pass_matha.setColor(Color(255,255,255,255));
        }
    }
    void thik_hoye_ja()
    {
        gari.setColor(Color(255,255,255,255));
        chaka1.setColor(Color(255,255,255,255));
        chaka2.setColor(Color(255,255,255,255));
        pass_body.setColor(Color(255,255,255,255));
        pass_matha.setColor(Color(255,255,255,255));
    }

    bool collusion(Sprite a)
    {
        return a.getGlobalBounds().intersects(chaka1.getGlobalBounds())||
        a.getGlobalBounds().intersects(chaka2.getGlobalBounds())||
        a.getGlobalBounds().intersects(pass_body.getGlobalBounds())||
        a.getGlobalBounds().intersects(pass_matha.getGlobalBounds())||
        a.getGlobalBounds().intersects(gari.getGlobalBounds())
        ;
    }
    bool matha_collusion(Sprite a)
    {
        return a.getGlobalBounds().intersects(pass_matha.getGlobalBounds());
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



int main() {
     //RenderWindow window1(VideoMode(win_W, 620), "Four Wheeler Racing");
     //window1.setTitle("Four Wheeler Racing");
     //window1.setSize(VideoMode(win_W, 620));


    // lifer kaj
    Texture gameover_tex;
    gameover_tex.loadFromFile("file/game_over.jpg");
    Sprite gameover_sp;
    gameover_sp.setTexture(gameover_tex);
    life ha;
    vector<life>ha_vec;
    int ha_timer=80;
    ha.init();
    ha.scale();
    // (VideoMode(win_W, 620), "Four Wheeler Racing");
    //coin show point
    int coin_image_number=0,framerate=2;
    Texture coin_point;
    Sprite coin[10];
    coin_point.loadFromFile("file/coin.png");
    coin_point.setSmooth(true);
    for(int i=0;i<10;i++)
    {
        coin[i].setPosition(50,40);
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





    Font font;
    font.loadFromFile("file/font.ttf");
    Text text_points,text_health;
    text_points.setFont(font);
    text_points.setString("0");
    text_points.setPosition(80,12);
    text_points.setCharacterSize(45);
    text_health.setFont(font);
    text_health.setString("100 %");
    text_health.setPosition(win_W-170,40);



    window1.setFramerateLimit(60);


    int point=0;

    srand(time(NULL));

    int n=1;
    std::vector<points> stone_coin;
    std::vector<pathor> pat;
    points tmp;
    pathor tmp_pat;
    tmp.scale();

    // Healthbar
    Texture healthBar;
    Sprite HealthBar;
    healthBar.loadFromFile("file/healthbar.png");
    HealthBar.setTexture(healthBar);
    RectangleShape healthbar;
    healthbar.setPosition(win_W-289,35);
    healthbar.setFillColor(Color(Color::Red));
    double health=275;
    healthbar.setSize(Vector2f(health,50));
    healthbar.setOutlineThickness(-2.f);
    healthbar.setOutlineColor(Color::Black);
    HealthBar.setPosition(win_W-301.5,-83);
    HealthBar.scale(0.4,0.4);
    // healthBar.setSmooth(true);

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
    int fattor_blink_flag=0;

    bool menu_b=1,alive=1;
    Texture menu_tex;
    menu_tex.loadFromFile("file/In_Game_Menu.jpg");
    Sprite menu_sp;
    menu_sp.setTexture(menu_tex);


    while(window1.isOpen()) {
        Event event;
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
        }
        window1.clear(Color::White);
        if(menu_b)
        {
            window1.draw(menu_sp);
            cout<<Mouse::getPosition(window1).x<<' '<<Mouse::getPosition(window1).y<<endl;
            if(Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition(window1).x>=415 && Mouse::getPosition(window1).x<=609 && Mouse::getPosition(window1).y>=175 && Mouse::getPosition(window1).y<=208){
                menu_b=0;
                cout<<"click\n"<<endl;
            }
        }

        else{
            if(alive){
                if(ha_timer>=300)
                {
                    ha_timer=0;
                    ha.start_point=rand()%win_W;
                    ha.init();
                    ha_vec.push_back(ha);
                }
                else
                {
                    ha_timer++;
                }

                if(timer_stone>120) //coin er timer_stone
                {
                    int x=rand()%win_W;
                    tmp.load_points("file/stone.png",x);
                    stone_coin.push_back(tmp);
                    timer_stone=0;
                }
                else
                {
                    timer_stone++;
                }

                if(timer_fattor>200) //fattor er timer_fattor
                {
                    int x=rand()%win_W;
                    tmp_pat.load_points("file/fattor1.png",x);
                    pat.push_back(tmp_pat);
                    timer_fattor=0;
                }
                else
                {
                    timer_fattor++;
                }


                new_gari.move();
                new_gari.print();

                //stone - stone baad
                for(int i=0; i<stone_coin.size(); i++)
                {
                    for(int j=0; j<stone_coin.size(); j++)
                    {
                        if(i!=j)
                        {
                            if(stone_coin[i].pa.getGlobalBounds().intersects(stone_coin[j].pa.getGlobalBounds()))
                            {
                                stone_coin.erase(stone_coin.begin()+j);
                            }
                        }
                    }
                }


                // fattor - fattor baad
                for(int i=0; i<pat.size(); i++)
                {
                    for(int j=0; j<pat.size(); j++)
                    {
                        if(i!=j)
                        {
                            if(pat[i].pa.getGlobalBounds().intersects(pat[j].pa.getGlobalBounds()))
                            {
                                pat.erase(pat.begin()+j);
                            }
                        }
                    }
                }

                // stone - fattor baad
                for(int i=0; i<stone_coin.size(); i++)
                {
                    for(int j=0; j<pat.size(); j++)
                    {
                        if(stone_coin[i].pa.getGlobalBounds().intersects(pat[j].pa.getGlobalBounds()))
                        {
                            pat.erase(pat.begin()+j);
                        }
                    }
                }


                // point count
                for(int i=0; i<stone_coin.size(); i++)
                {
                    if(new_gari.collusion(stone_coin[i].pa))
                    {
                        point++;
                        stone_coin.erase(stone_coin.begin()+i);
                        text_points.setString(to_string(point));
                    }
                }
                // life increase count
                for(int i=0; i<ha_vec.size(); i++)
                {
                    for(int j=0; j<10; j++)
                        if(new_gari.collusion(ha_vec[i].hea[j]))
                        {
                            health=min(health+10.0,275.0);
                            ha_vec.erase(ha_vec.begin()+i);

                            text_health.setString(to_string((int)(health/2.75))+" %");
                            break;
                        }
                }

                // health reduce

                for(int i=0; i<pat.size(); i++)
                {
                    if(new_gari.matha_collusion(pat[i].pa))
                    {
                        health/=2;
                        pat.erase(pat.begin()+i);
                        fattor_blink_flag=40;
                        //text_health.setString(to_string((int)(health/2.75))+" %");
                    }
                    else if(new_gari.collusion(pat[i].pa))
                    {
                        health-=10;
                        pat.erase(pat.begin()+i);
                        fattor_blink_flag=40;
                    }
                    if(health<=0)
                    {
                        alive=0;
                        break;
                    }
                    text_health.setString(to_string((int)(health/2.75))+" %");
                }
                if(fattor_blink_flag>0)
                {
                    new_gari.blink();
                    fattor_blink_flag--;
                }
                else
                {
                    new_gari.thik_hoye_ja();
                }

                // stone move + erase
                for(int i=0; i<stone_coin.size(); i++)
                {
                    stone_coin[i].move();
                    if(stone_coin[i].f)
                    {
                        stone_coin[i].blink();
                        if(stone_coin[i].op_cnt>=80)
                            stone_coin.erase(stone_coin.begin()+i);
                    }
                }


                for(int i=0; i<stone_coin.size(); i++)
                {
                    stone_coin[i].print();
                }


                //fattor move + erase
                for(int i=0; i<pat.size(); i++)
                {
                    pat[i].move();
                    if(pat[i].f)
                    {
                        pat[i].blink();
                        if(pat[i].op_cnt>80)
                            pat.erase(pat.begin()+i);
                    }
                }


                for(int i=0; i<pat.size(); i++)
                {
                    pat[i].print();
                }
                coin_image_number++;
                coin_image_number%=10*framerate;
                window1.draw(coin[coin_image_number/framerate]);

                for(int i=0; i<ha_vec.size(); i++)
                {
                    ha_vec[i].move();
                    ha_vec[i].draw();
                }



                healthbar.setSize(Vector2f(health,50));
                window1.draw(healthbar);
                window1.draw(HealthBar);
                window1.draw(text_health);
                window1.draw(text_points);

            }else{
                window1.draw(gameover_sp);
            }

        }
        // cout<< "# "<<health << ' '<<point<<endl;
        window1.display();
    }
    return 0;
}
