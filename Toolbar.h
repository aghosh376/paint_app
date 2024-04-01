#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Rectangle.h"
#include "Texture.h"

enum Tool {PENCIL, ERASER, MOUSE, SQUARE, CIRCLE, TRIANGLE, HEXAGON, CLEAR};

struct Toolbar {
private:
    Rectangle area;

    Texture mouseButton;
    Texture pencilButton;
    Texture eraserButton;

    Texture squareButton;
    Texture circleButton;
    Texture triangleButton;
    Texture hexagonButton;

    Texture clearButton;

    Tool selectedTool;

    void deselectAll(){
        mouseButton.deselect();
        pencilButton.deselect();
        eraserButton.deselect();
        squareButton.deselect();
        circleButton.deselect();
        triangleButton.deselect();
        hexagonButton.deselect();
        clearButton.deselect();
    }

public:
    Toolbar(){
        area = Rectangle(-1.0f, 1.0f, 0.2f, 2.0f, Color(0.8f, 0.8f, 0.8f));

        mouseButton = Texture("assets/mouse.png", -1.0f, 0.6f, 0.2f, 0.2f);
        pencilButton = Texture("assets/pencil.png", -1.0f, 1.0f, 0.2f, 0.2f);
        eraserButton = Texture("assets/eraser.png", -1.0f, 0.8f, 0.2f, 0.2f);
        squareButton = Texture("assets/square.png", -1.0f, 0.4f, 0.2f, 0.2f);
        circleButton = Texture("assets/circle.png", -1.0f, 0.2f, 0.2f, 0.2f);
        triangleButton = Texture("assets/triangle.png", -1.0f, 0, 0.2f, 0.2f);
        hexagonButton = Texture("assets/hexagon.png", -1.0f, -0.2f, 0.2f, 0.2f);
        clearButton = Texture("assets/trash.png", -1.0f, -0.8f, 0.2f, 0.2f);

        selectPencil();
    }

    Tool getSelectedTool(){
        return selectedTool;
    }

    void selectPencil() {
        deselectAll();
        pencilButton.select();
        selectedTool = PENCIL;
    }

    void selectEraser() {
        deselectAll();
        eraserButton.select();
        selectedTool = ERASER;
    }

    void selectMouse() {
        deselectAll();
        mouseButton.select();
        selectedTool = MOUSE;
    }

    void selectSquare() {
        deselectAll();
        squareButton.select();
        selectedTool = SQUARE;
    }

    void selectCircle() {
        deselectAll();
        circleButton.select();
        selectedTool = CIRCLE;
    }

    void selectTriangle() {
        deselectAll();
        triangleButton.select();
        selectedTool = TRIANGLE;
    }

    void selectHexagon() {
        deselectAll();
        hexagonButton.select();
        selectedTool = HEXAGON;
    }

    void selectClear() {
        deselectAll();
        clearButton.select();
        selectedTool = CLEAR;
    }

    void handleMouseClick(float x, float y){
        if (pencilButton.contains(x, y)){
            selectPencil();
        } else if (eraserButton.contains(x, y)){
            selectEraser();
        } else if (squareButton.contains(x, y)){
            selectSquare();
        } else if (mouseButton.contains(x, y)){
            selectMouse();
        } else if (circleButton.contains(x, y)){
            selectCircle();
        } else if (triangleButton.contains(x, y)){
            selectTriangle();
        } else if (hexagonButton.contains(x, y)){
            selectHexagon();
        } else if (clearButton.contains(x, y)) {
            selectClear();
        }
    }

    void draw(){
        area.draw();
        mouseButton.draw();
        pencilButton.draw();
        eraserButton.draw();
        squareButton.draw();
        circleButton.draw();
        triangleButton.draw();
        hexagonButton.draw();
        clearButton.draw();
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }
};

#endif