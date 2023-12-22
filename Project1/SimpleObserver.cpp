#include "ECGraphicViewImp.h"
#include "SimpleObserver.h"
#include "ECController.h"
#include <iostream>


//************************************************************


ECSimpleGraphicObserver::ECSimpleGraphicObserver(ECGraphicViewImp& viewIn) : view(viewIn), fIsSpaceBarPressed(false)
{
}

void ECSimpleGraphicObserver::Update()
{
    ECGVEventType evt = view.GetCurrEvent();
    // is this space bar key released?
    if (evt == ECGV_EV_KEY_UP_SPACE)
    {
        fIsSpaceBarPressed = true;

        // set the view to redraw
        // Note: call SetRedraw(true) once there is something changed in the view
        view.SetRedraw(true);
    }
    // if this is the timer event
    if (evt == ECGV_EV_TIMER)
    {
        // if space bar already pressed, draw a winidow
        // Note: you need to draw this in the timer event; otherwise you won't see the rectangle
        if (fIsSpaceBarPressed)
        {
            view.DrawRectangle(100, 100, 400, 400);
        }
    }
}

ECKeyboardObserver::ECKeyboardObserver(ECGraphicViewImp& viewIn, ECController& ctrl) : view(viewIn), controller(ctrl)
{
}

void ECKeyboardObserver::Update()
{
    ECGVEventType evt = view.GetCurrEvent();
    if (evt == ECGV_EV_KEY_UP_SPACE)
    {
        controller.SetMode();
        controller.UnselectAll();
        view.SetRedraw(false);
    }
    if (evt == ECGV_EV_KEY_UP_D && controller.GetMode() == 0 && controller.LengthShapes() != 0) {
        controller.DeleteShape();
    }

    if (evt == ECGV_EV_KEY_UP_G) {
        controller.SetEllipse();
    }

    if (evt == ECGV_EV_KEY_UP_Y && controller.GetMode() == 0) { // up for fill
        controller.FillShapes();
    }

    if (evt == ECGV_EV_KEY_UP_UP && controller.GetMode() == 0) { // up for fill
        controller.MoveByArrow(1);
    }

    if (evt == ECGV_EV_KEY_UP_DOWN && controller.GetMode() == 0) { // up for fill
        controller.MoveByArrow(4);
    }

    if (evt == ECGV_EV_KEY_UP_LEFT && controller.GetMode() == 0) { // up for fill
        controller.MoveByArrow(2);
    }

    if (evt == ECGV_EV_KEY_UP_RIGHT && controller.GetMode() == 0) { // up for fill
        controller.MoveByArrow(3);
    }

    if (evt == ECGV_EV_KEY_DOWN_ESCAPE && controller.GetMode() == 0) {
        int x;
        int y;
        view.GetCursorPosition(x, y);
        // controller.UpdateCursor(x, y);
        controller.GroupShapes(x, y);
    }
    // if this is the timer event
    if (evt == ECGV_EV_TIMER)
    {
        view.SetRedraw(true);
    }
}

ECMouseObserver::ECMouseObserver(ECGraphicViewImp& viewIn, ECController& ctrl) : view(viewIn), controller(ctrl)
{
}

void ECMouseObserver::Update()
{
    ECGVEventType evt = view.GetCurrEvent();
    if (evt == ECGV_EV_MOUSE_BUTTON_DOWN && controller.GetMode() == 0) //edit mode
    {
        int x;
        int y;
        view.GetCursorPosition(x, y);
        controller.SetStartCursor(x, y);
    }

    if (evt == ECGV_EV_MOUSE_BUTTON_DOWN && controller.GetMode() == 1 && controller.GetEllipse() == true)
    {
        int x;
        int y;
        view.GetCursorPosition(x, y);
        controller.SetStartCursorTest(x, y);
    }
    if (evt == ECGV_EV_MOUSE_BUTTON_DOWN && controller.GetMode() == 1 && controller.GetEllipse() == false)
    {
        int x;
        int y;
        view.GetCursorPosition(x, y);
        controller.SetStartCursor(x, y);
    }
    // insert mode
    if (evt == ECGV_EV_MOUSE_BUTTON_UP && controller.GetMode() == 1 && controller.GetEllipse() == false) // have another condition where we check to see if clicking in edit or insertion mode
    {
        int x;
        int y;
        view.GetCursorPosition(x, y);
        controller.SetEndCursor(x, y);
        controller.CreateRectangle();
    }

    if (evt == ECGV_EV_MOUSE_BUTTON_UP && controller.GetMode() == 1 && controller.GetEllipse() == true) {
        int x;
        int y;
        view.GetCursorPosition(x, y);
        controller.SetEndCursorTest(x, y);
        controller.CreateEllipse();
    }

    if (evt == ECGV_EV_MOUSE_BUTTON_UP && controller.GetMode() == 0) { // edit mode
        int x;
        int y;
        view.GetCursorPosition(x, y);
        controller.SetEndCursor(x, y);
        controller.MoveExistingShape();
        controller.UpdateCursor(x, y);
    }
    // if this is the timer event
    if (evt == ECGV_EV_TIMER)
    {
        controller.ReDrawRectangle();
        controller.ReDrawEllipse();
        view.SetRedraw(true);
    }
}