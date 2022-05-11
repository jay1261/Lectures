//
//  main.c
//  cPrac17_3
//
//  Created by DongJae Lee on 2021/05/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void display_student(student *);


int main(){
    
    display_student(get_score());
    
}

student* get_score(){
    student *p = NULL;
    p = malloc(sizeof(student) * 2);
    
    strcpy(p[0].ID,"0001");
    strcpy(p[0].name,"김씨");
    p[0].score.math = 50;
    p[0].score.english = 40;
    p[0].score.total = p[0].score.math + p[0].score.english;
    
//    scanf("%s",p[1].ID);
    strcpy(p[1].ID,"0002");
    strcpy(p[1].name,"이씨");
    p[1].score.math = 60;
    p[1].score.english = 30;
    p[1].score.total = p[1].score.math + p[1].score.english;
    
    return p;
}

void display_student(student *p){
    for(int i=0; i<2; i++){
        printf("학번 - %s\n",p->ID);
        printf("이름 - %s\n",p->name);
        printf("수학 점수 - %0.1lf\n",p->score.math);
        printf("영어 점수 - %0.1lf\n",p->score.english);
        printf("전체 점수 - %0.1lf\n",p->score.total);
        printf("\n");
        p++;
    }
}
