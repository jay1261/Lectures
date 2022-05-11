//
//  main.cpp
//  cppPrac10_1
//
//  Created by DongJae Lee on 2021/05/20.
//

#include <iostream>
using namespace std;

template<class T>
T biggest(T array[], T size){
    T max = array[0];
    for(int i=0; i<size; i++){
        if(max <= array[i])
            max = array[i];
    }
    return max;
}

int main(){
    int x[] = {1,10,100,5,4};
    
    cout << biggest(x, 5) << endl;
}
