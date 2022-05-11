// 실습 14장 1-1번
#include <stdio.h>

int main(){
    int array[2][3] = {1,2,3,4,5,6};
    
    printf("---포인터식 표현---\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j< 3; j++){
            printf("array[%d][%d] = %d\n", i, j, *(*(array+i)+j));
        }
    }
    printf("\n---배열식 표현---\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j< 3; j++){
            printf("array[%d][%d] = %d\n", i, j, array[i][j]);
        }
    }
    
    return 0;
}
