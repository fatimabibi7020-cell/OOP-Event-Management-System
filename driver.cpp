//Driver.cpp main file
#include<iostream>
#include "event.h"
using namespace std;

//Global Variables
Event* events=new Event[3];
int count=0;

//Function
void addEventOver()
{
        if(count>=3)
        {
            cout<<"Event list is full,Can't add more:"<<endl;
            return;
        }
    cout<<"\n--- Add New Event(Using Overloaded Constructor) ---"<<endl;

    //Temporary Variables
        char tempName[20];
        char tempVenue[50];
        char tempDate[11];
        char tempTime[9];

    cout<<"Enter event name: ";
    cin.ignore();
    cin.getline(tempName,20);
    cout<<"Enter event venue: ";
    cin.getline(tempVenue,50);
    cout<<"Enter event date(dd-mm-yyyy): ";
    cin.getline(tempDate,11);
    cout<<"Enter event time(hh:mm AM/PM): ";
    cin.getline(tempTime,9);

         events[count].setEventName(tempName);
         events[count].setEventVenue(tempVenue);
         events[count].setEventDate(tempDate);
         events[count].setEventTime(tempTime);
 
    count++;
    cout<<"Event added successfully!"<<endl;
}

//AddEvent Function
void addEventSet()
{
        if(count>=3)
        {
            cout<<"Event list is full,Can't add more:"<<endl;
            return;
        }
    cout<<"\n--- Add New Event(Using Setters) ---"<<endl;
    events[count].userInput();
    count++;
    cout<<"Event added successfully!"<<endl;
}

//Display Function
void displayEvents()
{
        if(count==0)
        {
            cout<<"\nNo events to display! "<<endl;
            return;
        }
    cout<<"\n============== All Events ===============" <<endl;
    for (int i=0;i<count;i++)
    {
        cout<<"\nEvent "<<(i+1) <<":"<<endl;
        cout<<" Name  : "<<events[i].getEventName()<<endl;
        cout<<" Venue  : "<<events[i].getEventVenue()<<endl;
        cout<<" Date  : "<<events[i].getEventDate()<<endl;
        cout<<" Time  : "<<events[i].getEventTime()<<endl;
    }
    cout<< "============================================="<<endl;
}

//MainFunction
int main()
{
    int choice;  
    do
    {
        cout<<"\n========== Menu Program =========="<<endl;
        cout<<"Add New Event Using Overloaded Constructor:Enter 1" <<endl;
        cout<<"Add New Event Using Setters              : Enter 2" <<endl;
        cout<<"Display All Events                       : Enter 3" <<endl;
        cout<<"Exit                                     : Enter 0" <<endl;
        cout<<"==================================" <<endl;
        cout<<"Enter your choice: ";
        cin>>choice;  
 
        if(choice==1)
        {
            addEventOver();   
        }
        else if(choice==2)
        {
            addEventSet();    
        }
        else if(choice==3)
        {
            displayEvents();  
        }
        else if(choice==0)
        {
            cout<<"\nExiting program..." <<endl;
        }
        else
        {
            cout<<"\nInvalid choice! Please try again."<<endl;
        }
 
    } while(choice!=0);  
 
    delete[] events;   
    events=nullptr;   
 
    return 0;  
}

