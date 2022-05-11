#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, int value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
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

int find_max(ListNode *head){
    ListNode *p = head;
    int max = 0;
    while(p != NULL){
        if(max < p->data)
            max = p->data;
        p = p->link;
    }
    return max;
}

int find_min(ListNode *head){
    ListNode *p = head;
    int min = head->data;
    while(p != NULL){
        if(min > p->data)
            min = p->data;
        p = p->link;
    }
    return min;
}

void print_list(ListNode *head){
    for (ListNode *p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}


int main(){
    ListNode *head = NULL;
    int max = 0, min = 0;
    
    head = insert_first(head, 60);
    head = insert_first(head, 50);
    head = insert_first(head, 30);
    head = insert_first(head, 40);
    print_list(head);
    
    max = find_max(head);
    min = find_min(head);
    printf("최대값 = %d\n최소값 = %d\n",max,min);
    
    return 0;
}
