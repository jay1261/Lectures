//
//  main.cpp
//  cppEx11_3
//
//  Created by DongJae Lee on 2021/05/25.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char cmd[80];
    cout << "cin.get(char*, int)로 문자열을 읽습니다." << endl;
    while(true){
        cout << "종료하려면 exit을 입력하세요 >>";
        cin.get(cmd,80);
        if(strcmp(cmd,"exit") == 0){
            cout << "프로그램을 종료합니다" ;
            return 0;
        }
        else
            cin.ignore(1);  //없으면 무한루프에 빠짐
    }                       //버퍼에 남아있는 <enter> 키('\n') 제거
}

