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

void get_score(student student[5]);
void display_student(student student[5]);

int main(){
    student kpu_st[5] = {   {"00000001", "Lee"},
                            {"00000002", "Kim"},
                            {"00000003", "Park"},
                            {"00000004", "Rho"},
                            {"00000005", "Seo"}};
    get_score(kpu_st);
    display_student(kpu_st);
    
}

void get_score(student student[5]){
    printf("영어점수 : ");
    scanf("%lf",&student[0].score.english);
    printf("수학점수 : ");
    scanf("%lf",&student[0].score.math);
    student[0].score.total = student[0].score.english + student[0].score.math;
    
    student[1].score.english = 50;
    student[1].score.math = 50;
    student[1].score.total = student[1].score.english + student[1].score.math;
    
    student[2].score.english = 60;
    student[2].score.math = 60;
    student[2].score.total = student[2].score.english + student[2].score.math;
    
    student[3].score.english = 70;
    student[3].score.math = 70;
    student[3].score.total = student[3].score.english + student[3].score.math;
    
    student[4].score.english = 90;
    student[4].score.math = 90;
    student[4].score.total = student[4].score.english + student[4].score.math;
    
}
void display_student(student student[5]){
    for(int i=0; i<5; i++){
        printf("이름 : %s\n",student[i].name);
        printf("영어점수 : %lf, 수학점수 : %lf, 총점 : %lf\n",student[i].score.english, student[i].score.math, student[i].score.total);
        printf("\n");
    }
    
}
