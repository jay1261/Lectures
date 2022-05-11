#include <stdio.h>
void ascii(int);
void convert(int);
void expo(int, int);
void sum(int, int);	

int main(){
	int i,j;
	printf("유닉스기초 과제2, 2019152051 이동재\n\n");

	printf("**********입력**********\n");
	printf("숫자(정수)를 차례로 2개 입력하시오\n");
	printf("숫자1: ");
	scanf("%d", &i);
	printf("숫자2: ");
	scanf("%d", &j);

	printf("\n**********출력**********\n");	
	ascii(i);	
	convert(i);
	expo(i,j);
	sum(i,j);
	printf("*************************\n");	

	return 0;
}
