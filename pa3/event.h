#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>

class Event{
private:
    int time;
    int duration;
    int departure;
    char type;
public:
    Event();
    int getEventTime();
    int getEventDuration();
    int getEventDeparture();
    char getEventType();
    void setEventTime(int newTime);
    void setEventDuration(int newDuration);
    void setEventDeparture(int newDeparture);
    void setEventType(char newType);
    friend std::ostream& operator << (std::ostream& out, const Event& event);
    friend inline bool operator < (Event event1, Event event2);
    friend inline bool operator > (Event event1, Event event2);
    friend inline bool operator == (Event event1, Event event2);
};

#endif