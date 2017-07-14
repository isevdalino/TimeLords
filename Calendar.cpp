#include "Calendar.h"
#include "WeeklyEvent.h"

void Calendar::init(const Calendar& other) {
    name = other.name;
    events = other.events;
    for (unsigned int i = 0; i < events.size(); i++) {
        // copy the events so that they are not shared
        // between the calendars
        events[i] = new Event(*events[i]);
    }
}

void Calendar::destroy() {
    // delete all events that we have created using new
    for (unsigned int i = 0; i < events.size(); i++) {
        delete events[i];
    }
}

Calendar::Calendar(std::string name): name(name) {
    // empty implementation
    // events is automatically initialized
    // using its default constructor
}

Calendar::Calendar(const Calendar& other) {
    init(other);
}

Calendar::~Calendar()
{
    destroy();
}

Calendar& Calendar::operator=(const Calendar& other) {
    if (this != &other) {
        destroy();
        init(other);
    }
    return *this;
}

std::string Calendar::getName() const{
    return name;
}

void Calendar::rename(const std::string& newName) {
    name = newName;
}

bool Calendar::isFree(const Date& date, int hour) const {
    for (unsigned int i = 0; i < events.size(); i++) {
        if (events[i]->isInProgress(date, hour)) {
            return false;
        }
    }
    return true;
}

void Calendar::addEvent(const Date& date, int start, int end,std::string s, std::string title, std::string descr) {
    Event* e = new Event(date, start, end,s, title, descr);
    events.push_back(e);
}

void Calendar::addEvent(Event& event) {
    events.push_back(&event);
}

/*void Calendar::addWeeklyEvent(const Date& date, int start, int end, int numReps,std::string title, std::string descr) {
    Event* we = new WeeklyEvent(date, start, end, numReps, title, descr);
    events.push_back(we);
}*/

/*void Calendar::operator+=(const Calendar& other) {
    for(int i=0;i<other.events.size();i++){
      this->addEvent(*other.events[i]);
    }
}*/
void Calendar::operator+=(const Calendar& other) {
    for(int i=0;i<other.events.size();i++){
      this->addEvent(other.events[i]->getDate(),other.events[i]->getSH(),other.events[i]->getEH(),
      other.events[i]->getLocation(),other.events[i]->getTitle(),other.events[i]->getDescription());
    }
}
/*
bool cancelEvent(const Event& event);
bool cancelEvents(const Date& date);
*/

int Calendar::getCalSize(){
  return events.size();
}

std::ostream& operator<< (std::ostream& out, const Calendar& cal) {
    out <<"Calendar: " << cal.name << std::endl;
    out << "Events:" << std::endl;
    for (unsigned i = 0; i < cal.events.size(); i++) {
        out << *cal.events[i] ;//<< std::endl;
    }
    return out;
}

bool Calendar::hasEventAt(std::string place,Date date,int sH,int eH){
  for(int i=0;i<events.size();i++){
    if(events[i]->isHappeningAt(place,date,sH,eH)&&(events[i]->getLocation()==place)){
        return true;
    }
  }
  return false;
}


Date Calendar::returnEarliestDate(){
  Date max=events[0]->getDate();
  for(int i=1;i<events.size();i++){
    if(events[i]->getDate()<max){
      max=events[i]->getDate();
    }
  }
  return max;
}

int Calendar::timeSpendInCentury(int i){
  int sum=0;
  int a=i*100;
  int b=(i*100)-100;
  for(int i=0;i<events.size();i++){
    if((events[i]->getDate().getYear()<=a)&&(events[i]->getDate().getYear()>=b)){
        sum+=(events[i]->getEH()-events[i]->getSH());
    }
  }
  return sum;
}
