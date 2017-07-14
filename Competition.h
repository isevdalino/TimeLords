#ifndef COMPETITION_H
#define COMPETITION_H
#include<string>
#include<vector>
#include "TimeLord.h"
#include "Event.h"
#include "Date.h"

class Competition
{
    public:
    Competition(std::string,Date);
    virtual ~Competition();
    bool registrateLord(TimeLord& timeLord);
    int numParticipants();
    void printParticipants();
    virtual TimeLord& winner();
    protected:
    std::string place;
    Date date;
    std::vector<TimeLord*> listOfParticipants;
};

#endif // COMPETITION_H
