//  p. 212 연습문제 7번

#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle();
    Circle(int r);
    void setRadius(int radius);
    double getArea(){return 3.14*radius*radius;}
    
};
Circle::Circle(){
    radius = 1;
}
Circle::Circle(int r){
    radius = r;
}


int main(){
    int radius;
    cout<<"원 3개의 반지름을 순서대로 입력하세요";
    Circle *pArray = new Circle[3];
    for (int i=0;i<2; i++){
        cout<<"원"<<i+1<<"의 반지름 :";
        cin>>radius;
        pArray[i].setRadius(radius);
    }
    
    int count;
    Circle*P= pArray;
    for(int i=0; i<2; i++){
        cout<<
    }
    
    
}
