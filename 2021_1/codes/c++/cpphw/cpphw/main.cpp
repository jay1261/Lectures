#include <iostream>
using namespace std;

class Circle{
public:
    int radius;
    Circle(int r); //매개변수 있는 생성자만 직접 생성
    double getArea();
};
Circle::Circle(int r){
    radius=r;
    cout<<"반지름 "<<radius<<"원 생성"<<endl;
}
double Circle::getArea(){
    return 3.14*radius*radius;
}


int main(){
    Circle donut;   //디폴트 생성자를 컴파일러가 자동으로 생성해주지않아서 오류 발생
    double area = donut.getArea();
    cout<<"면적은"<<area<<endl;
    
    
    Circle pizza(30);
    area= pizza.getArea();
    cout<<"면적은"<<area<<endl;
    
}
