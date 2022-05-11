//
//  main.c
//  cPrac15_1
//
//  Created by DongJae Lee on 2021/05/11.
//
#include <stdio.h>

int *multiple(int *, int *);
void swap_val(int m, int n);
void swap_ref(int *, int *);

int main(){
    int a = 30, b = 50, mult_res = 0;
    int *pa = &a, *pb = &b;
    printf("a = %d, b = %d\n",a,b);     //a,b의 값 출력
    
    swap_val(a,b);
    printf("a = %d, b = %d\n",a,b);     //a,b의 값 스왑 call by value로 출력
    
    swap_ref(pa,pb);
    printf("a = %d, b = %d\n",a,b);     //a,b의 값 스왑 call by ref로 출력
    
    mult_res = *multiple(pa,pb);
    printf("곱한 값 = %d\n", mult_res);    //곱한 값 출력
    return 0;
}

void swap_val(int m, int n){
    int tmp = 0;
    tmp = m;
    m = n;
    n = tmp;
    printf("m = %d, n = %d\n",m,n);
}

void swap_ref(int *m, int *n){
    int tmp = 0;
    tmp = *m;
    *m = *n;
    *n = tmp;
}

int *multiple(int *m, int *n){
    static int res = 0;
    res = *m * *n;
    
    return &res;
}
