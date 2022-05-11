#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char element;
//트리
typedef struct Tree{
    element data;
    struct Tree *right;
    struct Tree *left;
}Tree;
//스택
typedef struct Node{
    element data;
    struct Node *link;
}Node;

typedef struct ListStack{
    Node *head;
}Stack;

//------------------------스택함수-------------------------------
//스택 비었는지 학인
int SIsEmpty(Stack * pstack){
    if (pstack->head == NULL)
        return 0;
    else
        return 1;
}
// 스택 푸시연산 함수
void Spush(Stack* temp,Tree* item) {
    Node *newNode = malloc(sizeof(Node));
     
        newNode->data = item->data;
        newNode->link = temp->head;
     
        temp->head = newNode;
}

// 스택 팝 연산 함수
Tree* Spop(Stack *temp){
    Tree* pT = malloc(sizeof(Tree));
    Node *rnode;
 
    if (SIsEmpty(temp)) {
        printf("\n\n Stack is empty !\n");
            
        exit(-1);
    }
    else {// 스택이 공백 리스트가 아닌 경우
        pT->data = temp->head->data;
        rnode = temp->head;
        
        temp->head = temp->head->link;
        free(rnode);
        return pT;
    }
}
//------------------------스택함수-------------------------------


//------------------------트리함수------------------------------
//트리 구조체
Tree* makeTreeNode(void){
    Tree *pnode = (Tree*)malloc(sizeof(Tree));
    pnode->right = NULL;
    pnode->left = NULL;
    return pnode;
}
//트리 데이터 반환 함수
element getTreeData(Tree* p){
    return p->data;
}
//트리 데이터 세팅 함수
void setTreeData(Tree* p, element data){
    p->data = data;
}
//오른쩍 서브트리 반환
Tree* getRightSubTree(Tree *p){
    return p->right;
}
//왼쪽 서브트리 반환
Tree* getLeftSubTree(Tree *p){
    return p->left;
}
//서브 트리 생성 함수
void makeRightSubTree(Tree *main, Tree *sub){
    if(main->right != NULL){
        free(main->right);
    }
    main->right = sub;
}
void makeLeftSubTree(Tree *main, Tree *sub){
    if(main->left != NULL){
        free(main->left);
    }
    main->left = sub;
}
//수식트리를 만드는 함수
Tree* makeExpTree(char exp[]){
    Stack stack;
    Tree *pnode;
    unsigned long int expLenth = strlen(exp);
    
    for(int i=0; i<expLenth; i++){
        pnode = makeTreeNode();
        if(isdigit(exp[i])){
            setTreeData(pnode, exp[i]-'0');
        }
        else{
            makeRightSubTree(pnode, Spop(&stack));
            makeLeftSubTree(pnode, Spop(&stack));
            setTreeData(pnode, exp[i]);
        }
        Spush(&stack,pnode);
    }
    return Spop(&stack);
}
//지수 연산 함수
int expnentialEval(int a, int b){
    int result = 1;
    for(int i=0; i<b; i++){
        result *= a;
    }
    return result;
}
// 수식트리 계산 함수
int evalExpTree(Tree *p){
    int op1, op2;
    if(getLeftSubTree(p)==NULL && getRightSubTree(p)==NULL)
        return getTreeData(p);
    op1 = evalExpTree(getLeftSubTree(p));
    op2 = evalExpTree(getRightSubTree(p));
    
    switch(getTreeData(p)){
        case'+':
            return op1 + op2;
        case'-':
            return op1 - op2;
        case'*':
            return op1 * op2;
        case'/':
            return op1 / op2;
        case'^':
            return expnentialEval(op1, op2);
        case'%':
            return op1 % op2;
    }
    return 0;
}


typedef void (VisitFuncPtr)(element data); // 포인터 함수
//중위순회
void InorderTraverse(Tree * bt,VisitFuncPtr action){
    if(bt ==NULL)
        return;
    
    InorderTraverse(bt -> left, action);
    action(bt->data);
    InorderTraverse(bt -> right, action);
}
//전위순회
void PreorderTraverse(Tree * bt, VisitFuncPtr action){
    if(bt ==NULL)
        return;
    
    action(bt->data);
    InorderTraverse(bt -> left,action);
    InorderTraverse(bt -> right, action);
}
//후위순회
void PostorderTraverse(Tree * bt, VisitFuncPtr action){
    if(bt ==NULL)
        return;
    
    InorderTraverse(bt -> left, action);
    InorderTraverse(bt -> right, action);
    action(bt->data);
}
//------------------------트리함수------------------------------

int main(void)
{
    char exp[] = "1+2*3";
    Tree * eTree = makeExpTree(exp);
   


    printf("후위: ");
    printf("연산결과˙: %d \n", evalExpTree(eTree));

    return 0;
}



