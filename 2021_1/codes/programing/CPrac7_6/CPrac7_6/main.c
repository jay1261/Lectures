#include <stdio.h>

/*int main(){
    int i, factorial = 1;
    
    for(i=1; i <= 20; i++){
        factorial = factorial * i;
    }
    printf("1부터 %d까지의 곱 : %dl\n",n,factorial);
    
    
    return 0;
}*/

long unsigned factorial(int r);


int main(){
    int n;
    long unsigned f;
    
    printf("임의의 양의 정수를 입력 :");
    scanf("%d",&n);
    
    f = factorial(n);
    
    printf("1부터 %d 까지의 곱 : %lu\n",n,f);
}

long unsigned factorial(int r){
    int fact = 1;
    for(int i=1; i<=r; i++){
        fact = fact * i;
    }
    
    return fact;
}
