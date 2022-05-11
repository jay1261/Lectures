//
//  exchange.c
//  cPrac19_2
//
//  Created by DongJae Lee on 2021/06/03.
//

#include "module.h"

void exchange(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

