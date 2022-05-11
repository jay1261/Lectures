#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef int element;// 스택 원소(element)의 자료형을 int로 정의
 
typedef struct stackNode {// 스택의 노드를 구조체로 정의
    element data;
    struct stackNode *link;
} stackNode;
 
stackNode* top;// 스택의 top 노드를 지정하기 위해 포인터 top 선언
 
// 스택이 공백 상태인지 확인하는 연산
int isEmpty() {
    if (top == NULL) return 1;
    else return 0;
}
 
// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
    stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top;// 삽입 노드를 top의 위에 연결
    top = temp;// top 위치를 삽입 노드로 이동
}
 
// 스택의 top에서 원소를 삭제하는 연산
element pop() {
    element item;
    stackNode* temp = top;
 
    if (top == NULL) {// 스택이 공백 리스트인 경우
        printf("\n\n Stack is empty !\n");
            
        return 0;
    }
    else {// 스택이 공백 리스트가 아닌 경우
        item = temp->data;
        top = temp->link;// top 위치를 삭제 노드 아래로 이동
        free(temp);// 삭제된 노드의 메모리 반환
        return item;// 삭제된 원소 반환
    }
}

//피크함수
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
//prec 함수
int prec(char op){
    switch(op){
        case'(': case')': return 0;
        case'+': case'-': return 1;
        case'*': case'/': return 2;
    }
    return -1;
}

char* infix_to_postfix(char *express){
    int i = 0;
    char ch, top_op;
    int len = strlen(express);
    static char array[100];
    int count= 0;
    
    for(i = 0; i < len; i++){
        ch = express[i];
        switch(ch){
            case'+': case'-': case'*': case'/':
                while(top != NULL && prec(ch) <= prec(peek())){
                    //printf("%c",pop());
                    array[count] = pop();
                    count++;
                }
                push(ch);
                break;
                
            case'(':
                push(ch);
                break;
            case')':
                top_op = pop();
                while(top_op != '('){
                    //printf("%c",top_op);
                    array[count] = top_op;
                    top_op = pop();
                    count++;
                }
                break;
            default:
                //printf("%c",ch);
                array[count] = ch;
                count++;
                break;
        }
    }
    while(top != NULL){
        array[count] = pop();
        count++;
    }//printf("%c",pop());
    
    return array;
}
 
// 후위 표기법 수식을 계산하는 연산
element evalPostfix(char *exp) {
    int opr1, opr2, value, i = 0;
// char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장
    int length = strlen(exp);
    char symbol;
    top = NULL;
    
    for(i=0; i<length; i++){
        symbol = exp[i];
        if (symbol != '+' && symbol !='-' && symbol !='*' && symbol !='/'){
            value = symbol-'0';
            push(value);
        }
        else{
            opr2 = pop();
            opr1 = pop();
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
            }
        }
/* source implementation needed here */
    }
// 수식 exp에 대한 처리를 마친 후 스택에 남아 있는 결과값을 pop하여 반환
    return pop();
}
 
void main(void) {
    int a;
    char* result;
    char* express ="3*5-6/2"; //"35*62/-"; 
    printf("Infix = %s\n",express);
    result = infix_to_postfix(express);
    printf("Postfix = %s",result);
    a = evalPostfix(result);
    printf("\n\n연산 결과 => %d\n",a);
}
