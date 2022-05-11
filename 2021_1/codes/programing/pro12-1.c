#include <stdio.h>
int age, a=0;

int main(){
    printf("나이를 입력하세요 ");
    scanf("%d",&age);

    a = (age<=6) ? printf("무료") : (age<=12) ? printf("1000원") : (age<=19) ? printf("2000원") : (age<=69) ? printf("3000원") : printf("무료");;;;




    return 0;
}