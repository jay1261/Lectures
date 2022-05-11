//8장 실습 2번
#include <stdio.h>


int main(){
    
    int ary[10]= {1,2,3,4,5,6,7,8,9,10};
    int sum=0;
    for(int i= 0; i<sizeof(ary)/sizeof(ary[0]); i++){
        sum += ary[i];
    }
    printf("%d\n",sum);
    
    
    char address[30];
    printf("주소를 입력:");
//    scanf("%s",address);
    gets(address);
    printf("%s\n",address);
    
    
    
    return 0;
}

