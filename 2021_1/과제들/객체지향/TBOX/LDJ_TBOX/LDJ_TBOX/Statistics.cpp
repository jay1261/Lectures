//
//  Statistics.cpp
//  LDJ_TBOX
//
//  Created by DongJae Lee on 2021/05/27.
//
#include <iostream>
#include "Statistics.h"

int Statistics::totalSum(Screen* pScreen){
    int result = 0;
    Ticket** pTicket = pScreen->getTicketArray();
    
    for(int i=0; i<pScreen->getRowMax(); i++){
        for(int j=0; j<pScreen->getColMax(); j++){
            if(pTicket[i][j].getCheck() == SEAT_COMPLETION_MARK)
               result += pTicket[i][j].getPayAmount();
        }
    }
    return result;
}

int Statistics::totalCount(Screen* pScreen){
    int count = 0;

    Ticket** pTicket = pScreen->getTicketArray();
    
    for(int i=0; i<pScreen->getRowMax(); i++){
        for(int j=0; j<pScreen->getColMax(); j++){
            if(pTicket[i][j].getCheck() == SEAT_COMPLETION_MARK)
                count++;
        }
    }
    return count;
}

