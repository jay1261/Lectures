//
//  Pay.h
//  LDJ_TBOX
//
//  Created by DongJae Lee on 2021/05/26.
//

#ifndef PAY_H
#define PAY_H

#define MOBILE_PHONE_PAYMENT        1
#define BANK_TRANSFER_PAYMENT       2
#define CREDIT_CARD_PATMENT         3
#define MOBILE_PHONE_INTEREST_RATE  0.2     //수수료
#define BANK_TRANSFER_INTEREST_RATE 0.1
#define CREDIT_CARD_INTEREST_RATE   0.15
using namespace std;

class Pay{
public:
    virtual int charge(int amount) = 0; // 결제하기
};

class CardPay : public Pay{
    double interest;
public:
    CardPay(double rate){this->interest = rate;}
    int charge(int amount); //결제금액 = 티켓가격 + 티켓가격 * 수수료 비율
};


class BankTransfer : public Pay{
    double interest;
public:
    BankTransfer(double rate){this->interest = rate;}
    int charge(int amount);
};


class MobilePay : public Pay{
    double interest;
public:
    MobilePay(double rate){this->interest = rate;}
    int charge(int amount);
};

#endif /* Pay_h */
