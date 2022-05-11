#include <stdio.h>

void print_double(double, int);

int main(){
    double ary[] = {0.1, 0.3, 0.5, 0.7, 0.9};
    
    for(int i=0; i<sizeof(ary)/sizeof(ary[0]); i++)
    print_double(ary[i],i);
    
    return 0;
}


void print_double(double a, int n){
    
    
    printf("%dth function %0.1lf\n", n+1 , a);
    
}
