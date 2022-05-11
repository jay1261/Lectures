//
//  main.c
//  cPrac19_1
//
//  Created by DongJae Lee on 2021/06/03.
//

#include <stdio.h>
void input_value(int *, int *);

//
void print_value(int, int);
void exchange(int *, int *);

int main(){
    int a, b;
    input_value(&a, &b);
    print_value(a,b);
    exchange(&a,&b);
    print_value(a,b);
    
    return 0;
}

