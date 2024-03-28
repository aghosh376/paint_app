#ifndef CANVAS_H
#define CANVAS_H

#include "Rectangle.h"
#include "Toolbar.h"
#include "Point.h"
#include "Shape.h"

struct Canvas {
private:
    Rectangle area;

    Point points[10000];
    int pCounter;

    Shape* shapes[1000];
    int shapeCounter;

public:
    Canvas(){
        area = Rectangle(-0.8f, 1.0f, 1.8f, 1.8f, Color(1.0f, 1.0f, 1.0f));
        pCounter = 0;
        shapeCounter = 0;
    }

    void draw(){
        area.draw();

        for (int i = 0; i < pCounter; i++){
            points[i].draw();
        }

        for (int i = 0; i < shapeCounter; i++){
            shapes[i]->draw();
        }
    }

    void handleMouseClick(float x, float y, Tool tool, Color color){
        if (tool == PENCIL){
            points[pCounter] = Point(x, y, color);
            pCounter++;
        }
        else if (tool == ERASER){
            points[pCounter] = Point(x, y, Color(1.0f, 1.0f, 1.0f), 20.0f);
            pCounter++;
        }
    }

    void handleMouseDrag(float x, float y, Tool selectedTool, Color color){
        if (selectedTool == PENCIL){
            points[pCounter] = Point(x, y, color);
            pCounter++;
            //scribbles[scribbleCounter-1].addPoint(x, y, color);
        }
        else if (selectedTool == ERASER){
            points[pCounter] = Point(x, y, Color(1,1,1), 20);
            pCounter++;
        } /*else if (selectedTool == MOUSE){
            if (selectedSquare != -1){
                squares[selectedSquare].setX(x - offsetX);
                squares[selectedSquare].setY(y + offsetY);
            }
        } */

    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }
};

#endif