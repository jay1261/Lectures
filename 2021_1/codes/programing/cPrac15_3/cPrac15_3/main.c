//
//  main.c
//  cPrac15_3
//
//  Created by DongJae Lee on 2021/05/11.
//

#include <stdio.h>

double *sumByVal(double score);
double *sumByRef(double *score);

int main(){
    double arr[] = {95.1, 93, 94.5, 88, 89.7};
    double res1 = 0, res2 = 0;
    
    for(int i=0; i<5; i++){
        res1 = *sumByVal(arr[i]);
    }
    
    res2 = *sumByRef(arr);
    printf("ByRef 합 = %0.3lf\n",res1);
    printf("ByVal 합 = %0.3lf\n",res2);
    return 0;
}

double *sumByVal(double score){
    static double total;
    total += score;
    
    return &total;
}

double *sumByRef(double *score){
    static double total;
    
    for(int i=0; i<5; i++){
        total  += score[i];
    }
    return &total;
}
