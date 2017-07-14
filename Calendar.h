#ifndef CALENDAR_H
#define CALENDAR_H
#include <vector>
#include <string>
#include "Event.h"
#include "Date.h"

class Calendar
{
        public:
        Calendar(std::string name="<New Calendar>");
        Calendar(const Calendar& other);
        Calendar& operator=(const Calendar& other);
        ~Calendar();
        int getCalSize();
        Date returnEarliestDate();
        int timeSpendInCentury(int i);
        std::string getName() const;
        void rename(const std::string&);
        void addEvent(const Date&, int, int,std::string="", std::string="Event", std::string="");
        void addEvent(Event& e) ;
        void addWeeklyEvent(const Date&, int, int, int, std::string="Weekly Event", std::string="");
        bool isFree (const Date& date, int hour) const;
        friend std::ostream& operator<< (std::ostream&, const Calendar&);
        void operator+=(const Calendar&);
        bool hasEventAt(std::string place,Date date,int sH,int eH);
        protected:
        private:
        std::string name;
        std::vector<Event*> events;
        void init(const Calendar& other);
        void destroy();
};

#endif // CALENDAR_H
