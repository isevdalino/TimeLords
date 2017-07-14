#include "TimeLord.h"
#include <iostream>
using namespace std;

TimeLord::TimeLord(std::string name)
{
    this->name=name;
}

void TimeLord:: newCalendar(){
  Calendar* calendar1=new Calendar;
  calendarArray.push_back(calendar1);
}

void TimeLord:: newEvent(const Date& date1 , int a, int b,std::string place,std::string title , std::string description){
  Event event1(date1,a,b,place,title,description);
  calendarArray[calendarArray.size()-1]->addEvent(date1,a,b,place,title,description);
}

TimeLord::TimeLord(const TimeLord& t){
  this->name=t.name;
  for(int i=0;i<t.calendarArray.size();i++){
    this->newCalendar();
    *calendarArray[i]=*t.calendarArray[i];
  }
}


TimeLord::~TimeLord()
{
    for (unsigned int i = 0; i < calendarArray.size(); i++) {
        delete calendarArray[i];
    }
}

Calendar TimeLord::allArchives(){
  Calendar calendar;
  for(int i=0;i<calendarArray.size();i++){
    calendar+=(*calendarArray[i]);
  }
  return calendar;
}

bool TimeLord::canVisit(std::string place,Date date,int sH,int eH){
  for(int i=0;i<calendarArray.size();i++){
    if(calendarArray[i]->hasEventAt(place,date,sH,eH)){
        return false;
    }
  }
  return true;
}

template<typename T>
void TimeLord:: map(T(*func)(T)){
  for(int i=0;i<calendarArray.size();i++){
    *calendarArray[i]=func(*calendarArray[i]);
  }
}

Calendar TimeLord::returnFirst(){
  return *calendarArray[0];
}

void TimeLord::printTimeLord(){
  cout<<name<<endl;
  for (int i = 0; i <calendarArray.size(); i++) {
    cout<<*calendarArray[i]<<endl;
  }
  cout<<endl;
}
