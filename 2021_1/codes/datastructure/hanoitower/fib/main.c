#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>   //4개 외우기


int fib(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return (fib(n-1)+fib(n-2));
}



int fib_iter(int n){
    
     
    if (n==0) return 0;
    else if(n==1) return 1;
    else {
        int pp = 0;
        int p= 1;
        int result = 0;
        
        for (int i=2; i<=n; i++){
            result = p + pp;
            pp=p;
            p =result;
            
        }
        return result;
    }
    
}



int main(void){
    int i = 10;
    int result =0;
    
    clock_t start,stop;
    double duration;
    start = clock();
    //result= fib(i);
    result = fib_iter(i);
    stop = clock();
    duration = (double)(stop - start)/CLOCKS_PER_SEC;
    printf("수행시간은 %f초 입니다\n",duration);
    printf("%d\n",result);
    
    
    return 0;
}


