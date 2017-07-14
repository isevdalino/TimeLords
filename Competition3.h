#ifndef COMPETITION3_H
#define COMPETITION3_H
#include "Competition.h"
#include<string>

class Competition3:public Competition
{
    public:
    Competition3(std::string s,Date date);
    virtual ~Competition3();
    virtual TimeLord& winner();
    protected:
    private:
};

#endif // COMPETITION3_H
