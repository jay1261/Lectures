//
//  main.cpp
//  cppEx10_17
//
//  Created by DongJae Lee on 2021/05/20.
//

#include <iostream>
using namespace std;

int main(){
    //예제 10-17번
    double pi = 3.14;
    //           캡처   매개변수
    //           리스트  리스트   리턴타입     함수바디
    auto calc =   [pi](int r)->double{return pi*r*r;};
    
    cout << "먼적은 " << calc(3);
    cout << endl;
    
    //예제 10-18번
    int sum = 0;
    [&sum](int x, int y){sum = x + y;}(2,3);
    
    cout << "합은 " <<  sum << endl;
}
