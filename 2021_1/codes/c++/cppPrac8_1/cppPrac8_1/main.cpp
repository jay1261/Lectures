// 파생 클래스의 생성자에서 명시적으로 기본 클래스의 생성자를 선택하는 실습. p418 실습문제 1번
#include <iostream>
#include <string>
using namespace std;

class Circle{
    int radius;
public:
    Circle(int radius=0) {this->radius = radius;}
    int getRadius(){return radius;}
    void setRadius(int radius){this->radius = radius;}
    double getArea(){return 3.14*radius*radius;}
};

class NamedCircle : public Circle{
    string name;
public:
    NamedCircle(int radius, string name) : Circle(radius){ //매개변수 있는 생성자 명시적으로 지목
        this->name = name;
    }
    string getName(){return name;}
    void show(){
        cout << "반지름이 "<< getRadius()<<"인 "<< getName() << endl;
    }
};


int main(){
    NamedCircle waffle(3,"waffle");
    waffle.show();
}
