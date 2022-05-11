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

void sum(void);

int main(){
    sum();
    
    return 0;
}
void sum(){
    int i, add;
    for (i=1; i<=10; i++){
        add = add+i;
    }
    printf("1부터 10까지의 합은 : %d\n",add);
}
