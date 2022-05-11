//
//  main.c
//  cPrac15_2
//
//  Created by DongJae Lee on 2021/05/11.
//

#include <stdio.h>
int *min(int array[10]);

int main(){
    int array[10] = {9,8,7,6,5,4,3,2,1,0};
    int res = 0;
    
    res = *min(array);
    
    printf("최소값은 = %d\n", res);
    return 0;
}

int *min(int array[10]){
    static int Min = 0;
    Min = array[0];
    
    for(int i=1; i<10; i++){
        if(Min > array[i])
            Min = array[i];
    }
    
    return &Min;
}
