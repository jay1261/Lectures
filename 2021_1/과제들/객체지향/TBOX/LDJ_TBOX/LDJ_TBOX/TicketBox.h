#ifndef TICKETBOX_H
#define TICKETBOX_H

#include "Screen.h"
#include "Statistics.h"
#define TICKETBOX_MANAGER_PWD "admin"

class TicketBox{
public:
    virtual Screen* selectMenu(){return NULL;}  //상영관 선택 메뉴(1,2,3관)
    void Initialize(){}
};

class KpuTicketBox : public TicketBox{
    EuropeScreen* pEuropeScreen;
    AsiaScreen* pAsiaScreen;
    PremiumScreen* pPremiumScreen;
public:
    KpuTicketBox();
    ~KpuTicketBox();
    Screen* selectMenu();
    void Initialize();
    void Manage();
};
#endif
