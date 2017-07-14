#include "Competition1.h"
#include "TimeLord.h"
Competition1::Competition1(std::string s,Date date):Competition(s,date)
{

}

Competition1::~Competition1()
{

}

int numEvents(int a,Calendar cal){
  a+=cal.getCalSize();
  return a;
}

TimeLord& Competition1::winner(){
   int max1=0;
   int max2=0;
   for(int i=0;i<listOfParticipants.size();i++){
     if(listOfParticipants[i]->reduce(numEvents,0)>max1){
          max1=listOfParticipants[i]->reduce(numEvents,0);
          max2=i;
     }
   }
   return *listOfParticipants[max2];
}
