#include <stdio.h>


int p, q, r;
void sum_global();
void sum_callbyval(int, int);
int sum_retbyval(int, int);
void sum_callbyref(int *, int*, int *);
int *sum_retbyref (int *, int *);


int main(){
    
    int a=20, b=30, res;
    
    p = a; q = b;
    
    sum_global ();
    printf ("After sum_global(): %d + %d = %d\n", p, q, r);
    
    sum_callbyval (a, b);
    printf ("Data transfer by call by val : a= %d, b = %d \n", a, b);

    res = sum_retbyval (a, b);
    printf ("Data transfer by return by val : %d \n", res);
    
    sum_callbyref (&a, &b, &res);
    printf ("Data transfer by call by ref : %d + %d = %d\n", a, b, res);
    
    res = *sum_retbyref (&a, &b);
    printf ("Data transfer by return by ref : %d \n", res);
return 0;
}

void sum_global(){
    r = p+q;
}

void sum_callbyval(int a, int b){
    a = 20;
    b = 30;
}

int sum_retbyval(int a, int b){
    int res;
    a =20; b = 30;
    res = a + b;
    
    return res;
}

void sum_callbyref(int *pa, int*pb, int *pr){
    *pr = *pa + *pb;
}

int *sum_retbyref (int *pa, int *pb){ //중요
    static int res;     //나중엔 스태틱안쓰고 동적메모리할당 쓴다.
    res = *pa + *pb;
    
    return &res;
}
