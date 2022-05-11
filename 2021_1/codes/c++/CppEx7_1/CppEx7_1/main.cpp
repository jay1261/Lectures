#include <iostream>
using namespace std;
class Rect; // 클래스가 선언되기 전에 먼저 참조되는 컴파일 오류를 막기위해서 먼저 클래스라고 선언
bool equals(Rect r, Rect s);

class Rect{
    int width, height;
public:
    Rect(int width, int height) {this->width = width; this->height=height;}
    friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s){
    if(r.width == s.width && r.height == s.height) return true;
    else return false;
}

int main(){
    Rect a(3,4), b(4,5);
    if(equals(a,b)) cout << "equal" << endl;
    else cout << "not equal" << endl;
}
