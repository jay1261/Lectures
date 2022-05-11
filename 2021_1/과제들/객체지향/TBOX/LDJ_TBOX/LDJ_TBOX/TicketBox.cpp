//
//  TicketBox.cpp
//  LDJ_TBOX
//
//  Created by DongJae Lee on 2021/05/27.
//

#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
using namespace std;

KpuTicketBox::KpuTicketBox(){}
KpuTicketBox::~KpuTicketBox(){
    delete pEuropeScreen;
    delete pAsiaScreen;
    delete pPremiumScreen;
}

Screen* KpuTicketBox::selectMenu(){
    int select = 0;

    cout << "------------------------------" << endl
         << "\t\t상영관 메인 메뉴\t" <<endl
         << "------------------------------" << endl;
    cout << "1.\t유럽\t영화\t1관" << endl
         << "2.\t아시아\t영화\t2관" << endl
         << "3.\t프리미엄\t영화\t3관" << endl
         << "9.\t통계\t관리\t" << endl << endl;
    cout << "선택(1~3) 그외 종료 : ";
    
    cin >> select;
    switch (select) {
        case 1:
            return pEuropeScreen;
        case 2:
            return pAsiaScreen;
        case 3:
            return pPremiumScreen;
        case 9:
            Manage();
            return 0;
        default:
            return 0;
    }
}

void KpuTicketBox::Initialize(){
    //Screen(영화제목,티켓가격,좌석(nRowMax),좌석(nCalMax))
    pEuropeScreen = new EuropeScreen("노팅힐", 10000, 10, 10);
    pAsiaScreen = new AsiaScreen("기생충", 12000, 10, 10);
    pPremiumScreen = new PremiumScreen("콜 오브 와일드", 30000, 6, 6);
}

void KpuTicketBox::Manage(){
    string pwd;
    while(1){
        cout << "------------------------------" << endl
             << "\t\t관리자 메뉴\t" <<endl
             << "------------------------------" << endl;
        cout << "관리자 비밀번호 입력 : ";
        cin >> pwd;
        if(pwd == TICKETBOX_MANAGER_PWD){
            cout << "1. 유럽영화 상영관 결제 금액 : " << Statistics::totalSum(pEuropeScreen) << endl;
            cout << "2. 아시아영화 상영관 결제 금액 : " << Statistics::totalSum(pAsiaScreen) << endl;
            cout << "3. 프리미엄영화 상영관 결제 금액 : " << Statistics::totalSum(pPremiumScreen) << endl;
            cout << "4. 전체 티켓 판매량 : "
                 << Statistics::totalCount(pEuropeScreen) + Statistics::totalCount(pAsiaScreen) + Statistics::totalCount(pPremiumScreen)<< endl;
            break;
        }
        else
            cout << "비밀번호 오류" << endl;
    }
}
