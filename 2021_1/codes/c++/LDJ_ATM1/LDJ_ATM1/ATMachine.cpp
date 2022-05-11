#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"
//생성자
ATMachine::ATMachine(int size, int balance, string password){
    nCurrentAccountNum =0;
    nMaxAccountNum = size;
    pAcctArray = new Account[nMaxAccountNum];
    nMachineBalance = balance;
    strManagerPassword = password;
    
}
//소멸자
ATMachine::~ATMachine(){
    if(pAcctArray) delete[] pAcctArray;
}
//복사생성자
ATMachine::ATMachine(ATMachine &atm){
    nMaxAccountNum = atm.nMaxAccountNum;
    pAcctArray = new Account[nMaxAccountNum];
    nMachineBalance = atm.nMachineBalance;
    nCurrentAccountNum = atm.nCurrentAccountNum;
    strManagerPassword = atm.strManagerPassword;
    
    for(int i=0; i<nMaxAccountNum; i++){
        pAcctArray[i] = atm.pAcctArray[i];
    }
}


void ATMachine::displayMenu(){
    cout<<"----------------------"<<endl
        <<"-      KPU bank      -"<<endl
        <<"----------------------"<<endl;
    
    cout<< "1. 계좌 개설\n"
        << "2. 계좌 조회\n"
        << "3. 계좌 입금\n"
        << "4. 계좌 출금\n"
        << "5. 계좌 이체\n"
        << "6. 고객 관리\n"
        << "9. 업무 종료\n"
        << endl;
}

void ATMachine::createAccount(){
    cout << "------ 개설 ------" << endl;
    cout << "이름 입력: ";
    char name[30];
    cin >> name;
    cout << "암호 입력: ";
    char password[10];
    cin >> password;
    
    int ID = BASE_ACCOUNT_ID + nCurrentAccountNum;
    pAcctArray[nCurrentAccountNum].creat(ID, 0, name, password);
    
    cout << name << "님" << ID
         << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다"<<endl;
    nCurrentAccountNum++;
}

void ATMachine::checkMoney(){
    
    cout << "------ 조회 ------" <<endl;
    int ID;
    
    while(true){    //예외처리 시도
        cout << "계좌번호 입력: ";
        cin >> ID;
        if(ID>99 && ID<201){
            break;
        }
        else
            cout<<"잘못 입력하셨습니다." << endl;
    }
    char password[10];
    cout << "비밀번호 입력: ";
    cin >> password;
        
    
    
    for(int i = 0; i<nCurrentAccountNum; i++){
        if(pAcctArray[i].getAcctID() == ID){
            cout << "현재 잔액: "
            << pAcctArray[i].check(ID,password) << endl;
        }
    }
}

void ATMachine::depositMoney(){
    cout << "------ 입금 ------" << endl;
    cout << "계좌번호 입력: " ;
    int ID;
    cin >> ID;
    cout << "비밀번호 입력: ";
    char password[10];
    cin >> password;
    
    
    for(int i = 0; i<nCurrentAccountNum; i++){
        if(pAcctArray[i].getAcctID() == ID){
            cout << "입금액 입력 :" ;
            int money;
            cin >> money;
            pAcctArray[i].deposit(ID, password, money);
            cout << "현재 잔액: " << pAcctArray[i].check(ID, password) << endl;
        }
    }
}

void ATMachine::widrawMoney(){
    cout << "------ 출금 ------" << endl;
    cout << "계좌번호 입력: " ;
    int ID;
    cin >> ID;
    cout << "비밀번호 입력: ";
    char password[10];
    cin >> password;
    
    for(int i = 0; i<nCurrentAccountNum; i++){
        if(pAcctArray[i].getAcctID() == ID){
            cout << "출금액 입력 :";
            int money;
            cin >> money;
            pAcctArray[i].widraw(ID, password, money);
            cout << "현재 잔액 : "<< pAcctArray[i].check(ID, password) << endl;
        }
    }
}

void ATMachine::transfer(){
    cout << "------ 이체 ------" << endl;
    cout << "계좌번호 입력 : ";
    int ID;
    cin >> ID;
    cout << "비밀번호 입력 : ";
    char password[10];
    cin >> password;

    for(int i=0; i<nCurrentAccountNum; i++){
        if(pAcctArray[i].getAcctID() == ID){
            cout << "이체계좌 입력 : ";
            int ID_to;
            cin >> ID_to;
            //이체 계좌 확인하고
            cout << "이체금액 입력 : ";
            int money;
            cin >> money;
            
            cout << "현재 잔액 : " << pAcctArray[i].widraw(ID, password, money) << endl;
            
            for(int j=0; j<nCurrentAccountNum; j++){
                if(pAcctArray[j].getAcctID() == ID_to && pAcctArray[j].getBalance() >= money){
                    pAcctArray[j].deposit(ID_to, money);
                }
            }
        }
    }
}

bool ATMachine::isManager(string password){
    if(strManagerPassword == password)
        return AUTHENTIFICATION_SUCCESS;
    else
        return AUTHENTIFICATION_FAIL;
}

void ATMachine::managerMode(){
    cout << "------ 관리 ------"<< endl;
    cout << "관리자 비밀번호 입력 : ";
    char password_admin[10];
    cin >> password_admin;
    if(isManager(password_admin)){
        cout << endl <<"관리자입니다." << endl << endl;
        displayReport();
    }
}

void ATMachine::displayReport(){
    cout << "------ 계좌 목록 ------" << endl
         << "---------------------" << endl;
    
    for(int i=0; i<nCurrentAccountNum; i++){
        cout << pAcctArray[i].getAccountName() << "\t"
             << pAcctArray[i].getAcctID() << "\t\t"
             << pAcctArray[i].getBalance() << "원" << "\t"
             << endl;
             
    }
    cout << "---------------------" << endl;
    cout << "ATM 현재 잔고 : " << "\t\t"
         << nMachineBalance + Statistics::sum(pAcctArray,nCurrentAccountNum) << "원" << endl
         << "고객 잔고 총액 : " << "\t\t"
         << Statistics::sum(pAcctArray,nCurrentAccountNum) << "원"
         << "(총" << nCurrentAccountNum << "명)" << endl
         << "고객 잔고 평균 : " << "\t\t"
         << Statistics::average(pAcctArray,nCurrentAccountNum) << "원" << endl
         << "고객 잔고 최고 : " << "\t\t"
         << Statistics::max(pAcctArray,nCurrentAccountNum) << "원" << endl <<endl;
}
