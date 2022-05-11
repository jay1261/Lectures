//실습 14_1_2번
#include <stdio.h>

//int *sum_row(int array[4][3]);
//int *sum_column(int array[4][3]);

int main(){
    int array[4][3] = { {1,2,3},
                        {4,5,6},
                        {7,8,9},
                        {10,11,12}};
    
    int sum_row[4]={0}, sum_column[3]={0};
    
    //sum_row
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            sum_row[i] += array[i][j];
        }
    }
    
    for(int i=0; i<4; i++){
        printf("sum_row[%d] = %d\n",i,sum_row[i]);
    }
    
    
    //sum_column
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            sum_column[i] += array[j][i];
        }
    }
    for(int i=0; i<3; i++){
        printf("sum_column[%d] = %d\n",i,sum_column[i]);
    }
    
    return 0;
}



//int *sum_row(int array[4][3]){
//    int res[4];
//    for(int i=0; i<4; i++){
//        for(int j=0; j<3; j++){
//            res[i] += array[i][j];
//        }
//    }
//    return res;
//}
