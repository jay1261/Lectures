#include <stdio.h>

void sum_ary(int *ary);


int main(){
    
    int ary[4] = {10,30,40,20};
    
    sum_ary(ary);
    return 0;
}

void sum_ary(int *ary){
    int result = 0;
    
    for(int i=0; i<4; i++){
        result = result + ary[i];
    }
    printf("%d\n",result);
}
