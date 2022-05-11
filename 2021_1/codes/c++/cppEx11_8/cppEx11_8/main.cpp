//
//  main.cpp
//  cppEx11_8
//
//  Created by DongJae Lee on 2021/05/27.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << showbase;
    
    cout << setw(8) << "Number";
    cout << setw(10) << "Octal";
    cout << setw(10) << "Hexa" << endl;
    
    for(int i=0; i<50; i+=5){
        cout << setw(8) << setfill('.') << dec << i;
        cout << setw(10) << setfill(' ') << oct << i;
        cout << setw(10) << setfill(' ') << hex << i << endl;
    }
}
