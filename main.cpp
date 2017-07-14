#include <iostream>
#include <vector>
#include "TimeLord.h"
#include "Event.h"
#include "Date.h"
#include "Calendar.h"
#include "Competition.h"
#include "Competition1.h"
#include "Competition2.h"
#include "Competition3.h"

using namespace std;

int main()
{
    Date date(1970,1,1);
    Date date1(2016,5,1);
    Date date2(1453,5,29);
    Date date3(1421,11,1);
    Date date4(1989,11,10);
    Date date5(1997,1,23);
    Date date6(1963,11,22);
    TimeLord theTimeLord("The Doctor");
    TimeLord anotherTimeLord("The Monk");
    TimeLord testTimeLord("Joe");
    theTimeLord.newCalendar();
    theTimeLord.newEvent(date1,15,16,"UNSS");
    theTimeLord.newEvent(date1,14,15,"FMI");
    theTimeLord.newEvent(date1,16,17,"TU");
    theTimeLord.newCalendar();
    theTimeLord.newEvent(date2,1,2,"Constantinople");
    theTimeLord.newEvent(date4,18,22,"Sofia");
    theTimeLord.newEvent(date5,0,6,"Novy pazar");
    anotherTimeLord.newCalendar();
    anotherTimeLord.newEvent(date6,10,13,"Dallas");
    anotherTimeLord.newEvent(date3,0,16,"Salty Spear");
    anotherTimeLord.newEvent(date1,16,17,"YASG");
    anotherTimeLord.newCalendar();
    anotherTimeLord.newEvent(date2,1,2,"Constantinople");
    anotherTimeLord.newEvent(date4,18,22,"Sofia");
    anotherTimeLord.newEvent(date5,0,6,"Novy pazar");
    anotherTimeLord.newEvent(date4,18,22,"Sofia");
    testTimeLord.newCalendar();
    testTimeLord.newEvent(date,18,22,"Wonderlands");
    //Ex 1 test
    cout<<"All archives of The Doctor:"<<endl;
    cout<<theTimeLord.allArchives()<<endl;
    cout<<"Can The Doctor visit fmi at 01.05.2016 between 10 and 11 o'clock?"<<endl;
    theTimeLord.canVisit("FMI",date1,10,11)?cout<<"Yes\n":cout<<"No\n";
    cout<<"Can The Doctor visit fmi at 01.05.2016 between 13 and 15 o'clock?"<<endl;
    theTimeLord.canVisit("FMI",date1,13,15)?cout<<"Yes\n":cout<<"No\n";
    cout<<endl;
    //Ex 2 test
    Competition* comp=new Competition("Wonderlands",date);
    Competition* comp1=new Competition1("Sofia",date2);
    Competition* comp2=new Competition2("Beijing",date3);
    Competition* comp3=new Competition3("Kings Landing",date1);
    //Successfully registrating 2 time lords in each competition
    comp->registrateLord(theTimeLord)?cout<<"Successful registration\n":cout<<"Unsuccessful registration\n";
    comp->registrateLord(anotherTimeLord)?cout<<"Successful registration\n":cout<<"Unsuccessful registration\n";
    comp1->registrateLord(theTimeLord)?cout<<"Successful registration\n":cout<<"Unsuccessful registration\n";
    comp1->registrateLord(anotherTimeLord)?cout<<"Successful registration\n":cout<<"Unsuccessful registration\n";
    comp2->registrateLord(theTimeLord)?cout<<"Successful registration\n":cout<<"Unsuccessful registration\n";
    comp2->registrateLord(anotherTimeLord)?cout<<"Successful registration\n":cout<<"Unsuccessful registration\n";
    comp3->registrateLord(theTimeLord)?cout<<"Successful registration\n":cout<<"Unsuccessful registration\n";
    comp3->registrateLord(anotherTimeLord)?cout<<"Successful registration\n":cout<<"Unsuccessful registration\n";
    //Unsuccessfully registrating time lord in the first competition
    comp->registrateLord(testTimeLord)?cout<<"Successful registration\n":cout<<"Unsuccessful registration\n";
    //Creating a list of competitions
    vector<Competition*> competitions;
    competitions.push_back(comp);
    competitions.push_back(comp1);
    competitions.push_back(comp2);
    competitions.push_back(comp3);
    //Printing the winner in each competition
    competitions[0]->winner().printTimeLord();
    competitions[1]->winner().printTimeLord();
    competitions[2]->winner().printTimeLord();
    competitions[3]->winner().printTimeLord();
    return 0;
}

