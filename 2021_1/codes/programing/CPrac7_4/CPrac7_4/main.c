#include <stdio.h>


void add(int add1, int add2);
void subtract(int sub1, int sub2);
void multiply(int mul1, int mul2);
void divide(int div1, int div2);

int main(){
    char menu;
    int a,b;
    
    for(;;){
        printf("두 정수를 입력하시오 : ");
        scanf("%d%d",&a,&b);
        
        printf(">> 원하는 메뉴를 선택하시오: ");
        scanf(" %c", &menu);
        
        switch(menu){
            case 'a':
                add(a,b);
                break;
            case 's':
                subtract(a,b);
                break;
            case 'm':
                multiply(a,b);
                break;
            case 'd':
                divide(a,b);
                break;
            case 'q':
                return 0;
            default :
                printf("잘못 입력하였습니다.");
        }
    }
    return 0;
}

void add(int add1,int add2){
    int sum = 0;
    sum = add1 + add2;
    printf("%d\n",sum);
}

void subtract(int sub1, int sub2){
    int sub = 0;
    sub = sub1 - sub2;
    printf("%d\n",sub);
}

void multiply(int mul1, int mul2){
    double mult = 0;
    mult = mul1 * mul2;
    printf("%f\n", mult);
}

void divide(int div1, int div2){
    double div =0;
    div = (div1 / div2);
    printf("%f\n",div);
}
