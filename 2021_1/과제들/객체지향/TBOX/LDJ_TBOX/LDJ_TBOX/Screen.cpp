//
//  Screen.cpp
//  LDJ_TBOX
//
//  Created by DongJae Lee on 2021/05/27.
//

#include <iostream>
#include <string>
#include "Screen.h"
using namespace std;

Screen::Screen(string name, int price, int r, int c){
    strMovieName = name;
    nRowMax = r;
    nColMax = c;
    nTicketPrice = price;
    pSeatArray = new Ticket*[nRowMax];
    for(int r = 0; r<nRowMax; r++){
        pSeatArray[r] = new Ticket[nColMax];
    }
    for(int i=0; i<nRowMax; i++){
        for(int j=0; j<nColMax; j++){
            pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
        }
    }
}

Screen::~Screen(){
    for(int i=0; i<nRowMax; i++)
        delete []pSeatArray[i];
    delete []pSeatArray;
}

void Screen::showSeatMap(){
    cout << "\t\t[ 좌석 예약 현황 ]" << endl;
    cout << "\t\t";
    for(int i=0; i<nRowMax; i++){
        cout << "[" << i+1 << "]" << '\t';
    }
    cout << endl;
    for(int i=0; i<nRowMax; i++){
        cout << i+1 << ']' << '\t' << '\t';
        for(int j=0; j<nColMax; j++){
            cout << '[' << pSeatArray[i][j].getCheck() << ']' << '\t';
        }
        cout << endl;
    }
}

void Screen::showMovieMenu(){
    cout << "-----------------------------------" << endl
         << "\t\t영화 메뉴 - "<< strMovieName << endl
         << "-----------------------------------" << endl;
    cout << "1. 상영 영화 정보" << endl
         << "2. 좌석 예약 현황" << endl
         << "3. 예약 하기" << endl
         << "4. 결제 하기" << endl
         << "7. 메인 메뉴 이동" << endl;
}

void EuropeScreen::showMovieInfo(){
    cout << "-----------------------------------" << endl
         << "\t\t" << strMovieName << endl
         << "-----------------------------------" << endl;
    cout << "영화관 : 유럽영화 1관" << endl
         << "주인공 : 줄리아 로버츠, 휴 그랜트" << endl
         << "줄거리 : 윌리엄 대커(휴 그랜트)는 노팅힐에서 여행관련 서적을 판매하는 자영 책방을 경영하는 사람이다..." << endl
         << "가격 : 10000" << endl;
}

void AsiaScreen::showMovieInfo(){
    cout << "-----------------------------------" << endl
         << "\t\t" << strMovieName << endl
         << "-----------------------------------" << endl;
    cout << "영화관 : 아시아영화 2관" << endl
         << "주인공 : 송강호, 이선균 ..." << endl
         << "줄거리 : 여러 사업에 도전했지만 실패한 아버지 김기택(송강호)... " << endl
         << "가격 : 12000" << endl;
}

void PremiumScreen::showMovieInfo(){
    cout << "-----------------------------------" << endl
         << "\t\t" << strMovieName << endl
         << "-----------------------------------" << endl;
    cout << "영화관 : 프리미엄영화 3관" << endl
         << "주인공 : 해리슨 포드, 카라 지, ..." << endl
         << "줄거리 : 1890년대 골드러시 시대,금광이 발견되었다는 소식에 일확천금을 노린 수많은 사람들이 알래스카로 몰려든다..." << endl
         << "가격 : 30000" << endl;
}

void Screen::reserveTickets(){
    int row, col;
    int rID = 100 + nCurrentReservedID;
    while(1){
        cout << "\t[ 좌석 예약 ]" << endl
             << "좌석 행 번호 입력(1 - " << nRowMax << ") : ";
        cin >> row;
        cout << "좌석 열 번호 입력(1 - " << nColMax << ") : ";
        cin >> col;
        
        //이미 예약되어있는거 처리
        if(pSeatArray[row-1][col-1].getCheck() == SEAT_EMPTY_MARK){
            pSeatArray[row-1][col-1].setSeat(row, col);
            pSeatArray[row-1][col-1].setReservedID(rID);
            pSeatArray[row-1][col-1].setCheck(SEAT_RESERVED_MARK);
            nCurrentReservedID++;
            cout << "행[" << row << "] "
                 << "열[" << col << "] "
                 << rID << " 예약 번호로 접수되었습니다." << endl << endl;
            break;
        }
        else
            cout << "그 좌석은 예약할 수 없습니다." <<endl;
    }

}

void Screen::Payment(){
    int rID;
    Ticket *pcheckID = NULL;
    int loop = 1;
    while(loop){
        cout << "\t[ 좌석 예약 결제 ]" << endl
             << "예약 번호 입력 : " ;
        cin >> rID;
        for(int i=0; i<nRowMax; i++){
            for(int j=0; j<nColMax; j++){
                if(pSeatArray[i][j].getReservedID() == rID){
                    pcheckID = &pSeatArray[i][j];
                    loop = 0;
                }
            }
        }
        if(pcheckID == NULL)
            cout << "예약 번호 오류" <<endl;
    }
    cout << "-----------------------------------" << endl
         << "\t\t 결제 방식 선택 \t\t" << endl
         << "-----------------------------------" << endl;
    cout << "1. 모바일 결제" << endl
         << "2. 은행 이체 결제" << endl
         << "3. 카드 결제" << endl << endl;
    
    cout << "결제 방식(1~3) : ";
    int method;
    cin >> method;
    
    char num[12], name[10]; //이름 다시

    Pay *pPaymethod = NULL;
    switch (method) {
        case 1:
            pPaymethod = new MobilePay(MOBILE_PHONE_INTEREST_RATE);
            pcheckID->setPayMethod(MOBILE_PHONE_PAYMENT);
            pcheckID->setPayAmount(pPaymethod->charge(getTicketPrice()));
            cout << "\t\t[ 모바일 결제 ]" << endl
                 << "핸드폰 번호 입력(11자리수) : ";
            cin >> num;
            cout << "이름 : ";
            cin >> name;
            cout << "모바일 결제가 완료되었습니다. :" << pcheckID->getPayAmount() << endl << endl;
            pcheckID->setCheck(SEAT_COMPLETION_MARK);
            break;
        case 2:
            pPaymethod = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
            pcheckID->setPayMethod(BANK_TRANSFER_PAYMENT);
            pcheckID->setPayAmount(pPaymethod->charge(getTicketPrice()));
            cout << "\t\t[ KPU 은행 결제 ]" << endl
                 << "은행 번호 입력(12자리수) : ";
            cin >> num;
            cout << "이름 : ";
            cin >> name;
            cout << "KPU 은행 결제가 완료되었습니다. :" << pcheckID->getPayAmount() << endl << endl;
            pcheckID->setCheck(SEAT_COMPLETION_MARK);
            break;
        case 3:
            pPaymethod = new CardPay(CREDIT_CARD_INTEREST_RATE);
            pcheckID->setPayMethod(CREDIT_CARD_PATMENT);
            pcheckID->setPayAmount(pPaymethod->charge(getTicketPrice()));
            cout << "\t\t[ 신용카드 결제 ]" << endl
                 << "카드 번호 입력(12자리수) : ";
            cin >> num;
            cout << "이름 : ";
            cin >> name;
            cout << "신용카드 결제가 완료되었습니다. :" << pcheckID->getPayAmount() << endl << endl;
            pcheckID->setCheck(SEAT_COMPLETION_MARK);
            break;
        default:
            break;
    }
}
