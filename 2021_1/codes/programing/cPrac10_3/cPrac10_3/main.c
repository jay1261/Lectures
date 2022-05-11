#include <stdio.h>


int sum(int array[5],int size);

int main(){
    int tot;
    int array[5] = {10,30,40,30,20};
    
    tot = sum(array,sizeof(array)/sizeof(array[0]));
    printf("배열의 합은 %d 입니다. \n",tot);
    
    
    return 0;
}

int sum(int array[5],int size){
    int total = 0;
    for(int i =0; i<size; i++){
        total = total + array[i];
    }
    return total;
}
