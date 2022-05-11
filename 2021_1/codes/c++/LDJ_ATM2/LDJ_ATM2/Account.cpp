#include "Account.h"
#include "ATMachine.h"
#include "Statistics.h"

inline int Account::authenticate(int id, string password){
    if(nID == id && strPassword == password){
        return AUTHENTIFICATION_SUCCESS;
    }
    else{
        return AUTHENTIFICATION_FAIL;
    }
}

void Account::creat(int id, int money, string name, string password){
    nID = id;
    nBalance = money;
    strAccountName = name;
    strPassword = password;
}

int Account::check(int id, string password){
    if(authenticate(id, password) == AUTHENTIFICATION_FAIL){
        return AUTHENTIFICATION_FAIL;
    }
    else{
        return nBalance;
    }
} //return 값 : nBalance(잔고) or 인증실패(AUTHENTIFICATION_FAIL)


int Account::deposit(int id, string password, int money){
    if(authenticate(id, password)== false)
        return AUTHENTIFICATION_FAIL;
    else{
        nBalance = nBalance + money;
        return nBalance;
    }
}
//계좌이체할때 추가 deposit
int Account::deposit(int id, int money){
    nBalance = nBalance + money;
    return nBalance;
}

int Account::widraw(int id, string password, int money){
    if(authenticate(id, password)==false)
        return AUTHENTIFICATION_FAIL;
    else{
        if(nBalance >= money)
            nBalance = nBalance - money;
        else {cout << "잔액이 부족합니다" << endl;}
        
        return nBalance;
    }
}
