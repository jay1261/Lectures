//
//  Screen.h
//  LDJ_TBOX
//
//  Created by DongJae Lee on 2021/05/26.
//

#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include "Ticket.h"
#include "Pay.h"

using namespace std;

class Screen{
protected:
    int nTicketPrice;           //티켓가격
    int nRowMax, nColMax;       //좌석 행과 열 최대 값
    int nCurrentReservedID;     //발급된 마지막 예약 번호
    Ticket **pSeatArray;        //스크린 좌석에 대한 티켓 배열
    string strMovieName;        //스크린 상영중인 영화 제목
public:
    Screen(string name, int price, int r, int c);
    ~Screen();  
    void showSeatMap();                 //좌석 예약 여부 맵으로 보기
    void showMovieMenu();               //영화 예매 메뉴 , virtual에서 수정
    virtual void showMovieInfo() = 0;   //영화 소개 정보
    void reserveTickets();
    int getTicketPrice(){return nTicketPrice;}
    void Payment();
    int getRowMax(){return nRowMax;}    
    int getColMax(){return nColMax;}
    Ticket** getTicketArray(){return pSeatArray;}
};

class EuropeScreen : public Screen{
public:
    EuropeScreen(string name, int price, int r, int c): Screen(name, price, r, c){}
    void showMovieInfo();
};

class AsiaScreen : public Screen{
public:
    AsiaScreen(string name, int price, int r, int c): Screen(name, price, r, c){}
    void showMovieInfo();
};

class PremiumScreen : public Screen{
public:
    PremiumScreen(string name, int price, int r, int c): Screen(name, price, r, c){}
    void showMovieInfo();
};

#endif /* Screen_h */
