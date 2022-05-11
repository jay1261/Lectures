//6장 실습 6번
#include <stdio.h>
int n;
int sum_odd,sum_even;

int main(){
    printf("정수 하나를 입력하시오");
    scanf("%d",&n);
    int i,j,cnt;
    for (cnt=0, i=1, j=2; cnt<n; ++cnt, i+=2, j+=2)
    sum_odd += i;
    sum_even += j;
    
    printf("홀수 합 = %d, 짝수 합 = %d", sum_odd, sum_even);
    
    
    int sum_odd=0 , sum_even=0;
    printf("정수 하나를 입력하시오");
    scanf("%d",&n);
    cnt=0; i=1; j=2;
    while(cnt<n){
        
        sum_odd += i;
        sum_even += j;
        
        ++cnt; i+=2; j+=2;
    }
    printf("홀수 합 = %d, 짝수 합 = %d", sum_odd, sum_even);
    
    
    
    
    
    
    return 0;
    
}
