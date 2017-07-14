#ifndef COMPETITION1_H
#define COMPETITION1_H
#include "Competition.h"
#include <string>
#include "TimeLord.h"

class Competition1:public Competition
{
    public:
    Competition1(std::string s,Date date);
    virtual ~Competition1();
    virtual TimeLord& winner();
    protected:
    private:
};

#endif // COMPETITION1_H
