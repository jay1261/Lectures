#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef int element;
 
// 스택 구조체
typedef struct stackNode {
    element data;
    struct stackNode *link;
} stackNode;
 
stackNode* top;// 스택의 top 노드를 지정하기 위한 포인터 top 선언
 
//스택이 비었는지 확인
int isEmpty() {
    if (top == NULL) return 1;
    else return 0;
}
 
//스택에 데이터 삽입
void push(element item) {
    stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}
 
// 스택에서 원소를 삭제하고 삭제한 원소를 반환
element pop() {
    element item;
    stackNode* temp = top;
 
    if (top == NULL) {// 스택이 공백 리스트인 경우
        printf("\n\n Stack is empty !\n");
            
        return 0;
    }
    else {
        item = temp->data;
        top = temp->link;
        free(temp);
        return item;
    }
}

// 피크 함수
element peek(){
    element item;
    stackNode* temp = top;
    if(top == NULL){
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else{
        item = temp ->data;
        return item;
    }
}
// 연산자의 우선순위를 반환해주는 함수
int prec(char op){
    switch(op){
        case'(': case')': return 0;
        case'+': case'-': return 1;
        case'*': case'/': case'%': return 2;
        case'^': return 3;
    }
    return -1;
}

// 중위표기식을 후위표기식으로 변환
char* infix_to_postfix(char *express){
    int i = 0;
    char ch, top_op;
    int len = strlen(express);
    static char array[100];
    int count= 0;
    
    for(i = 0; i < len; i++){
        ch = express[i];
        switch(ch){
            //우선순위대로 연산자 비교
            case'+': case'-': case'*': case'/': case'^': case'%':
                while(top != NULL && prec(ch) <= prec(peek())){
                    array[count] = pop();
                    count++;
                }
                push(ch);
                break;
            //괄호 처리
            case'(':
                push(ch);
                break;
            case')':
                top_op = pop();
                while(top_op != '('){
                    array[count] = top_op;
                    top_op = pop();
                    count++;
                }
                break;
            default:
                array[count] = ch;
                count++;
                break;
        }
    }
    while(top != NULL){
        array[count] = pop();
        count++;
    }
    return array;
}
//지수 계산하는 함수 작성
int expnentialEval(int a, int b){
    int result = 1;
    for(int i=0; i<b; i++){
        result *= a;
    }
    return result;
}

//후위 표기식으로 들어온 수식을 계산하는 함수
element evalPostfix(char *exp) {
    int opr1, opr2, value, i = 0;
    int length = strlen(exp);
    char symbol;
    top = NULL;
    
    for(i=0; i<length; i++){
        symbol = exp[i];
        if (symbol != '+' && symbol !='-' && symbol !='*' && symbol !='/' && symbol !='^' && symbol !='%'){
            value = symbol-'0';
            push(value);
        }
        else{
            opr2 = pop();
            opr1 = pop();
            //연산자에 따라 계산식 설정해서 계산후 스택에 푸쉬
            switch(symbol){
                case '+':
                    push(opr1 + opr2);
                    break;
                case '-':
                    push(opr1 - opr2);
                    break;
                case '*':
                    push(opr1 * opr2);
                    break;
                case '/':
                    push(opr1 / opr2);
                    break;
                case '^':
                    push(expnentialEval(opr1, opr2));
                    break;
                case '%':
                    push(opr1 % opr2);
                    break;
            }
        }
    }
    return pop();
}
 
int main(void) {
    int a;
    char* result;
    //계산할 수식 입력
    char* express = "(2^2+3^2+2)+(8%5)";
    printf("Infix = %s\n",express);
    result = infix_to_postfix(express);
    printf("Postfix = %s",result);
    a = evalPostfix(result);
    printf("\n\n연산 결과 => %d\n",a);
    
    return 0;
}
