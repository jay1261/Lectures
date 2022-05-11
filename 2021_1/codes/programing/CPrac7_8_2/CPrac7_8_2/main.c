/*
 #include <stdio.h>
 
 int main(){
 int i;
 int sum = 0;
 
 for(i+1;i<=10;i++){
 sum = sum=i;
 }
 printf("1붙터 10까지의 합은 : %d\n, sum);
 return 0;
 
 */

#include <stdio.h>

int sum(int);

int main(){
    int n,s;
    
    scanf("%d",&n);
    s = sum(n);
    printf("1부터 %d 까지의 합 : %d\n",n,s);
    
    return 0;
}

int sum(int a){
    int add = 0;
    
    for(int i=1; i<=a; i++){
        add = add + i ;
    }
    
    return add;
    
}
