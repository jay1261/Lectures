#include <stdio.h>

int input(void);
int sum(int, int);
void print(int, int, int);


int main(){
    int a,b,c;
    
    a = input();
    b = input();
    c = sum(a, b);
    print(a,b,c);
    
    return 0;
}

int input(void){
    int n;
    printf("숫자를 입력하세요 :");
    scanf("%d", &n);
    return n;
}

int sum(int a, int b){
    int sum1;
    sum1 = a + b;
    return sum1;
}

void print(int x, int y, int z){
    printf("첫번째 수 %d,두번째 수 %d, 합은 %d\n", x, y, z);
}
