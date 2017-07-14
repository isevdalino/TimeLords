#ifndef COMPETITION2_H
#define COMPETITION2_H
#include "Competition.h"
#include<string>

class Competition2:public Competition
{
    public:
    Competition2(std::string s,Date date);
    virtual ~Competition2();
    virtual TimeLord& winner();
    protected:
    private:
};

#endif // COMPETITION2_H
