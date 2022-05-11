//6장 실습 3-2번
#include <stdio.h>

int n;
int main(){
    //for문
    printf("출력할 구구단 단수를 입력:");
    scanf("%d",&n);
    printf("%d단\n",n);
    for(int i=1; i<=10;i++){
        printf("%d*%d = %d\n",n,i,n*i);
    }
    
    //while문
    printf("출력할 구구단 단수를 입력:");
    scanf("%d",&n);
    printf("%d단\n",n);
    int i=0;
    while(i<=10){
        printf("%d*%d = %d\n",n,i,n*i);
        i++;
    }
    
    return 0;
}
