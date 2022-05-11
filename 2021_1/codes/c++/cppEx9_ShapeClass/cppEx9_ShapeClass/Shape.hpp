//
//  Shape.hpp
//  cppEx9_ShapeClass
//
//  Created by DongJae Lee on 2021/05/06.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <iostream>

class Shape{
    Shape * next;
protected:
    virtual void draw();
public:
    Shape(){next = NULL;}
    virtual ~Shape(){};
    void paint();
    Shape* add(Shape *p);
    Shape* getNext(){return next;}
};



#endif /* Shape_hpp */
