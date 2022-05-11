#include <stdio.h>
void getCost(int rate, int amount);

int main(){
       char type;	//지역
       int amount = 0; //전력 사용량(단위 Kw)
       int cost = 0;	//요금
       int rate = 1;	//할증%

       printf("*****실습분제02  2019152051 이동재 *****\n\n");
       printf("*****지역을 입력하세요*****\n");
       printf("주거지역: R\n상업지역: C\n공업지역: I\n");
       printf("***************************\n");
       printf("입력: ");
       scanf("%c", &type);
       printf("전력사용량을 입력하세요(정수만 입력, 단위Kw) :");
       scanf("%d", &amount);

       switch(type){
       	case 'R': case 'r':
       		printf("주거지역");
       		getCost(10, amount);
       		break;
       	case 'C': case 'c':
       		printf("상업지역");
       		getCost(20, amount);
       		break;
       	case 'I': case 'i':
       		printf("공업지역");
       		getCost(30, amount);
       		break;
	default:
		printf("잘못입력하셨습니다.\n");
		break;
       }

       return 0;
}

void getCost(int rate, int amount){
       int cost = 3000;

       if(amount >= 0 && amount <= 300){
       	cost += amount * 100;
       }
       else if(amount >= 0 && amount <= 600){
       	cost += amount * 150;
       }
       else if(amount > 600){
       	cost += amount * 200;
       }
       else{
       	printf("잘못입력하였습니다");
	return;
       }
       cost = cost + (cost * rate/100);

       printf("의 %dKw 사용량에 대한 요금은 %d원 입니다.\n", amount, cost);
}



