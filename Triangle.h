#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <GL/freeglut.h>
#include "Color.h"
#include "Shape.h"

class Triangle : public Shape{
private:

    float x;
    float y;
    float w;
    float h;
    Color color;
    bool selected;

public:

    Triangle() {
        x = 0.0f;
        y = 0.0f;
        w = 0.4f;
        h = 0.5 * sqrt(3) * w;
        selected = false;
    }

    Triangle(float x, float y, float w, Color color) {
        this->x = x;
        this->y = y;
        this->w = w;
        h = 0.5 * sqrt(3) * w;
        this->color = color;
        selected = false;
    }

    void setColor(Color color) {
        this->color = color;
    }

    void select() {
        selected = true;
    }

    void deselect() {
        selected = false;
    }

     void setW(float w){
        this->w = w;
    }
    
    float getW(){
        return w;
    }

    float getH(){
        return h;
    }

    void draw() {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
            glVertex2f(x - w/2, y - h/2);
            glVertex2f(x, y + h/2);
            glVertex2f(x + w/2, y - h/2);
        glEnd();

        if (selected) {
            Triangle outer(x, y, w - 0.04f, Color(1.0f, 1.0f, 1.0f));
            Triangle inner(x, y, w - 0.08f, color);
            outer.draw();
            inner.draw();
        }
    }

    bool contains(float mx, float my) {
        if (mx >= x - w/2 && mx <= x + w/2 && my <= y + h/2 && my >= y - h/2) {
            return true;
        } else {
            return false;
        }
    }
};

#endif