#include <string>
#include "event.h"

Event::Event() : time(), duration(), type(), departure() {}

int Event::getEventTime(){
    return time;
}

int Event::getEventDuration(){
    return duration;
}

int Event::getEventDeparture(){
    return departure;
}

char Event::getEventType(){
    return type;
}

void Event::setEventTime(int newTime){
    time = newTime;
}

void Event::setEventDuration(int newDuration){
    duration = newDuration;
}

void Event::setEventDeparture(int newDeparture){
    departure = newDeparture;
}

void Event::setEventType(char newType){
    type = newType;
}

// operator overloads
// **least (in value) takes highest priority**
inline bool operator < (Event event1, Event event2){
    return event1.getEventTime() > event2.getEventTime();
}

inline bool operator > (Event event1, Event event2){
    return event1.getEventTime() < event2.getEventTime();
}

inline bool operator == (Event event1, Event event2){
    return event1.getEventTime() == event2.getEventTime();
}

std::ostream& operator << (std::ostream& out, const Event& event){
    if(event.type == 'a'){
        out << "Processing an arrival event at time: " << event.time << std::endl;
    }else if(event.type == 'd'){
        out << "Processing a departure event at time: " << event.departure << std::endl;
    }
    return out;
}