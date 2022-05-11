#include <stdio.h>
#include <string.h>
typedef struct friend{
    char name[32];
    int phonenumber;
    char hobby[256];
    char address[256];
}friend;



int main(){
    friend lee;
    strcpy(lee.name,"leeD");
    strcpy(lee.hobby,"baseball");
    strcpy(lee.address,"산기대");
    lee.phonenumber = 1026706051;
    
    printf("이름 : %s, 취미 : %s, 주소 : %s, 전화번호 : %d\n", lee.name, lee.hobby, lee.address, lee.phonenumber);
    //friend kim;
    
    
    
    return 0;
}

