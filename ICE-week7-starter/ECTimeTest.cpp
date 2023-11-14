#include "ECTime.h"
#include <iostream>
using namespace std;

int main(){
    ECTime t1(1, 40, 40), t2(2, 25,30);
    ECTime t3 = t1+t2;
    int h, m, s;
    t3.GetTime(h,m,s);
    cout << "h: " << h << ", m: " << m << ", s: " << s << endl;
}