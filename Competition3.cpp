#include "Competition3.h"

Competition3::Competition3(std::string s,Date date):Competition(s,date)
{

}

Competition3::~Competition3()
{

}

int timeSpendInFifteenCentury(int a,Calendar cal){
  if(cal.timeSpendInCentury(15)>a){
    return cal.timeSpendInCentury(15);
  }
  return a;
}

TimeLord& Competition3::winner(){
   int max1=0;
   int max2=0;
   for(int i=0;i<listOfParticipants.size();i++){
     if(listOfParticipants[i]->reduce(timeSpendInFifteenCentury,0)>max1){
          max1=listOfParticipants[i]->reduce(timeSpendInFifteenCentury,0);
          max2=i;
     }
   }
   return *listOfParticipants[max2];
}
