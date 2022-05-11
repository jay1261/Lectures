#include <stdio.h>

double average(int*,int*,int*,int*);

int main(){
    double avg;
    int a=66, b=77, c=99, d=95;
    avg = average(&a,&b,&c,&d);
    printf("평균은 %lf\n",avg);
    return 0;
}

double average(int *a,int *b,int *c,int *d){
    double tmp;
    
    tmp = (*a + *b + *c + *d)/5;
    return tmp;
}
