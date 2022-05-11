//
//  sub.c
//  cPrac19_1
//
//  Created by DongJae Lee on 2021/06/03.
//

#include <stdio.h>

void print_value(int a, int b){
    printf("a = %d, b = %d\n",a,b);
}

void exchange(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
