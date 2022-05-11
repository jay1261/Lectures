//
//  main.cpp
//  leedongjae
//
//  Created by DongJae Lee on 2021/05/13.
//
#include <iostream>
#include <string>
using namespace std;
//MP3 클래스
class MP3{
    string title;
public:
    MP3(){}
    MP3(string title){this->title = title;}
    string getTitle(){return title;}
};

//Player클래스
class Player{
    MP3 mp3;
public:
    virtual void download(MP3 mp3){cout << mp3.getTitle()+"를 다운로드함" << endl;}
    virtual void play(){cout << mp3.getTitle() + "를 재생함" << endl;}
};

//에어팟
class AirPods : public Player{
    MP3 mp3;
public:
    virtual void download(MP3 mp3){
        this->mp3 = mp3;
        cout << "애플 AirPods " << mp3.getTitle()+"를 다운로드함" << endl;
    }
    virtual void play(){
        cout << "애플 AirPods " << mp3.getTitle() +"를 재생함" << endl;
    }
};

//갤럭시버즈
class GalaxyBuds : public Player{
    MP3 mp3;
public:
    virtual void download(MP3 mp3){
        this->mp3 = mp3;
        cout << "삼성 GalaxyBuds " << mp3.getTitle()+"를 다운로드함" << endl;
    }
    virtual void play(){
        cout << "삼성 GalaxyBuds " << mp3.getTitle()+"를 재생함" << endl;
    }
};
//소니 이어버즈
class EarBuds : public Player{
    MP3 mp3;
public:
    virtual void download(MP3 mp3){
        this->mp3 = mp3;
        cout << "소니 EarBuds " << mp3.getTitle()+"를 다운로드함" << endl;
    }
    virtual void play(){
        cout << "소니 EarBuds " << mp3.getTitle()+"를 재생함" << endl;
    }
};
//Shop클래스
class Shop{
public:
    virtual Player* selectItem(){return NULL;}
};
//MediaShop클래스
class MediaShop : public Shop{
public:
    Player* selectItem(){
        cout << endl
             << "------------------" << endl
             << "    플레이어 선택" <<endl
             << "------------------" << endl
             << "1. 애플 AirPods" <<endl
             << "2. 삼성 GalaxyBuds" << endl
             << "3. 소니 EarBuds" << endl << endl;
        
        cout << "아이템 선택(1~3) 그외 종료 : " ;
        int num;
        cin >> num;
        cout << endl;
        AirPods *pAirPods = new AirPods;
        GalaxyBuds *pGalaxyBuds = new GalaxyBuds;
        EarBuds *pEarBuds = new EarBuds;
        switch(num){
            case 1 :
                return pAirPods;
//                break;
            case 2 :
                return pGalaxyBuds;
//                break;
            case 3 :
                return pEarBuds;
//                break;
            default :
                cout<< "종료합니다.\n";
                exit(0);
        }
    }
};


int main(){
    MediaShop shop;
    Player* pPlayer;
    
    while(true){
        pPlayer = shop.selectItem();
        MP3 mp3("sg_wannabe");
        
        pPlayer->download(mp3);
        pPlayer->play();
    }
    return 0;
}



