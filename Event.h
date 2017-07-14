#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>
#include "Date.h"

class Event
{
    public:
        Event(const Date&, int, int,std::string location="",std::string title = "<Untitled Event>", std::string description= "");
        virtual ~Event();
        int getSH();
        int getEH();
        Date getDate();
        std::string getLocation();
        std::string getTitle();
        std::string getDescription();
        bool isHappeningAt(std::string place,Date date,int sH,int eH);
        virtual bool isInProgress(const Date&, int) const;
        friend std::ostream& operator<< (std::ostream&, const Event&);
        friend std::istream& operator>> (std::istream&, Event&);
//           ​
        protected:
        Date date;
        int startHour;
        int endHour;
        std::string location;
        std::string title;
        std::string description;
        virtual std::ostream& write(std::ostream& out) const;

};

#endif // EVENT_H
