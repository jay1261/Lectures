//
#include <iostream>
using namespace std;

class Base{
public:
    virtual void f(){cout << "Base::f() called" << endl;}
};
class Derived : public Base{
public:
    virtual void f(){cout << "Derived::f() called" << endl;}
};

int main(){
    Derived d, *pDer;
    pDer = &d;
    pDer->f();
    
    Base *pBase;
    pBase = pDer;   //업캐스팅
    pBase->f();     //동적바인딩 발생으로 Derived 의 f 함수 호출
}
