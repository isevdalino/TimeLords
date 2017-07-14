#ifndef TIMELORD_H
#define TIMELORD_H
#include "Event.h"
#include "Date.h"
#include "Calendar.h"
#include <vector>

class TimeLord
{
    public:
    TimeLord(std::string);
    std::string getName(){
      return name;
    }
    ~TimeLord();
    TimeLord(const TimeLord&);
    void printTimeLord();
    void newCalendar();
    void newEvent(const Date& , int, int,std::string place="",std::string title = "<Untitled Event>", std::string description= "");
    template<typename T>
    void map(T(*)(T));
    Calendar returnFirst();
    template <typename RestType>
    RestType  reduce (RestType (*oper)(RestType,Calendar), RestType init){
      RestType result = init;
      for (int i = 0; i < calendarArray.size(); i++){
        result = oper (result, *calendarArray[i]);
      }
      return result;
    }
    Calendar allArchives();
    bool canVisit(std::string place,Date date,int sH,int eH);
    private:
    std::string name;
    std::vector<Calendar*> calendarArray;
};

#endif // TIMELORD_H
