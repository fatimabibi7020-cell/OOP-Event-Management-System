//Event.cpp actuall implementation//
#include<iostream>
#include "event.h"
using namespace std;

int myStrLen(char* str)
{
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}


//Helper Function
void myStrCopy(char* destination,char* source)
{
    int i=0;
    while(source[i]!='\0'){
        destination[i]=source[i];
        i++;
    }
    destination[i]='\0';
}

//Default Constructors
Event::Event()
{
    cout<< "Default Constructor is called"<<endl;
        event_name=nullptr;
        event_venue=nullptr;
    for(int i=0;i<11;i++)  event_date[i]='\0';
    for(int i=0;i<9;i++)   event_time[i]='\0';
}

//Overloaded Constructors
Event::Event(char event_name[20],char event_venue[50],char event_date[11],char event_time[9])
{
    cout<<"Overload Constructor is called"<<endl;
        int namelen=myStrLen(event_name);
        this->event_name= new char[namelen+1];
        myStrCopy(this->event_name,event_name);

        int venueLen=myStrLen(event_venue);
        this->event_venue= new char[venueLen+1];
        myStrCopy(this->event_venue,event_venue);

        myStrCopy(this->event_date,event_date);

        myStrCopy(this->event_time,event_time);
}

//Destructors
Event::~Event()
{
    cout<<"Destructor is called"<<endl;
        if(event_name!=nullptr)
        {
            delete[] event_name;
            event_name =nullptr;
        }
        if(event_venue!=nullptr)
      {
          delete[] event_venue;
         event_venue=nullptr;
      }
}

//Setters
void Event::setEventName(char* name)
{
        if(event_name!=nullptr)
        {
            delete[] event_name;
        }
    int len=myStrLen(name);
    event_name=new char[len+1];
    myStrCopy(event_name,name);
}

void Event::setEventVenue(char* venue)
{
        if(event_venue!=nullptr)
        {
            delete[] event_venue;
        }
    int len=myStrLen(venue);
    event_venue=new char[len+1];
    myStrCopy(event_venue,venue);
}

void Event::setEventDate(char* date)
{
    myStrCopy(event_date,date);
}

void Event::setEventTime(char* time)
{
    myStrCopy(event_time,time);
}

//Getters
char* Event::getEventName()
{
         return event_name;  
}
 
char* Event::getEventVenue()
{
         return event_venue;  
}
 
char* Event::getEventDate()
{
         return event_date;   
}
 
char* Event::getEventTime()
{
         return event_time;   
}

//Userinput
void Event::userInput()
{
     char tempName[20];
     char tempVenue[50];   
     char tempDate[11];    
     char tempTime[9];    
 
    cout<<"Enter event name:";
    cin.ignore();                  
    cin.getline(tempName,20);     
 
    cout<<"Enter event venue:";
    cin.getline(tempVenue,50);   
 
    cout<<"Enter event date (dd-mm-yyyy):";
    cin.getline(tempDate,11);     
 
    cout<<"Enter event time (hh:mm AM/PM):";
    cin.getline(tempTime,9);      
 
    setEventName(tempName);
    setEventVenue(tempVenue);
    setEventDate(tempDate);
    setEventTime(tempTime);
}