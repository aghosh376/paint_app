#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"

class Shape{
protected:
    float x;
    float y;
    bool selected;

public:
    virtual void draw() = 0;
    virtual bool contains(float, float) = 0;
    virtual void setColor(Color) = 0;

    virtual void addPoint(float x, float y, Color color) {}

    virtual void select(){
        selected = true;
    }

    virtual void deselect(){
        selected = false;
    }

    virtual bool isSelected(){
        return selected;
    }

    virtual void setX(float x){
        this->x = x;
    }

    virtual void setY(float y){
        this->y = y;
    }

    virtual float getX(){
        return x;
    }

    virtual float getY(){
        return y;
    }

    virtual ~Shape(){}

};

#endif