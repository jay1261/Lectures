//실습 14_2번
#include <stdio.h>

int main(){
    
    int array[5][6] = {{1,2,3,4,5,0},{6,7,8,9,10,0},{11,12,13,14,15,0},{16,17,18,19,20,0},{0,0,0,0,0,0}};
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            array[i][5] += array[i][j];
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            array[4][i] += array[j][i];
        }
    }
    
    
    for (int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            printf("%d\t",array[i][j]);
        }
        printf("\n");
    }
    return 0;
}
