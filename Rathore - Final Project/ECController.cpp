#include "ECController.h"
#include "ECGraphicViewImp.h"
#include <cmath>

// code for save and load step
#include <iostream>
#include <fstream>
#include <vector>

std::vector <ECShape* > ECController::getShapes() {
    return listShapes;
}

enum ShapeType {
    RECTANGLE = 0,
    ELLIPSE,
    FILLED_RECTANGLE,
    FILLED_ELLIPSE,
    COMPOSITE_SHAPE
};

struct Color {
    int value; // Assuming color is represented as an integer
};

struct Point {
    int x, y;
};

struct Shape {
    ShapeType type;
    std::vector<Point> points; // Assuming rectangles and ellipses can be defined by points
    Color color;
};

// save function
void saveShapes(const std::string& filename, const std::vector<Shape>& shapes) {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    // Write the number of shapes
    file << shapes.size() << std::endl;

    // Write shape details
    for (const auto& shape : shapes) {
        file << shape.type << " ";
        file << shape.points.size() << " ";
        for (const auto& point : shape.points) {
            file << point.x << " " << point.y << " ";
        }
        file << shape.color.value << std::endl;
    }

    file.close();
}

// load function
bool ECController::loadShapes(const std::string& filename) {
    std::ifstream file(filename, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading." << std::endl;
        return false;
    }

    int numShapes;
    file >> numShapes;

    listShapes.clear();
    listShapes.reserve(numShapes);

    for (int i = 0; i < numShapes; ++i) {
        ECShape* shape;
        int type, numPoints;
        file >> type;
        //shape.type = static_cast<ShapeType>(type);

        file >> numPoints;
        for (int j = 0; j < numPoints; ++j) {
            Point point;
            file >> point.x >> point.y;
            //shape.points.push_back(point);
        }

        int colorValue;
        file >> colorValue;
        ///shape.color.value = colorValue;

        listShapes.push_back(shape);
    }

    file.close();
    return true;
}

ECController::ECController(ECGraphicViewImp& viewIn) : view(viewIn), listShapes(), EditMode(0), startX(0), startY(0), endX(0), endY(0), cursorX(0), cursorY(0), ToDraw(false), ellipse(false) {}
//ECController::ECController(ECGraphicViewImp& viewIn) : view(viewIn), listShapes(), EditMode(0), startX(0), startY(0), endX(0), endY(0), cursorX(0), cursorY(0), ToDraw(false), ellipse(false), fillMode(false) {}

ECController::~ECController() {
    for (auto shape : listShapes) {
        delete shape;
    }
}
//
//bool ECController::Undo()
//{
//    return listShapes.Undo();
//}
//
//bool ECController::Redo()
//{
//    return listShapes.Redo();
//}

//void ECController::AddChild(ECShape* myshape) {
//    // Create a new copy of the ECShape and add it to the listShapes
//    listShapes.push_back(new ECShape(*myshape));
//    undoStack.push(listShapes);  // Save the current state for undo
//    redoStack = {};  // Clear redo stack when a new change occurs
//}

//bool ECController::Undo()
//{
//    if (posCurrCmd < 0)
//    {
//        return false;
//    }
//    listShapes[posCurrCmd]->UnExecute();
//    --posCurrCmd;
//    return true;
//}
//
//bool ECController::Redo()
//{
//    if (posCurrCmd >= (int)listShapes.size() - 1)
//    {
//        return false;
//    }
//    ++posCurrCmd;
//    listShapes[posCurrCmd]->Execute();
//    return true;
//}
//
//void ECController::ExecuteCmd(ECCommand* pCmd)
//{
//    pCmd->Execute();
//    // clear up all cmds from current pos to end
//    if (posCurrCmd >= -1)
//    {
//        int szList = listShapes.size();
//        for (unsigned int i = posCurrCmd + 1; i < szList; ++i)
//        {
//            delete listShapes.back();
//            listShapes.pop_back();
//        }
//    }
//    listShapes.push_back(pCmd);
//    ++posCurrCmd;
//}

 //undo/redo code here
void ECController::Undo() {
    if (!undoStack.empty()) {
        redoStack.push(listShapes);
        listShapes = undoStack.top();
        undoStack.pop();
        // Redraw the updated state
        ReDrawAll();
    }
}

void ECController::Redo() {
    if (!redoStack.empty()) {
        undoStack.push(listShapes);
        listShapes = redoStack.top();
        redoStack.pop();
        // Redraw the updated state
        ReDrawAll();
    }
}

// This function should be called whenever a change is made to the graphic display, be it insert or edit.
void ECController::SaveStateForUndo() {
    undoStack.push(listShapes);
    // Whenever a new state is saved, the redo stack should be cleared
    // because the redo history no longer applies to the new state.
    while (!redoStack.empty()) {
        redoStack.pop();
    }
}

void ECController::OnKeyPress(char key) {
    switch (key) {
    case 'z':
        Undo();
        break;
    case 'y':
        Redo();
        break;
        // Handle other key presses if necessary
    default:
        break;
    }
}

//bool ECController::Undo()
//{
//    if (posCurrCmd < 0)
//    {
//        return false;
//    }
//    listShapes[posCurrCmd]->UnExecute();
//    --posCurrCmd;
//    return true;
//}
//
//bool ECController::Redo()
//{
//    if (posCurrCmd >= (int)listShapes.size() - 1)
//    {
//        return false;
//    }
//    ++posCurrCmd;
//    listShapes[posCurrCmd]->Execute();
//    return true;
//}

void ECController::SetMode() {
    if (EditMode == 0) {
        EditMode = 1;
        return;
    }
    if (EditMode == 1) EditMode = 0;
}

int ECController::GetMode() {
    return EditMode;
}

// fill code
void ECController::ToggleFillMode() {
    fillMode = !fillMode;
}

void ECController::SetStartCursor(int x, int y) {
    startX = x;
    startY = y;
}

void ECController::SetStartCursorTest(int x, int y) {
    stestX = x;
    stestY = y;
}

void ECController::SetEndCursorTest(int x, int y) {
    ftestX = x;
    ftestY = y;
}

void ECController::SetEndCursor(int x, int y) {
    endX = x;
    endY = y;
}
// void DrawEllipse(int xcenter, int ycenter, double radiusx, double radiusy,
void ECController::CreateShape() {
    if (GetEllipse() == false) {
        ECShape* rect = new ECRectangle(startX, startY, endX, endY, false);
        //ECShape* rect = new ECRectangle(startX, startY, endX, endY, fillMode);
        AddChild(rect);

    }
    if (GetEllipse() == true) {
        ECShape* ellipse = new ECEllipse(startX, startY, endX, endY, false);
        //ECShape* ellipse = new ECEllipse(startX, startY, endX, endY, fillMode);
        AddChild(ellipse);
    }
}

void ECController::GroupShapes(int x, int y) {
    // for (auto k : listShapes){
    //     int x;
    //     int y;
    //     view.GetCursorPosition(x, y);
    //     UpdateCursor(x, y);
    //     if (k->WhatColor() == 4){
    //         groupShapes.push_back(k);
    //     }
    // }
    cursorX = x;
    cursorY = y;
    // iterate through list of shapes to see if cursor is on any shape;
    // if on that shape select it by turning it blue

    for (auto x : listShapes) {

        if (x->GetStartX() > x->GetEndX()) {
            bigX = x->GetStartX();
            smallX = x->GetEndX();
        }
        if (x->GetStartX() < x->GetEndX()) {
            bigX = x->GetEndX();
            smallX = x->GetStartX();
        }
        if (x->GetStartY() > x->GetEndY()) {
            bigY = x->GetStartY();
            smallX = x->GetEndY();
        }
        if (x->GetStartY() < x->GetEndY()) {
            bigY = x->GetEndY();
            smallY = x->GetStartY();
        }

        if (cursorX >= smallX && cursorX <= bigX && cursorY >= smallY && cursorY <= bigY) {
            groupShapes.push_back(x);
            // listShapes.
        }
    }
    for (auto k : groupShapes) {
        k->SelectedColor(4);
    }
}

void ECController::CreateRectangle() {
    if (GetEllipse() == false) {
        ECShape* rect = new ECRectangle(startX, startY, endX, endY, false);
        // ECShape* rect = new ECRectangle(startX, startY, ftestX, ftestY, fillMode);
        AddChild(rect);
    }
}
void ECController::CreateEllipse() {
    if (GetEllipse() == true) {
        ECShape* ellipse = new ECEllipse(stestX, stestY, ftestX, ftestY, false);
        //ECShape* ellipse = new ECEllipse(startX, startY, ftestX, ftestY, fillMode);
        AddChild(ellipse);
    }
}

bool ECController::GetFillMode() const {
    return fillMode;
}

// void ECController :: CreateShapeMoving(int startX, int startY, int endX, int endY){
//     if (GetMode() == 1){
//         view.DrawRectangle(startX, startY, endX, endY);
//         view.SetRedraw(true);
//     }
// }

// void ECController :: UpdateIsReleased(){
//     if (IsReleased == false){
//         IsReleased = true;
//         return;
//     }
//     IsReleased = false;
// }

void ECController::UpdateCursor(int x, int y) {
    cursorX = x;
    cursorY = y;
    // iterate through list of shapes to see if cursor is on any shape;
    // if on that shape select it by turning it blue

    for (auto x : listShapes) {

        if (x->GetStartX() > x->GetEndX()) {
            bigX = x->GetStartX();
            smallX = x->GetEndX();
        }
        if (x->GetStartX() < x->GetEndX()) {
            bigX = x->GetEndX();
            smallX = x->GetStartX();
        }
        if (x->GetStartY() > x->GetEndY()) {
            bigY = x->GetStartY();
            smallX = x->GetEndY();
        }
        if (x->GetStartY() < x->GetEndY()) {
            bigY = x->GetEndY();
            smallY = x->GetStartY();
        }


        if (cursorX >= smallX && cursorX <= bigX && cursorY >= smallY && cursorY <= bigY) {
            x->SelectedColor(4);
        }
        else {
            x->SelectedColor(0);
        }
    }
}

void ECController::ReDrawAll() {
    for (auto x : groupShapes) {
        ECShape* pc = dynamic_cast<ECRectangle*> (x);
        if (pc != NULL) {
            if (x->WhatColor() == 4 and x->GetFilled() == true) {
                view.DrawFilledRectangle(x->GetStartX(), x->GetStartY(), x->GetEndX(), x->GetEndY());
            }
            else if (x->WhatColor() == 4 && x->GetFilled() == false) {
                view.DrawRectangle(x->GetStartX(), x->GetStartY(), x->GetEndX(), x->GetEndY(), x->GetThickness(), ECGV_BLUE);
            }
            else {
                view.DrawRectangle(x->GetStartX(), x->GetStartY(), x->GetEndX(), x->GetEndY());
            }
        }
        ECShape* pc1 = dynamic_cast<ECEllipse*> (x);
        if (pc1 != NULL) {
            if (x->WhatColor() == 4 and x->GetFilled() == true) {
                view.DrawFilledEllipse(x->GetStartX(), x->GetStartY(), x->GetEndX(), x->GetEndY());
                return;
            }
            else if (x->WhatColor() == 4 && x->GetFilled() == false) {
                view.DrawEllipse((startX + endX) / 2, (startY + endY) / 2, fabs(startX - endX) / 2, fabs(startY - endY) / 2, x->GetThickness(), ECGV_BLUE);
            }
            else {
                view.DrawEllipse((startX + endX) / 2, (startY + endY) / 2, fabs(startX - endX) / 2, fabs(startY - endY) / 2);
            }
        }
    }
}

void ECController::ReDrawRectangle() {
    for (auto x : listShapes) {
        ECShape* pc = dynamic_cast<ECRectangle*> (x);
        if (pc != NULL) {
            if (x->GetFilled() == true) {
                view.DrawFilledRectangle(x->GetStartX(), x->GetStartY(), x->GetEndX(), x->GetEndY());
            }
            else if (x->WhatColor() == 4 && x->GetFilled() == false) {
                view.DrawRectangle(x->GetStartX(), x->GetStartY(), x->GetEndX(), x->GetEndY(), x->GetThickness(), ECGV_BLUE);
            }
            else {
                view.DrawRectangle(x->GetStartX(), x->GetStartY(), x->GetEndX(), x->GetEndY());
            }
        }
    }
}
void ECController::ReDrawEllipse() {
    for (auto x : listShapes) {
        ECShape* pc1 = dynamic_cast<ECEllipse*> (x);
        if (pc1 != NULL) {
            if (x->GetFilled() == true) {
                view.DrawFilledEllipse((x->GetStartX() + x->GetEndX()) / 2, (x->GetStartY() + x->GetEndY()) / 2, fabs(x->GetStartX() - x->GetEndX()) / 2, fabs(x->GetStartY() - x->GetEndY()) / 2);
            }
            else if (x->WhatColor() == 4 && x->GetFilled() == false) {
                view.DrawEllipse((x->GetStartX() + x->GetEndX()) / 2, (x->GetStartY() + x->GetEndY()) / 2, fabs(x->GetStartX() - x->GetEndX()) / 2, fabs(x->GetStartY() - x->GetEndY()) / 2, x->GetThickness(), ECGV_BLUE);
            }
            else {
                view.DrawEllipse((x->GetStartX() + x->GetEndX()) / 2, (x->GetStartY() + x->GetEndY()) / 2, fabs(x->GetStartX() - x->GetEndX()) / 2, fabs(x->GetStartY() - x->GetEndY()) / 2);
            }
        }
    }
}

void ECController::AddChild(ECShape* myshape) {
    listShapes.push_back(myshape);
}

ECShape* ECController::GetChild(int i) {
    return listShapes.at(i);
}

void ECController::MoveExistingShape() {
    int differenceX = GetStartX() - GetEndX();
    int differenceY = GetStartY() - GetEndY();

    for (auto k : listShapes) {
        if (k->WhatColor() == 4) {
            k->SetStartX(k->GetStartX() - differenceX);
            k->SetStartY(k->GetStartY() - differenceY);
            k->SetEndX(k->GetEndX() - differenceX);
            k->SetEndY(k->GetEndY() - differenceY);
        }
    }
}

void ECController::UnselectAll() {
    for (auto k : listShapes) {
        k->SelectedColor(0);
    }
}

// bool ECController :: DeleteShapeHelper(){ // see if any more shapes selected
//     if (listShapes.size() == 0) return false;
//     for (auto k : listShapes){
//         if (k->WhatColor() == 4){
//             return true;
//         }
//     }
//     return false;
// }

void ECController::DeleteShape() {
    if (listShapes.size() == 0) return;
    for (auto k = 0; k < listShapes.size(); k++) {
        if (listShapes[k]->WhatColor() == 4) {
            listShapes.erase(listShapes.begin() + k);
        }
    }
}

bool ECController::GetEllipse() {
    return ellipse;
}
void ECController::SetEllipse() {
    if (ellipse == false) {
        ellipse = true;
        return;
    }
    ellipse = false;
}

//void ECController::FillShapes() {
//    for (auto k : listShapes) {
//        if (k->WhatColor() == 4) {
//            // ECShape* rect = new ECRectangle()
//            k->SetFilled(!k->GetFilled());
//        }
//    }
//}

void ECController::FillShapes() {
    for (auto k : listShapes) {
        if (GetMode() == 1) {  // Check if in insertion mode
            // Insertion mode behavior - for example, create a new shape
            if (GetEllipse() == false) {
                ECShape* rect = new ECRectangle(startX, startY, endX, endY, false);
                AddChild(rect);
            }
            else {
                ECShape* ellipse = new ECEllipse(startX, startY, endX, endY, false);
                AddChild(ellipse);
            }
        }
        else {
            // Edit mode behavior - toggle filled status
            if (k->WhatColor() == 4) {
                k->SetFilled(!k->GetFilled());
            }
        }
    }
}

void ECController::MoveByArrow(int key) {
    for (auto k : listShapes) {
        if (k->WhatColor() == 4) {
            if (key == 1) { // up
                k->SetStartY(k->GetStartY() - 10);
                k->SetEndY(k->GetEndY() - 10);
            }
            else if (key == 2) { // left
                k->SetStartX(k->GetStartX() - 10);
                k->SetEndX(k->GetEndX() - 10);
            }
            else if (key == 3) { // right
                k->SetStartX(k->GetStartX() + 10);
                k->SetEndX(k->GetEndX() + 10);
            }
            else { // down
                k->SetStartY(k->GetStartY() + 10);
                k->SetEndY(k->GetEndY() + 10);
            }
        }
    }
}

ECRectangle::ECRectangle(int startX, int startY, int endX, int endY, bool filled) : startX(startX), startY(startY), endX(endX), endY(endY), thickness(0), color(0), filled(false) {}
//void DrawEllipse(int xcenter, int ycenter, double radiusx, double radiusy,
ECEllipse::ECEllipse(int startX, int startY, int endX, int endY, bool filled) : startX(startX), startY(startY), endX(endX), endY(endY), thickness(0), color(0), filled(false) {}

//int main() {
//    // Example usage
//    std::vector<Shape> shapes;
//
//    // Add a rectangle to the shapes vector
//    ECRectangle rect = ECRectangle(10, 20, 30, 40, 123456); // Example coordinates and color
//    shapes.push_back(rect);
//
//    // Add an ellipse to the shapes vector
//    ECEllipse ellipse = ECEllipse(50, 60, 70, 80, 654321); // Example coordinates and color
//    shapes.push_back(ellipse);
//
//    // Save shapes to file
//    saveShapes("tmp.dat", shapes);
//
//    // Load shapes from file
//    std::vector<Shape> loadedShapes;
//    if (loadShapes("tmp.dat", loadedShapes)) {
//        // Successfully loaded shapes
//    }
//
//    return 0;
//}