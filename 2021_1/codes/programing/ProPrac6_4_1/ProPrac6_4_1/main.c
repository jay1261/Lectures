//  6장 실습 4-1번문제
#include <stdio.h>

int n,sum=1;

int main(){

    printf("임의의 양의 정수 입력:");
    scanf("%d",&n);
    for (int i=1; i<=n; i++ ){
        sum = i*sum;
    }
    printf("%d factorial =%d\n",n,sum);
    
    
}
