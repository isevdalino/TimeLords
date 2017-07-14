#include "Event.h"
#include <string>
#include <iostream>
#include "Date.h"

Event::Event(const Date& date, int start, int end,std::string location,std::string title, std::string description)
:date(date),startHour(start),endHour(end), title(title),description(description),location(location)
{

}

Event::~Event () {

}

int Event::getSH(){
  return startHour;
}

int Event::getEH(){
  return endHour;
}

Date Event::getDate(){
  return date;
}

std::string Event::getTitle(){
  return title;
}

std::string Event::getDescription(){
  return description;
}

std::string Event::getLocation(){
  return location;
}

bool Event::isInProgress(const Date& when, int hour) const {
    return date == when && hour >= startHour && hour < endHour;
}

std::ostream& Event::write(std::ostream& out) const {
    out << title << " " << date <<
        " (from " << startHour << "h to " << endHour << "h)"<<" at "<<location << std::endl;
    out << description << std::endl;
    return out;
}

std::ostream& operator<< (std::ostream& out, const Event& e) {
    return e.write(out);
}

std::istream& operator>> (std::istream& in, Event& e) {
    in >> e.title;
    in >> e.date;
    in >> e.startHour >> e.endHour;
    in >> e.description;
    return in;
}

 bool Event::isHappeningAt(std::string place,Date date,int sH,int eH){
   if(location==""){
     //return (date==this->date)&&(sH>=startHour)&&(eH<=endHour);
     return (date==this->date)&&(((sH>=startHour)&&(eH<=endHour))||((sH>startHour&&sH<endHour)||(eH>startHour&&eH<endHour)));
   }
   return (location==place)&&(date==this->date)&&(((sH==startHour)&&(eH==endHour))||((startHour>sH&&startHour<eH)||(endHour>sH&&endHour<eH)));
   //return (location==place)&&(date==this->date)&&(sH>=startHour)&&(eH<=endHour);
 }
