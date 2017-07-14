#include "Competition2.h"

Competition2::Competition2(std::string s,Date date):Competition(s,date)
{

}

Competition2::~Competition2()
{

}

Date earliestVisitedDate(Date a,Calendar cal){
  if(cal.returnEarliestDate()<a){
    return cal.returnEarliestDate();
  }
  return a;
}

TimeLord& Competition2::winner(){
   Date max1=listOfParticipants[0]->reduce(earliestVisitedDate,listOfParticipants[0]->returnFirst().returnEarliestDate());
   int max2=0;
   for(int i=1;i<listOfParticipants.size();i++){
      if(listOfParticipants[i]->reduce(earliestVisitedDate,listOfParticipants[i]->returnFirst().returnEarliestDate())<max1){
        max1=listOfParticipants[i]->reduce(earliestVisitedDate,listOfParticipants[i]->returnFirst().returnEarliestDate());
        max2=i;
      }
   }

   return *listOfParticipants[max2];
}
