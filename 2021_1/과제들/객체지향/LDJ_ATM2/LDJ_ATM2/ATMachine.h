#ifndef ATMachine_h
#define ATMachine_h

#include <iostream>
#include "Account.h"
#include "ATMachine.h"
using namespace std;
using std::string;
#define NEGATIVE_ATM_BALANCE -10 //잔액부족

class ATMachine{
private:
    Account *pAcctArray; //동적 생성된 고객계좌 배열 포인터
    int nMachineBalance; //ATM잔고
    int nMaxAccountNum; //동적 생성된 고객계좌 배열 크기
    int nCurrentAccountNum; //개설된 고객 계좌 수
    string strManagerPassword; //관리자 비밀번호
    bool isManager(string password); //매니저 암호 확인
    void displayReport();   //통계 화면 처리
public:
    ATMachine(int size, int balance, string password); //계좌배열크기, ATM 잔고, 관리자 암호 초기화
    ~ATMachine();
    ATMachine(ATMachine& atm);
    void displayMenu();     //ATM 기능 선택 화면
    void createAccount();   //계좌 개설
    void checkMoney();      //계좌 조회
    void depositMoney();
    void widrawMoney();
    void transfer();    //계좌이체
    void managerMode(); //고객 관리
};

#endif
