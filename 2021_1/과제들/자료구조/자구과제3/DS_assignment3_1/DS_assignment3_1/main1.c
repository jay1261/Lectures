#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
    char name[20];
    int age;
    int height;
    struct ListNode *link;
}ListNode;

void error(char *message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}

ListNode* insert_first(ListNode *head, char *name,int age, int height){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    strcpy(p->name,name);
    p->age = age;
    p->height = height;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, char *name, int age, int height){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));    //(1)
    strcpy(p->name,name);
    p->age = age;
    p->height = height;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode *head){
    ListNode *removed;
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre){
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head){
    for (ListNode *p = head; p != NULL; p = p->link)
        printf("|%s,%d,%d| -> ", p->name,p->age,p->height);
    printf("NULL \n");
}

int main(){
    ListNode *head = NULL;
    
    head = insert_first(head, "choi", 30, 130);
    head = insert_first(head, "lee", 38, 140);
    head = insert_first(head, "park", 27, 120);
    head = insert_first(head, "kim", 34, 170);

    print_list(head);
    
    return 0;
}
