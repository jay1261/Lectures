//  6장 반복문 실습 1
#include <stdio.h>

int n,sum;

int main(){
    
    for (;;){
        sum=0;
        printf("임의의 양의 정수를 입력하세요");
        scanf("%d",&n);
        for(int i=0; i<=n; i++){
            sum += i;
            
        }
        
        
        printf("1부터 %d까지의 합 : %d\n",n,sum);
        
    }
        
}
