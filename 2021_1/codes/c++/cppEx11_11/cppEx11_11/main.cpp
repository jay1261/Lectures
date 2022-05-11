//
//  main.cpp
//  cppEx11_11
//
//  Created by DongJae Lee on 2021/05/27.
//

#include <iostream>
using namespace std;
class Point{
    int x, y;
public:
    Point(int x=0, int y=0){
        this->x = x;
        this->y = y;
    }
    friend istream& operator >>(istream& ins, Point &a);
    friend ostream& operator <<(ostream& stream, Point a);
};
istream& operator >>(istream& ins, Point &a){
    cout << "x좌표>>";
    ins >> a.x;
    cout << "y좌표>>";
    ins >> a.y;
    return ins;
}

ostream& operator <<(ostream& stream, Point a){
    stream << "(" << a.x << "," << a.y << ")";
    return stream;
}

int main(){
    Point p;
    cin >> p;
    cout << p << endl;
}
