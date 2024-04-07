#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <GL/freeglut.h>
#include "AppController.h"
#include "ColorSelector.h"
#include "ColorPicker.h"
#include "Toolbar.h"
#include "Canvas.h"

struct Controller : public AppController {
    Toolbar toolbar;
    Canvas canvas;
    ColorSelector colorSelector;
    ColorPicker colorPicker;

    Controller(){
        //
    }

    void leftMouseDown( float x, float y ){
        if (toolbar.contains(x, y)){
            toolbar.handleMouseClick(x, y);
            if (toolbar.getSelectedTool() == CLEAR){
                canvas.clearShapeCounter();
            }
            if (toolbar.getSendBack() || toolbar.getSendFront()) {
                canvas.changeShapeLayer(toolbar.getSendBack(), toolbar.getSendFront());
                toolbar.deselectSendBack();
                toolbar.deselectSendFront();
            }

        } else if (canvas.contains(x, y)){
            canvas.handleMouseClick(x, y, toolbar.getSelectedTool(), colorPicker.getCurrentColor());
        } else if (colorPicker.contains(x, y)){
            colorPicker.handleMouseClick(x, y);
            if (canvas.getSelectedShape() != -1) {
                canvas.updateSelectedShape(colorPicker.getCurrentColor());
            }
            
        }
    }

    void mouseMotion( float x, float y ) {
        if (canvas.contains(x, y)){
                canvas.handleMouseDrag(x, y, toolbar.getSelectedTool(), colorPicker.getCurrentColor());
        }
        if (colorPicker.contains(x, y)) {
            colorPicker.handleMouseDrag(x, y);
        }
    }

    void leftMouseUp(float x, float y) {
        
        colorPicker.handleMouseUp(x, y);
        //canvas.handleMouseUp(x, y, toolbar.getSelectedTool(), colorPicker.getCurrentColor());

    }

    void render(){
        canvas.draw();
        toolbar.draw();
        //colorSelector.draw();
        colorPicker.draw();
    }
};

#endif