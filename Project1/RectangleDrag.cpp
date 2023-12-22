#include "RectangleDrag.h"
#include "../Proj-tutorial/ECGraphicViewImp.h"

RectangleDrag::RectangleDrag(ECGraphicViewImp& view) : view(view)
{
}

void RectangleDrag::StartDragging(int startX, int startY)
{
    this->startX = startX;
    this->startY = startY;
}

void RectangleDrag::UpdateDragging(int currentX, int currentY)
{
    view.DrawRectangle(startX, startY, currentX, currentY, 3, ECGV_GRAY);
}

void RectangleDrag::EndDragging(int endX, int endY)
{
    view.DrawRectangle(startX, startY, endX, endY, 3, ECGV_GRAY);
}