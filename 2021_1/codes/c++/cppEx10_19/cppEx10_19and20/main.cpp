//
//  main.cpp
//  cppEx10_19
//
//  Created by DongJae Lee on 2021/05/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int n){
    cout << n << " ";
}

int main(){
    vector<int> v = {1,2,3,4,5};
    
    for_each(v.begin(), v.end(), print);
    cout << endl;
    
    
    //람다식
    for_each(v.begin(),v.end(),[](int n){cout << n << " ";});
    cout << endl;
}
