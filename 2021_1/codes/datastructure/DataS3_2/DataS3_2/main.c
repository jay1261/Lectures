#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 101 // 다항식의 최대차수 + 1
#define MAX_TERMS 101
#define MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct {
int degree;
float coef[MAX_DEGREE];
} polynomial;
struct {
float coef;
int expon;
} terms[MAX_TERMS]={ {8,3}, {7,1}, {1,0}, {10,3}, {3,2},{1,0} };
int avail=6;
// 두 개의 정수를 비교
char compare(int a, int b)
{
if( a>b ) return '>';
else if( a==b ) return '=';
else return '<';
}
void attach(float coef, int expon)
{
if( avail>MAX_TERMS ){
fprintf(stderr, "항의 개수가 너무 많음\n");
exit(1);
}
terms[avail].coef=coef;
terms[avail++].expon=expon;
}
polynomial poly_add1(polynomial A, polynomial B)
{
polynomial C;// 결과 다항식
int Apos = 0, Bpos = 0, Cpos = 0;// 배열 인덱스 변수
int degree_a = A.degree;
int degree_b = B.degree;
C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
while (Apos <= A.degree && Bpos <= B.degree) {
if (degree_a > degree_b) { // A항 > B항
C.coef[Cpos++] = A.coef[Apos++];
degree_a--;
}
    else if (degree_a == degree_b) { // A항 == B항
C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
degree_a--; degree_b--;
}
else {// B항 > A항
C.coef[Cpos++] = B.coef[Bpos++];
degree_b--;
}
}
return C;
}
poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
float tempcoef;
*Cs = avail;
while( As <= Ae && Bs <= Be )
switch(compare(terms[As].expon,terms[Bs].expon)){
case '>': // A의 차수 > B의 차수
attach(terms[As].coef, terms[As].expon);
As++;break;
case '=': // A의 차수 == B의 차수
tempcoef = terms[As].coef + terms[Bs].coef;
if( tempcoef )
attach(tempcoef,terms[As].expon);
As++; Bs++;break;
case '<': // A의 차수 < B의 차수
attach(terms[Bs].coef, terms[Bs].expon);
Bs++;break;
}
// A의 나머지 항들을 이동함
for (; As <= Ae; As++)
attach(terms[As].coef, terms[As].expon);
// B의 나머지 항들을 이동함
for (; Bs <= Be; Bs++)
attach(terms[Bs].coef, terms[Bs].expon);
*Ce = avail - 1;
}

void print_poly2(int s, int e)
{
for (int i = s; i < e; i++)
printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}
void print_poly1(polynomial p)
{
for (int i = p.degree; i>0; i--)
printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
printf("%3.1f \n", p.coef[p.degree]);
}
    
int main(void)
{
    //int avail; //test case #2
    
polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
polynomial b = { 4,{ 7, 0, 5, 0, 1 } };
polynomial c;
print_poly1(a);
print_poly1(b);
c = poly_add1(a, b);
printf("1-----------------------------------------------------------------------------\n");
print_poly1(c);
int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
print_poly2(As, Ae);
print_poly2(Bs, Be);
printf("2-----------------------------------------------------------------------------\n");
print_poly2(Cs, Ce);
return 0;
}
