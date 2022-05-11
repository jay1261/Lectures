#include <stdio.h>
#include <stdlib.h>

int **matrix_sum(int **A, int **B);

int main(){
    int **a = NULL, **b = NULL, **c = NULL;
    
//a
    a = (int**)malloc(3 * sizeof(int *));
    for(int i=0; i<3; i++){
        a[i] = (int*)malloc(4*sizeof(int));
    }
    for(int i=0, count=1; i<3; i++){
        for(int j=0; j<4; j++){
            a[i][j] = count++;
        }
    }
//a프린트
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    
//b
    b = (int**)malloc(3 * sizeof(int *));
    for(int i=0; i<3; i++){
        b[i] = (int*)malloc(4*sizeof(int));
    }
    for(int i=0, count=12; i<3; i++){
        for(int j=3; j>=0; j--){
            b[i][j] = count--;
        }
    }
//b 프린트
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

//a,b더해서 c에 대입후 출력
    c = matrix_sum(a, b);
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}

//sum함수 구현
int **matrix_sum(int **A, int **B){
    int **c = NULL;
    c = (int**)malloc(3 * sizeof(int *));
    for(int i=0; i<3; i++){
        c[i] = (int*)malloc(4*sizeof(int));
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            c[i][j] = 0;
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            c[i][j] = A[i][j] + B[i][j];
        }
    }
    
    return c;
}
