#include <stdio.h>

void swap1(int,int);
void swap2(int*, int*);

int main(){
    int a=30, b=50;
    printf("a = %d, b = %d",a,b);
    
    
    return 0;
}

void swap1(int a, int b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
