#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct score_tag{
    double math;
    double english;
    double total;
}score;

typedef struct student{
    char ID[10];
    char name[32];
    score score;
}student;

student* get_score();
void display_student(student student[5]);

int main(){
    student kpu_st[5] = {   {"00000001", "Lee"},
                            {"00000002", "Kim"},
                            {"00000003", "Park"},
                            {"00000004", "Rho"},
                            {"00000005", "Seo"}};
    
    display_student(get_score());
    
}

student* get_score(){
    student *pstudent = malloc(sizeof(student)*5);
    strcpy(pstudent[0].name,"lee");

    printf("영어점수 : ");
    scanf("%lf",&pstudent[0].score.english);
    printf("수학점수 : ");
    scanf("%lf",&pstudent[0].score.math);
    pstudent[0].score.total = pstudent[0].score.english + pstudent[0].score.math;
    
    pstudent[1].score.english = 50;
    pstudent[1].score.math = 50;
    pstudent[1].score.total = pstudent[1].score.english + pstudent[1].score.math;
    
    pstudent[2].score.english = 60;
    pstudent[2].score.math = 60;
    pstudent[2].score.total = pstudent[2].score.english + pstudent[2].score.math;
    
    pstudent[3].score.english = 70;
    pstudent[3].score.math = 70;
    pstudent[3].score.total = pstudent[3].score.english + pstudent[3].score.math;
    
    pstudent[4].score.english = 90;
    pstudent[4].score.math = 90;
    pstudent[4].score.total = pstudent[4].score.english + pstudent[4].score.math;
    
    return pstudent;
}
void display_student(student student[5]){
    for(int i=0; i<5; i++){
        printf("이름 : %s\n",student[i].name);
        printf("영어점수 : %lf, 수학점수 : %lf, 총점 : %lf\n",student[i].score.english, student[i].score.math, student[i].score.total);
        printf("\n");
    }
    
}

