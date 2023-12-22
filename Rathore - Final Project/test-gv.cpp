//
//  Created by Yufeng Wu on 3/2/22.
//
#include "ECGraphicViewImp.h"
#include "ECController.h"

#include <ios>
#include <iostream>
#include <fstream>

// Test graphical view code
int real_main(int argc, char** argv)
{
    const int widthWin = 500, heightWin = 500;
    ECGraphicViewImp view(widthWin, heightWin);

    // ECShape myShapes;
    // ECController control(view, myShapes);
    ECController control(view);
    ECMouseObserver mouse(view, control);
    ECKeyboardObserver keyboard(view, control);
    view.Attach(&mouse);
    view.Attach(&keyboard);

    if (argc == 2) {
        std::string file(argv[1]);
        std::ifstream inFile(file);
        if (inFile.good()) {
            view.SetRedraw(true);
            std::vector <ECShape* > shapes = control.getShapes();
            //control.loadShapes(file);
            control.ReDrawAll();
        }
    }

    view.Show();
    // ECObserver *testObserver = new Test();
    // view.Attach(testObserver); // call get event function to determine what key is pressed
    // if(view.GetCurrEvent() == 21){
    //   view.DrawRectangle(100, 100, 400, 400);
    //   view.SetRedraw(true);
    // };


    return 0;
}

int main(int argc, char** argv)
{
    return real_main(argc, argv);
    //return al_run_main(argc, argv, real_main);
}

