// 참조 매개 변수로 인한 함수중복의 모호성 예제

#include <iostream>
using namespace std;
int add(int a, int b){
    return a+b;
}
int add(int a, int &b){
    b = b+a;
    return b;
}

int main(){
    int s = 10, t = 20;
    cout << add(s,t); // 컴파일 오류
}
//call by value 인지 call by reference 인지 모호하다.
