// 6장 실습 2
#include <stdio.h>
int score;

int main(){
    
    for (;;){
        printf("점수를 입력하시오");
        scanf("%d",&score);
        
        if(score>=90){
            printf("학점은 A입니다.\n");
        }
        else if(score>=80){
            printf("학점은 B입니다.\n");
        }
        else if(score>=70){
            printf("학점은 C입니다.\n");
        }
        else if(score>=60){
            printf("학점은 D입니다.\n");
        }
        else if (score<=0){
            printf("종료합니다\n");
            break;
        }
        
        else printf("학점은 F입니다.\n");
        
    
    
    }
    
    
    
}
