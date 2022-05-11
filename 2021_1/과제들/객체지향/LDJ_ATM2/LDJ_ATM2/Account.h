#ifndef Account_h
#define Account_h

#include <iostream>
#include <string>
using namespace std;
using std::string;
#define AUTHENTIFICATION_FAIL -1    //계정 인증 실패
#define AUTHENTIFICATION_SUCCESS 1  //계정 인증 성공
#define BASE_ACCOUNT_ID 100         //계좌번호는 100번부터

class Account{
private:
    int nID;        //계좌번호
    int nBalance;   //잔고
    string strAccountName; //고객명
    string strPassword;     //계좌 비밀번호
    
private:
    inline int authenticate(int id, string passwd); //인증성공:true(1), 인증실패 : false(0) bool -> int로 변경
public:
    Account(){};
    void creat(int id, int money, string name, string password); //계좌 개설
    int check(int id, string password); //return 값 : nBalance(잔고) or 인증실패(AUTHENTIFICATION_FAIL)
    int getAcctID(){return nID;} //계좌번호 읽어오기
    int deposit(int id, string password, int money);
    int deposit(int id, int money);
    int widraw(int id, string password, int money);
    int getBalance(){return nBalance;}
    string getAccountName(){return strAccountName;}
};

#endif

