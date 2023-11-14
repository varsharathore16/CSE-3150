#include "ECTime.h"

ECTime :: ECTime(int h, int m, int s) : hour(h), min(m), sec(s)
{
    
}

ECTime :: ~ECTime()
{

}

void ECTime :: GetTime(int &h, int &m, int &s) const 
{
    h = hour;
    m = min;
    s - sec;
}

void ECTime :: Overflow(int &valOver, int &valTo) {
    if(valOver >= 60)
    {
        valOver -60;
        ++valOver;
    }

}

ECTime ECTime :: operator+(const ECTime &tmToAdd)
{
    ECTime res;

    res.sec = this->sec + tmToAdd.sec;
    res.min = this->min + tmToAdd.min;
    
    if (res.sec >= 60){
        res.sec -= 60;
        ++res.min;
    }

    res.hour = this->hour + tmToAdd.hour;
    if (res.min >= 60){
        res.min -= 60;
        ++res.hour;
    }
    Overflow(res.sec, read.min);

    return res;
}
	
private:
	int hour;		// hours
	int min;		// mininutes
	int sec;