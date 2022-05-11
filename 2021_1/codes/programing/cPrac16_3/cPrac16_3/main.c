//
//  main.c
//  cPrac16_3
//
//  Created by DongJae Lee on 2021/05/18.
//
#include <stdio.h>
#include <stdlib.h>

void sum_callbyref (int *, int *, int *);
int *sum_retbyref(int *, int *);


int main(){
    int a= 20, b = 30, res;

    
    sum_callbyref (&a, &b, &res);
    printf ("Data transfer by call by ref : %d + %d = %d\n", a, b, res);
    
    res = *sum_retbyref (&a, &b);
    printf ("Data transfer by return by ref : %d \n", res);
    
    return 0;
}


void sum_callbyref(int *pa, int*pb, int *pr){
    *pr = *pa + *pb;
}

int *sum_retbyref (int *pa, int *pb){ //중요
    int *res = (int *)malloc(sizeof(256));
    *res = *pa + *pb;
    
    return res;
}
