//  6장 실습 4-2
#include <stdio.h>
int n;
int main(){
    //for 문
    for (int i=2; i<=9;i++){
        
        for (int j=1;j<=9;j++){
            printf("%d * %d=%d\n",i,j,i*j);
    }
 }
    //while 문
    int i=2;
    while(i<=9){
        int j=1;
        while(j<=9){
            printf("%d*%d =%d\n",i,j,i*j);
            j++;
        }
        i++;
    }
    
    
    
    
    
    
}
