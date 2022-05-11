//
//  main.cpp
//  cppEx10_2
//
//  Created by DongJae Lee on 2021/05/11.
//

#include <iostream>
using namespace std;

template<class T>
T bigger(T a, T b){ //반환형도 T로 일반화
    if(a>b)
        return a;
    else
        return b;
}

int main(){
    int a = 20, b = 50;
    char c = 'a' , d = 'z';
    cout << "bigger(20,50)의 결과는 " << bigger(a,b) << endl;
    cout << "bigger('a','z')의 결과는 " << bigger(c,d) << endl;
}
