//  6장 실습 3
#include <stdio.h>
int n,sum1,sum2;

int main(){
    //for문
    printf("양의 정수를 입력하시오");
    scanf("%d", &n);
    
    for(int i=0; i<=n; i++){
        if(i%2 == 0) sum1+=i;
        else sum2+=i;
    
    
    }
    printf("1부터 n까지 \n짝수의 합:%d,\n홀수의 합:%d\n", sum1,sum2);
    
    //while 문
    n=0; sum1=0; sum2=0;
    printf("양의 정수를 입력하시오");
    scanf("%d", &n);
    int i=0;
    while(i<=n){
        if(i%2 == 0) sum1+=i;
        else sum2+=i;
        i++;

    }
    printf("1부터 n까지 \n짝수의 합:%d,\n홀수의 합:%d\n", sum1,sum2);
    

    
    
    
    
    
    
    
    
    
    return 0;
}

