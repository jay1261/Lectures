#include <stdio.h>

double multiple(int*,int*);

int main(){
    int a,b;
    double result;
    printf("정수 2개 입력 :");
    scanf("%d%d",&a, &b);
    result = multiple(&a,&b);
    printf("결과는 : %0.1lf\n",result);
}

double multiple(int *c,int *d){
    double tmp;
    tmp = *c * *d;
    return tmp;
}
