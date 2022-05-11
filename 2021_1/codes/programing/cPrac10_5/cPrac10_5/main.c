#include <stdio.h>

void swap(int *,int *);
void bubble(int *a, int n);

int main(){
    int array[5] = {0,};
    int size = sizeof(array)/sizeof(array[0]);
    printf("정수 5개 입력\n");
    
    for(int i=0; i<size; i++){
        printf("%d 번째 정수 입력 :",i);
        scanf("%d",&array[i]);
    }
    bubble(array,size);
    for(int i =0; i<size; i++){
        printf("%d",array[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *pa,int *pb){
    double tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}


void bubble(int *a, int n){
    int i,j;
    for(i = 0; i<n; i++){
        for(j=n-1; j>i; --j)
            if(a[j-1] > a[j]) swap(&a[j-1],&a[j]);
    }
}
