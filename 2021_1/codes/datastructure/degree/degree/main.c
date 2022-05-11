// 화씨 바꾸기

#include <stdio.h>

int TransDegree(int nDegree,int nType);


int main(){
    int nDegree,nType;

    printf("온도를 입력하세요:");
    scanf("%d",&nDegree);
    printf("type을 입력하세요(섭씨 0,화씨 1)");
    scanf("%d",&nType);
    
    
    TransDegree(nDegree, nType);
    
    return 0;
}


int TransDegree(int nDegree,int nType){
    
    
    
    if (nType==0){
       nDegree = nDegree*(9.0/5.0)+32;
        printf("화씨 = %d\n",nDegree);
    }
    else if (nType==1){
        nDegree = (nDegree-32)*(5.0/9.0);
        printf("섭씨= %d\n",nDegree);
    }
    return nDegree;
    
}
