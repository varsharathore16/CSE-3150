#ifndef ECCONTROLLER_H
#define ECCONTROLLER_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "ECObserver.h"
#include "ECGraphicViewImp.h"

class ECGraphicViewImp;
class ECShape;
// enum ECGVColor;

class ECController
{
public:
    ECController(ECGraphicViewImp& viewIn);
    void CreateShape();
    void CreateRectangle();
    void CreateEllipse();
    // void CreateShapeMoving(int x, int y, int xx, int yy);
    void SetMode(); // 0 is edit (default) 1 is insertion
    int GetMode();
    void SetStartCursor(int x, int y);
    void SetStartCursorTest(int x, int y);
    void SetEndCursorTest(int x, int y);
    void SetEndCursor(int x, int y);
    void SetRelease();
    int GetStartX() { return startX; }
    int GetStartY() { return startY; }
    int GetEndX() { return endX; }
    int GetEndY() { return endY; }
    // void UpdateIsReleased();
    void UpdateCursor(int x, int y);
    // void SelectShape();
    void ReDrawAll();
    void ReDrawRectangle();
    void ReDrawEllipse();
    int LengthShapes() { return listShapes.size(); }
    void AddChild(ECShape* myshape);
    ECShape* GetChild(int i);
    void UpdateToDraw() { ToDraw = !ToDraw; }
    bool GetToDraw() { return ToDraw; }
    void MoveExistingShape();
    void UnselectAll();
    void DeleteShape();
    bool DeleteShapeHelper();
    bool GetEllipse();
    void SetEllipse();
    void FillShapes();
    void GroupShapes(int x, int y);
    void MoveByArrow(int key);

private:
    ECGraphicViewImp& view;
    std::vector <ECShape* > listShapes;
    std::vector <ECShape* > groupShapes;
    int EditMode;
    int startX; // cursor start and end
    int startY;
    int endX;
    int endY;
    // bool IsReleased;
    int cursorX;
    int cursorY;
    bool ToDraw;
    bool ellipse;
    int stestX;
    int stestY;
    int ftestX;
    int ftestY;
};

class ECShape
{
public:
    ECShape() {};
    // int GetStartX();
    virtual int GetStartX() = 0;
    virtual int GetStartY() = 0;
    virtual int GetEndX() = 0;
    virtual int GetEndY() = 0;
    virtual void SelectedColor(int newColor) = 0;
    virtual int WhatColor() = 0;
    virtual int GetThickness() = 0;
    virtual void SetFilled(bool fill) = 0;
    virtual bool GetFilled() = 0;
    virtual void SetThickness(int thickness) = 0;
    virtual void SetStartX(int x) = 0;
    virtual void SetStartY(int x) = 0;
    virtual void SetEndX(int x) = 0;
    virtual void SetEndY(int x) = 0;

private:

};

class ECRectangle : public ECShape
{
public:
    ECRectangle(int startX, int startY, int endX, int endY, bool filled);
    int GetStartX() { return startX; }
    int GetStartY() { return startY; }
    int GetEndX() { return endX; }
    int GetEndY() { return endY; }
    void SelectedColor(int newColor) { color = newColor; }
    int WhatColor() { return color; }
    int GetThickness() { return thickness; }
    void SetFilled(bool fill) { filled = fill; }
    bool GetFilled() { return filled; }
    void SetThickness(int thickness) { thickness = thickness; }
    void SetStartX(int x) { startX = x; }
    void SetStartY(int x) { startY = x; }
    void SetEndX(int x) { endX = x; }
    void SetEndY(int x) { endY = x; }

private:
    int startX;
    int startY;
    int endX;
    int endY;
    int thickness;
    int color;
    bool filled;
};

class ECEllipse : public ECShape
    // void DrawEllipse(int xcenter, int ycenter, double radiusx, double radiusy,
{
public:
    ECEllipse(int startX, int startY, int endX, int endY, bool filled);
    int GetStartX() { return startX; }
    int GetStartY() { return startY; }
    int GetEndX() { return endX; }
    int GetEndY() { return endY; }
    void SelectedColor(int newColor) { color = newColor; }
    int WhatColor() { return color; }
    int GetThickness() { return thickness; }
    void SetFilled(bool fill) { filled = fill; }
    bool GetFilled() { return filled; }
    void SetThickness(int thickness) { thickness = thickness; }
    void SetStartX(int x) { startX = x; }
    void SetStartY(int x) { startY = x; }
    void SetEndX(int x) { endX = x; }
    void SetEndY(int x) { endY = x; }

private:
    int startX;
    int startY;
    double endX;
    double endY;
    int thickness;
    int color;
    bool filled;
};

#endif