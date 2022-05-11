//
//  main.cpp
//  cppEx10_13
//
//  Created by DongJae Lee on 2021/05/20.
//

#include <iostream>
#include <vector>   //컨테이너 벡터 사용을 위한 include
#include <algorithm>    //알고리즘 사용을 위한 include
using namespace std;

int main(){
    vector<int> v;  //정수 벡터 생성
    cout << "5개의 정수를 입력하세요 >>" ;
    for(int i=0; i<5; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(),v.end());    //벡터 안의 값을 정렬시키는 알고리즘 사용

    vector<int>::iterator it;   //벡터 내의 원소를 탐색하기 위한 iterator선언
    for(it= v.begin(); it!=v.end(); it++){  //벡터 내의 원소 하나하나 접근하여 출력
        cout<<*it << ' ';
    }
    cout <<endl;
}
