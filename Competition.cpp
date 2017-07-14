#include "Competition.h"
#include "stdlib.h"
#include "time.h"
#include<string>
#include<iostream>

using namespace std;

Competition::Competition(std::string place,Date date)
{
  this->place=place;
  this->date=date;
}

Competition::~Competition()
{
   for (int i = 0; i <listOfParticipants.size(); i++) {
        delete listOfParticipants[i];
   }
}

bool Competition::registrateLord(TimeLord& timeLord){
  TimeLord* l=new TimeLord(timeLord);
  if(timeLord.canVisit(place,date,0,24)){
    listOfParticipants.push_back(l);
    return true;
  }
  return false;
}

int Competition::numParticipants(){
    return listOfParticipants.size();
}

void Competition::printParticipants(){
  for (int i = 0; i <listOfParticipants.size(); i++) {
    listOfParticipants[i]->printTimeLord();
  }
}

TimeLord& Competition::winner(){
  int randomNum;
  srand(time(NULL));
  randomNum=rand()%listOfParticipants.size();
  return *listOfParticipants[randomNum];
}
