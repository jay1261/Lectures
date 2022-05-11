//
//  main.cpp
//  cppEx10_11
//
//  Created by DongJae Lee on 2021/05/18.
// 벡터의 모든 원소에 곱하기 2

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    vector<int>::iterator it;
    for(it=v.begin(); it != v.end(); it++){
        int n = *it;
        n = n * 2;
        *it = n;
    }
    for(it=v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << endl;
}
