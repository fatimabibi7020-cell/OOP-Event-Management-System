//event.h a blueprint of our class//
#ifndef EVENT_H
#define EVENT_H

class Event{
    //Private //
    private:
        char* event_name;
        char* event_venue;
        char event_date[11];
        char event_time[9];

        //Public//
    public:
        Event();
           
        Event(char event_name[20],char event_venue[50],char event_date[11],char event_time[9]);

        ~Event(); //Free Memory

        //Setters
    void setEventName(char* name);
    void setEventVenue(char* venue);
    void setEventDate(char* date);  
    void setEventTime(char* time);
    
        //Getters
    char* getEventName();
    char* getEventVenue();
    char* getEventDate();
    char* getEventTime();

        //Helper Function
    void userInput();
};

#endif