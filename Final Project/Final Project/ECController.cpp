#include "ECController.h"
#include "ECGraphicViewImp.h"
#include <cmath>

ECController::ECController(ECGraphicViewImp& viewIn) : view(viewIn), listShapes(), EditMode(0), startX(0), startY(0), endX(0), endY(0), cursorX(0), cursorY(0), ToDraw(false), ellipse(false) {}

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
        AddChild(rect);

    }
    if (GetEllipse() == true) {
        ECShape* ellipse = new ECEllipse(startX, startY, endX, endY, false);
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
        int smallX;
        int bigX;
        int smallY;
        int bigY;
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
        AddChild(rect);
    }
}
void ECController::CreateEllipse() {
    if (GetEllipse() == true) {
        ECShape* ellipse = new ECEllipse(stestX, stestY, ftestX, ftestY, false);
        AddChild(ellipse);
    }
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
        int smallX;
        int bigX;
        int smallY;
        int bigY;
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
            // listShapes.
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

void ECController::FillShapes() {
    for (auto k : listShapes) {
        if (k->WhatColor() == 4) {
            // ECShape* rect = new ECRectangle()
            k->SetFilled(!k->GetFilled());
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