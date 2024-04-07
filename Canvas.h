#ifndef CANVAS_H
#define CANVAS_H

#include "Rectangle.h"
#include "Toolbar.h"
#include "Point.h"
#include "Shape.h"
#include "Scribble.h"
#include "Triangle.h"
#include "Circle.h"
#include "Hexagon.h"

struct Canvas {
private:
    Rectangle area;

    Point points[10000];
    int pCounter;

    float offsetX;
    float offsetY;

    Shape* shapes[1000];
    int shapeCounter;
    int selectedShape;

public:
    Canvas(){
        area = Rectangle(-0.8f, 1.0f, 1.8f, 1.8f, Color(1.0f, 1.0f, 1.0f));
        pCounter = 0;
        shapeCounter = 0;
        selectedShape = -1;
        offsetX = 0;
        offsetY = 0;
    }

    void draw(){
        area.draw();

        /*for (int i = 0; i < pCounter; i++){
            points[i].draw();
        }*/

        for (int i = 0; i < shapeCounter; i++){
            shapes[i]->draw();
        }
    }

    void handleMouseClick(float x, float y, Tool tool, Color color){
        if (tool == PENCIL){
            //points[pCounter] = Point(x, y, color);
            //pCounter++;
            shapes[shapeCounter] = new Scribble();
            shapeCounter++;
        }
        else if (tool == ERASER){
            //points[pCounter] = Point(x, y, Color(1.0f, 1.0f, 1.0f), 20.0f);
            //pCounter++;
            for (int i = 0; i < shapeCounter; i++) {
                if (shapes[i]->contains(x, y)) {
                    for(int j = i; j < shapeCounter - 1; j++) {
                        shapes[j] = shapes[j+1];
                    }
                    shapeCounter--;
                }
            }
        } else if (tool == MOUSE){
            for (int i = 0; i < shapeCounter; i++){
                shapes[i]->deselect();
                std::cout << "deselect" << std::endl;
            }
            selectedShape = -1;
            for (int i = shapeCounter-1; i >= 0; i--){
                if (shapes[i]->contains(x, y)){
                    std::cout << "select" << std::endl;
                    /*Shape* temp = shapes[i];
                    for(int j = i; j < shapeCounter - 1; j++) {
                        shapes[j] = shapes[j+1];
                    }
                    selectedShape = shapeCounter-1;
                    shapes[selectedShape] = temp;
                    shapes[selectedShape]->select();
                    */
                    selectedShape = i;
                    shapes[selectedShape]->select();
                    offsetX = x - shapes[selectedShape]->getX();
                    offsetY = shapes[selectedShape]->getY() - y;
                    break;
                }
            }
        } else if (tool == SQUARE) {
            shapes[shapeCounter] = new Rectangle(x, y, 0.3, 0.3, color);
            shapeCounter++;
        } else if (tool == CIRCLE) {
            shapes[shapeCounter] = new Circle(x, y, 0.15, color);
            shapeCounter++;
        } else if (tool == TRIANGLE) {
            shapes[shapeCounter] = new Triangle(x, y, 0.3, color);
            shapeCounter++;
        } else if (tool == HEXAGON) {
            shapes[shapeCounter] = new Hexagon(x, y, 0.15, color);
            shapeCounter++;
        } else if (tool == CLEAR) {
            clearShapeCounter();
        }
    }

    void changeShapeLayer(bool sendBack, bool sendFront) {
        if (selectedShape != -1) {
            if (sendFront && selectedShape != shapeCounter - 1) {
                Shape* temp = shapes[selectedShape];
                shapes[selectedShape] = shapes[selectedShape + 1];
                shapes[selectedShape + 1] = temp;
                selectedShape++;
            } else if (sendBack && selectedShape != 0) {
                Shape* temp = shapes[selectedShape];
                shapes[selectedShape] = shapes[selectedShape - 1];
                shapes[selectedShape - 1] = temp;
                selectedShape--;
            }
        }
    }

    void handleMouseDrag(float x, float y, Tool selectedTool, Color color){
        if (selectedTool == PENCIL){
            //points[pCounter] = Point(x, y, color);
            //pCounter++;
            //scribbles[scribbleCounter-1].addPoint(x, y, color);
            shapes[shapeCounter-1]->addPoint(x, y, color);
        }
        else if (selectedTool == ERASER){
            //points[pCounter] = Point(x, y, Color(1,1,1), 20);
            //pCounter++;
            
        } /*else if (selectedTool == MOUSE){
            if (selectedSquare != -1){
                squares[selectedSquare].setX(x - offsetX);
                squares[selectedSquare].setY(y + offsetY);
            }
        } */else if (selectedTool == MOUSE) {
            if (selectedShape != -1) {
                shapes[selectedShape]->setX(x - offsetX);
                shapes[selectedShape]->setY(y + offsetY);
                std::cout << "move" << std::endl;
            }
        }

    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }

    int getSelectedShape() {
        return selectedShape;
    }

    void updateSelectedShape(Color color) {
        if (selectedShape != -1 && selectedShape < shapeCounter) {
            shapes[selectedShape]->setColor(color);
        }
    }

    void clearShapeCounter(){
        shapeCounter = 0;
    }
};

#endif