// 임의의 수를받아 0부터 첫 n개의 짝수의 합과 홀수의 합 구하기
#include <stdio.h>

void sum_of_odd(int odd);
void sum_of_even(int even);
int n;

int main(){
    
    sum_of_odd(n);
    sum_of_even(n);
    
    return 0;
}

void sum_of_odd(int odd){
    int i,sum_odd = 0;
    printf("정수를 입력하시오 : ");
    scanf("%d", &n);
    
    for(odd = 0, i = 1; odd < n; ++odd, i += 2){
        sum_odd += i;
        }
    printf("%d\n",sum_odd);
    }

void sum_of_even(int even){
    int j,sum_even = 0;
    printf("정수를 입력하시오 : ");
    scanf("%d", &n);
    
    for(even = 0, j = 2; even < n; ++even, j += 2){
        sum_even += j;
        }
    printf("%d\n",sum_even);
    }
