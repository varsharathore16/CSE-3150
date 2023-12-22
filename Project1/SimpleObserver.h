//
//  ECObserver.h
//
//
//  Created by Yufeng Wu on 2/27/20.
//
//

#ifndef SimpleObserver_h
#define SimpleObserver_h

#include "ECObserver.h"
#include "ECGraphicViewImp.h"


#include <vector>
#include <algorithm>
#include <iostream>


//************************************************************
class ECSimpleGraphicObserver : public ECObserver
{
public:
    ECSimpleGraphicObserver(ECGraphicViewImp& viewIn);
    virtual void Update();

private:
    ECGraphicViewImp& view;
    bool fIsSpaceBarPressed;
};

//********************************************
// Observer design pattern: subject

class ECObserverSubject
{
public:
    ECObserverSubject() {}
    virtual ~ECObserverSubject() {}
    void Attach(ECObserver* pObs)
    {
        //std::cout << "Adding an observer.\n";
        listObservers.push_back(pObs);
    }
    void Detach(ECObserver* pObs)
    {
        listObservers.erase(std::remove(listObservers.begin(), listObservers.end(), pObs), listObservers.end());
    }
    void Notify()
    {
        //std::cout << "Notify: number of observer: " << listObservers.size() << std::endl;
        for (unsigned int i = 0; i < listObservers.size(); ++i)
        {
            listObservers[i]->Update();
        }
    }

private:
    std::vector<ECObserver*> listObservers;
};


#endif /* SimpleObserver_h */