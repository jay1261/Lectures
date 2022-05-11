#include <stdio.h>

int main(){
	int score;

	printf("점수를 입력하시오:");
	scanf("%d",&score);

	switch(score) {
	case 100:
	case 99:
	case 98:
	case 97:
	case 96:
	case 95:
		printf("A+ 입니다.");
		break;

	case 94:
	case 93:
	case 92:
	case 91:
	case 90:
		printf("A 입니다.");
		break;
	
	case 89:
	case 88:
	case 87:
	case 86:
	case 85:
		printf("B+ 입니다.");
		break;
		
	case 84:
	case 83:
	case 82:
	case 81:
	case 80:
		printf("B+ 입니다.");
		break;

	case 79:
	case 78:
	case 77:
	case 76:
	case 75:	
		printf("C+ 입니다.");
		break;


	case 74:
	case 73:
	case 72:
	case 71:
	case 70:
		printf("C 입니다.");
		break;

	deafult:
	printf("F 입니다.");
	}

	return 0;
}

			




