//
//  Pay.cpp
//  LDJ_TBOX
//
//  Created by DongJae Lee on 2021/05/27.
//

#include <iostream>
#include "Pay.h"

int CardPay::charge(int amount){
    int result;
    result = amount + (amount * interest);
    return result;
}

int BankTransfer::charge(int amount){
    int result;
    result = amount + (amount * interest);
    return result;
}

int MobilePay::charge(int amount){
    int result;
    result = amount + (amount * interest);
    return result;
}
