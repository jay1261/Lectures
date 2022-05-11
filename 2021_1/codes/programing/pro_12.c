#include <stdio.h>
int age;

int main(){
    printf("나이를 입력하세요 ");
    scanf("%d",&age);

    if(age<=6){
        printf("무료");
    }
    else if(age<=12){
        printf("1000원");
    }
    else if(age<=19){
        printf("2000원");
    }
    else if(age<=69){
        printf("3000원");
    }


    return 0;
}