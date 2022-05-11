#include <stdio.h>
#define PI 3.141592

void area(int r);
void circumference(int r);

int main(){


    char option;
    int r;
    printf("(문자입력) 넓이는 A, 둘레는 C, 끝내려면 Q :");
    scanf("%c",&option);
    printf("반지름 입력");
    scanf("%d",&r);
    
    
    switch(option){
    case 'A':
    case 'a':
        area(r);
        break;
    case 'C':
    case 'c':
        circumference(r);
        break;
    case 'Q':
    case 'q':
        return (0);
    default:
        printf("다시 입력하시오");
        }
    
    
    return 0;
}


void area(int r){
    printf("넓이는 %f\n",PI*r*r);
}

void circumference(int r){
    printf("둘레는 %f\n",2*PI*r);
}
