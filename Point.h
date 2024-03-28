#ifndef POINT_H
#define POINT_H

#include <GL/freeglut.h>
#include "Color.h"

struct Point {
private:
    float x;
    float y;
    Color color;
    float thickness;

public:
    Point() {
        x = 0.0f;
        y = 0.0f;
        thickness = 4.0f;
    }

    Point(float x, float y, Color color) {
        this->x = x;
        this->y = y;
        this->color = color;
        thickness = 4.0f;
    }

    Point(float x, float y, Color color, float thickness) {
        this->x = x;
        this->y = y;
        this->color = color;
        this->thickness = thickness;
    }

    void draw() {
        glColor3f(color.getR(), color.getG(), color.getB());
        glPointSize(thickness);
        
        glBegin(GL_POINTS);
            glVertex2f(x, y);
        glEnd();
    }

    float getX(){
        return x;
    }
    float getY(){
        return y;
    }

    Color getColor(){
        return color;
    }

    int getThickness(){
        return thickness;
    }

    void setX(float x){
        this->x = x;
    }

    void setY(float y){
        this->y = y;
    }

    void setColor(Color color){
        this->color = color;
    }

    void setThickness(int thickness){
        this->thickness = thickness;
    }
};


#endif