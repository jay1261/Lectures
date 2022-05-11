#include <iostream>
#include "Statistics.h"


int Statistics::sum(Account* pArray, int size){
    int res = 0;
    for(int i=0; i<size; i++){
        res = res + pArray[i].getBalance();
    }
    return res;
}

int Statistics::average(Account* pArray, int size){
    int res;
    res = Statistics::sum(pArray,size)/size;
    return res;
}

int Statistics::max(Account* pArray, int size){
    int Max = pArray[0].getBalance();
    for(int i=0; i<size; i++){
        if(pArray[i].getBalance() > Max)
            Max = pArray[i].getBalance();
    }
    return Max;
}
