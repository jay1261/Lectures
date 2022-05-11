//
//  main.cpp
//  cppEx11-10
//
//  Created by DongJae Lee on 2021/05/27.
//

#include <iostream>
#include <string>
using namespace std;

class Book{
    string title;
    string press;
    string author;
public:
    Book(string title ="", string press="", string author=""){
        this->title = title;
        this->press = press;
        this->author = author;
    }
    friend ostream& operator <<(ostream& stream, Book b);
};

ostream& operator <<(ostream& stream, Book b){
    stream << b.title << "," << b.press << "," << b.author;
    return stream;
}

int main(){
    Book book("소유냐 존재냐", "한국 출판사", "에리히프롬");
    cout << book;
}
