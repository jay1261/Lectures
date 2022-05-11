//
//  sub.c
//  cPrac19_2
//
//  Created by DongJae Lee on 2021/06/03.
//
#include <stdio.h>
#include "module.h"

void input_value(int *a, int *b){
    *a = 10;
    *b = 20;
}

void print_value(int a, int b){
    printf("a = %d, b = %d\n",a,b);
}
