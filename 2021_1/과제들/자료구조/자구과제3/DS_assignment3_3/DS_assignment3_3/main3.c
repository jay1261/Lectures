#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct SortedList{
    element data;
    struct SortedList *link;
}SortedList;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//가득 차있으면 0 아니면 1
int is_full(SortedList *head){
    SortedList *p = malloc(sizeof(SortedList));
    if(p == NULL)
        return 1;
    else
        return 0;
}
//비어있으면 0 아니면 1
int is_empty(SortedList *head){
    if(head == NULL)
        return 1;
    else
        return 0;
}

int get_max(SortedList *head){
    SortedList *p = head;
    int max = 0;
    while(p != NULL){
        if(max < p->data)
            max = p->data;
        p = p->link;
    }
    return max;
}

int get_min(SortedList *head){
    SortedList *p = head;
    int min = head->data;
    while(p != NULL){
        if(min > p->data)
            min = p->data;
        p = p->link;
    }
    return min;
}

SortedList *get_prev(SortedList *head, element item){
    SortedList *p = head;
    SortedList *prev = head;
    
    while(p != NULL){
        if(item < p->data){
            return prev;
        }
        prev = p;
        p = p->link;
    }
    return prev;
}


SortedList *add(SortedList *head, element item){
    SortedList *p = malloc(sizeof(SortedList));
    SortedList *prev;
    prev = get_prev(head, item);
    if(is_empty(head) == 1){
        p->data = item;
        p->link = head;
        head = p;
        return head;
    }
    else{
        if(get_min(head) >= item){
            p->data = item;
            p->link = head;
            head = p;
            return head;
        }
        else{
            p->data = item;
            p->link = prev->link;
            prev->link = p;
            return head;
        }
    }
    return head;
}

SortedList *delete(SortedList *head){
    SortedList *removed;
    if(is_empty(head) == 1)
        return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

int get_length(SortedList *head){
    int count = 0;
    SortedList *p = head;
    while(p != NULL){
        count++;
        p = p->link;
    }
    return count;
}

int is_in_list(SortedList *head, int item){
    SortedList *p = head;
    while(p != NULL){
        if(p->data == item)
            return 1;
        p = p->link;
    }
    return 0;
}

void display(SortedList *head){
    SortedList *p = head;
    while(p != NULL){
        printf("%d->",p->data);
        p = p->link;
    }
    printf("NULL\n");
}

int main(){
    SortedList *head = NULL;

    head = add(head, 10);
    head = add(head, 60);
    head = add(head, 50);
    head = add(head, 70);
    head = add(head, 30);
    head = add(head, 20);
    
    
    display(head);
    
    return 0;
}
