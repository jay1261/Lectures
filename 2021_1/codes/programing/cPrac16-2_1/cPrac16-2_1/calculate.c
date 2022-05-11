//
//  main.c
//  cPrac16-2_1
//
//  Created by DongJae Lee on 2021/05/18.
//  명령행 인자
#include <stdio.h>
#include <stdlib.h>

//char **argv 도 가능
int main(int argc, const char **argv) {
    printf("%s %s %s %s\n", argv[0],argv[1],argv[2],argv[3]);
    switch(*argv[2]){
        case '+':
            printf("%d + %d = %d\n",atoi(argv[1]), atoi(argv[3]), atoi(argv[1]) + atoi(argv[3]));
            break;
        case '-':
            printf("%d - %d = %d\n",atoi(argv[1]), atoi(argv[3]), atoi(argv[1]) - atoi(argv[3]));
            break;
        case 'x': //곱셈을 할 때는 * 넣으면 다르게 들어가서 x로 대체
            printf("%d * %d = %d\n",atoi(argv[1]), atoi(argv[3]), atoi(argv[1]) * atoi(argv[3]));
            break;
        case '/':
            printf("%d / %d = %d\n",atoi(argv[1]), atoi(argv[3]), atoi(argv[1]) / atoi(argv[3]));
            break;
        default:
            printf("인자를 잘못 입력하였습니다. \n참고 : 곱하기는 *이아닌 x로 입력.");
            break;
    }
}
