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
        } else if (canvas.contains(x, y)){
            canvas.handleMouseClick(x, y, toolbar.getSelectedTool(), colorPicker.getCurrentColor());
        } else if (colorPicker.contains(x, y)){
            colorPicker.handleMouseClick(x, y);
        }
    }

    void mouseMotion( float x, float y ) {
        if (canvas.contains(x, y)){
            if (toolbar.getSelectedTool() == PENCIL || toolbar.getSelectedTool() == ERASER){
                canvas.handleMouseClick(x, y, toolbar.getSelectedTool(), colorSelector.getCurrentColor());
            }
        }
    }

    void render(){
        canvas.draw();
        toolbar.draw();
        //colorSelector.draw();
        colorPicker.draw();
    }
};

#endif