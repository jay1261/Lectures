//  6장 실습 5번문제
#include <stdio.h>
#define PI 3.141592

char c;
int r;
int main(){
    for(;;){
    printf("문자를 입력하시오:\n");
    scanf("%c",&c);
        
        if(c=='A'){
            printf("넓이를 구할 원의 반지름을 입력하세요:");
            scanf("%d",&r);
            printf("원의 넓이는 %f\n",PI*r*r);
        }
        else if(c=='C'){
            printf("둘레를 구할 원의 반지름을 입력하세요:");
            scanf("%d",&r);
            printf("원의 둘레는 %f\n",2*PI*r);
        }
        else if (c=='Q') break;
    
    
    
    }
    
    return 0;
    
}
