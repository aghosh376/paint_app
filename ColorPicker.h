#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include "Circle.h"
#include "Rectangle.h"
#include "Color.h"
#include <iostream>

struct ColorPicker {
private:
    Rectangle area;
    Rectangle preview;
    
    Rectangle redBar;
    Rectangle greenBar;
    Rectangle blueBar;

    Circle redSlider;
    Circle greenSlider;
    Circle blueSlider;
    float x, y;
    Color currentColor;
    Color previewColor;

    float range;
    float offsetX;
    float offsetY;

public:
    ColorPicker() {
        x = 0.5;
        y = -0.8;
        range = 255/1.5;

        area = Rectangle(-0.8f, -0.8f, 1.8f, 0.2f, Color(0.8f, 0.8f, 0.8f));

        currentColor = Color(1,0,0);
        previewColor = currentColor;
        preview = Rectangle(0.85,-0.8,0.5,0.2, previewColor);

        redBar = Rectangle(-0.75f, -0.825f, 1.5f, 0.025f, Color(0.9f, 0.9f, 0.9f));
        greenBar = Rectangle(-0.75f, -0.875f, 1.5f, 0.025f, Color(0.9f, 0.9f, 0.9f));
        blueBar = Rectangle(-0.75f, -0.925f, 1.5f, 0.025f, Color(0.9f, 0.9f, 0.9f));

        redSlider = Circle(-0.72f, -0.8375f, 0.02, Color(1,0,0));
        greenSlider = Circle(-0.72f, -0.8875f, 0.02, Color(0,1,0));
        blueSlider = Circle(-0.72f, -0.9375f, 0.02, Color(0,0,1));
    }

    void deselectAll() {
        redSlider.deselect();
        greenSlider.deselect();
        blueSlider.deselect();
    }

    void draw(){
        area.draw();
        preview.draw();

        redBar.draw();
        greenBar.draw();
        blueBar.draw();

        redSlider.draw();
        greenSlider.draw();
        blueSlider.draw();
    }

    void handleMouseClick(float x, float y){
        deselectAll();
        if (redBar.contains(x-0.02, y)) {
            redSlider.select();
            redSlider.setX(x - offsetX);
            
        } else if (greenBar.contains(x-0.02, y)){
            greenSlider.select();
            greenSlider.setX(x - offsetX);

        } else if (blueBar.contains(x-0.02, y)){
            blueSlider.select();
            blueSlider.setX(x - offsetX);

        } else if (preview.contains(x, y)){
            setCurrentColor();
        }
        setPreviewColor();
    }

    void handleMouseDrag(float x, float y) {
        if (redSlider.getSelected() && redBar.contains(x-0.02, y)) {
            redSlider.setX(x - offsetX);
        } else if (greenSlider.getSelected() && greenBar.contains(x-0.02, y)){
            greenSlider.setX(x - offsetX);
        } else if (blueSlider.getSelected() && blueBar.contains(x-0.02, y)) {
            blueSlider.setX(x - offsetX);
        }
        setPreviewColor();
    }

    void handleMouseUp(float x, float y) {
        deselectAll();
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }

    void setPreviewColor(){
        float r = (redSlider.getX() + 0.75) / 1.5;
        float g = (greenSlider.getX() + 0.75) /1.5;
        float b = (blueSlider.getX() + 0.75) /1.5;
        std::cout << "RGB: " << r << " , "<< g <<  " , " << b << std::endl;
        previewColor = Color(r, g, b);
        preview.setColor(previewColor);
    }

    void setCurrentColor(){
        currentColor = previewColor;
    }

    Color getCurrentColor() {
        return currentColor;
    }
};


#endif