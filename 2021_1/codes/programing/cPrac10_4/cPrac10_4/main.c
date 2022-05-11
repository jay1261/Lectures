#include <stdio.h>

int min(int *array,int size);
//int min(int array[10],int size);

int main(){
    int mini;
    int array[10] ={50,20,30,40,5,10,7,8,6,100};
    int size = sizeof(array)/sizeof(array[0]);
    
    mini = min(array,size);
    printf("최소값은 %d 입니다.",mini);
    
    return 0;
}

int min(int *array, int size){
    int min = array[0];
    
    for(int i =1; i < size; i++){
        if(min > array[i]){
            min = array[i];
        }
    }
    return min;
}
