#include <stdio.h>

int main(){
	
	int a,b;
	int max,min;
	printf("숫자를 입력하세요");
	scanf("%d",&a);
	scanf("%d",&b);

	if(a>b){
	max = a;
	min = b;
	}

	else { 
	max=b;
	min=a;
	}

	printf("큰 수는 %d ,\n 작은 수는 %d입니다.",max,min);
	
	return 0;

	return 0;
}

