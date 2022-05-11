#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

typedef struct student{
    int student_no;
    char name[40];
    int score;
}student;

void SWAP(student* arr, int a, int b){
    student temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void SORT_Score(student *arr, int m, int n){
// 아래 주석은 for문으로 작성한 SORT함수
//    for (int i = 0; i < n ; i++){
//        for(int j = 0; j < n; j++){
//            if(arr[j].score < arr[j+1].score){
//                SWAP(arr, j , j+1);
//            }
//        }
//    }

    
    //재귀함수로 SORT함수 작성
    if(n == 0) return;
    
    for(int i = 0; i < n; i++){
    if(arr[i].score < arr[i+1].score)
        SWAP(arr, i, i+1);
    }
    SORT_Score(arr, m+1, n-1);
    
}
void SORT_Student_no(student *arr, int m, int n){
    if(n == 0) return;
    
    for(int i = 0; i < n; i++){
    if(arr[i].student_no < arr[i+1].student_no)
        SWAP(arr, i, i+1);
    }
    SORT_Student_no(arr, m+1, n-1);
}

int main(){
    
    struct student* s[MAX];
    //동적 할당
    for(int i = 0 ; i < sizeof(s)/sizeof(struct student *); i++){
        s[i] = malloc(sizeof(struct student));
    }
    
    
    char str[40];

    //stduent information field
    for (int i = 0; i < MAX; i++){
        printf("Student Information (학번, 이름, 성적) : ");
        scanf("%d", &s[i]->student_no);
        scanf("%s", str);
        strcpy(s[i]->name, str);
        scanf("%d", &s[i]->score);
    }
    //성적순
    printf("성적 순 학생 출력\n");
    SORT_Score(*s, 0, MAX-1); //소트(학생 배열,0,num-1)
    for (int i = 0; i < MAX; i++)
        printf("%d\t%s\t%d\n", s[i]->student_no, s[i]->name, s[i]->score);
    printf("\n");
    
    //학번순
    printf("학번 순 학생 출력\n");
    SORT_Student_no(*s, 0, MAX-1); //소트(학생 배열,0,num-1)
    for (int i = 0; i < MAX; i++)
        printf("%d\t%s\t%d\n", s[i]->student_no, s[i]->name, s[i]->score);
    printf("\n");
    
    //할당 반환
    for(int i = 0 ; i < sizeof(s)/sizeof(struct student *); i++){
        free(s[i]);
    }
    
    
    return 0;
}
