#ifndef Statistics_h
#define Statistics_h
#include <iostream>
#include "Account.h"
#include "ATMachine.h"

class Statistics{
public:
    static int sum(Account* pArray, int size);  //계좌 잔고 총합
    static int average(Account* pArray, int size);  //계좌 잔고 평균
    static int max(Account* pArray, int size);  //계좌 최고 값
};

#endif
