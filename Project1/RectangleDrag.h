#ifndef RECTANGLEDRAG_H
#define RECTANGLEDRAG_H

#include "ECGraphicViewImp.h"

class RectangleDrag
{
public:
    RectangleDrag(ECGraphicViewImp& view);
    void StartDragging(int startX, int startY);
    void UpdateDragging(int currentX, int currentY);
    void EndDragging(int endX, int endY);

private:
    ECGraphicViewImp& view;
    int startX;
    int startY;
};

#endif