//
//  main.c
//  cPrac19_2
//
//  Created by DongJae Lee on 2021/06/03.
//

#include <stdio.h>
#include "module.h"

int main(){
    int a, b;
    input_value(&a, &b);
    print_value(a,b);
    exchange(&a,&b);
    print_value(a,b);
    
    return 0;
}
