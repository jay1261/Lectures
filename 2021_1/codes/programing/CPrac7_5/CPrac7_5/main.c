#include <stdio.h>

void show_grade(void);
int n;

int main(){
    
    show_grade();
    
    return 0;
}


void show_grade(){
    printf("학년을 숫자만 입려하세요 :");
    scanf("%d", &n);
    
    switch(n){
        case 1:
            printf("%d 학년학생 입니다.\n",n);
            break;
            
        case 2:
            printf("%d 학년학생 입니다.\n",n);
            break;
            
        case 3:
            printf("%d 학년학생 입니다.\n",n);
            break;
            
        case 4:
            printf("%d 학년학생 입니다.\n",n);
            break;
        default:
            printf("잘못 입력하였습니다.\n");
            break;
    }
}
