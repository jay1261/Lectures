//
//  main.cpp
//  cppEx10_15and16
//
//  Created by DongJae Lee on 2021/05/20.
//  람다식

#include <iostream>
#include <string>

using namespace std;

int main(){
// 
    [](int x, int y){cout << "합은 " << x + y;}(2, 3);
    cout << endl;
    
    auto love = [](string a, string b){
        cout << a << "보다 " << b << "가 좋아" <<endl;
    };
    
    love("돈", "너");
    love("냉면", "만두");
}
