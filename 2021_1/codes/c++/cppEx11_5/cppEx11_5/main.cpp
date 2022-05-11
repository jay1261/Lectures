//
//  main.cpp
//  cppEx11_5
//
//  Created by DongJae Lee on 2021/05/25.
//

#include <iostream>
using namespace std;

int main(){
    cout << 30 << endl;  //10진수로 출력
    
    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout << 30 << endl;     //16진수 출력
    
    cout.setf(ios::showbase);   //16진수로 설정
    cout << 30 << endl;
    
    cout.setf(ios::uppercase);  //16진수의 A~F는 대문자로 설정
    cout << 30 << endl;
    
    cout.setf(ios::dec | ios::showpoint);    //10진수 설정, 소숫점이하 나머지 0
    
    cout << 23.5 << endl;
    
    cout.setf(ios::scientific);     //실수를 과학산술용 표현으로 설정
    cout << 23.5 << endl;
    
    cout.setf(ios::showpos);        //양수인 정수도 +부호 함께 출력하도록 설정
    cout << 23.5 << endl;
}
