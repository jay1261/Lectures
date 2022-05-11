//
//  main.c
//  cPrac15_4
//
//  Created by DongJae Lee on 2021/05/11.
//

#include <stdio.h>
#include <string.h>

void get_data(char str[2][256]);
void display(char str[2][256]);

char (*get_data_by_ptr(char str[2][256]))[256];
void display_data(char str[2][256]);

int main(){
    char str[2][256] = {0};
    
    get_data(str);
    display(str);
    
    printf("---------------------------\n");
    
    display_data(get_data_by_ptr(str));
    
    return 0;
}

void get_data(char str[2][256]){
    for(int i=0; i<2; i++){
        printf("이름을 입력하세요 : ");
        gets(str[i]);
    }
}

void display(char str[2][256]){
    
    for(int i=0; i<2; i++){
        printf("%s\n",str[i]);
    }
}

char (*get_data_by_ptr(char str[2][256]))[256]{
    
    return str;
}

void display_data(char str[2][256]){
    for(int i=0; i<2; i++){
        printf("%s\n", str[i]);
    }
}
