//
//  main.c
//  cPrac16_2
//
//  Created by DongJae Lee on 2021/05/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_data(char **);
void display(char **);

int main(){
    char **str;
    str = malloc(5 * sizeof(char *));
    for(int i=0; i<5; i++){
        str[i] = malloc(256 * sizeof(char));
    }
    
    get_data(str);
    display(str);
    
    return 0;
}

void get_data(char **str){
    strcpy(str[0],"lee");
    strcpy(str[1],"kim");
    strcpy(str[2],"park");
    strcpy(str[3],"sung");
    strcpy(str[4],"asdf");
}

void display(char **str){
    for(int i=0; i<5; i++){
        printf("%s\n",str[i]);
    }
}
