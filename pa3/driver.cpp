#include <iostream>
#include <fstream>
#include <sstream>
#include "priorityarrayqueue.h"
#include "arrayqueue.h"
#include "event.h"
#define FILE "events.txt"

using namespace std; //I'm sorry :( // blashpemy *tsk* *tsk*
int loadEvents();
void processArrival(bool, PriorityArrayQueue<Event>, ArrayQueue<Event>);
void processDeparture(bool, PriorityArrayQueue<Event>, ArrayQueue<Event>);


void processArrival(bool tellerAvailable, PriorityArrayQueue<Event> processedLine, ArrayQueue<Event> line){
    /*
    get  event  from  events  priority  queue,  decide  if  event  should  be  processed,  
    otherwise add to line queue. If event should be processed,  create departure event 
    and add it to events priority queue,  teller is in use
    */
    while(!line.isEmpty()){
        if(tellerAvailable){
            processDeparture(tellerAvailable, processedLine, line); 
            processedLine.enqueue(line.peekFront()); // add it to events priority queue
            //tellerAvailable = false;
            line.dequeue();
        }else{
            line.enqueue(line.peekFront());
        }
    }
}

void processDeparture(bool tellerAvailable, PriorityArrayQueue<Event> processedLine, ArrayQueue<Event> line){
    /*
     get event from events priority queue, decide if there’s a customer in line, 
     otherwise teller is free. If there’s a customer, create departure event 
     and add it to events priority queue, teller is in use
    */
    while(!line.isEmpty()){ // if there’s a customer in line
        if(tellerAvailable){
            int departure = line.getTotal() + (line.peekFront().getEventDuration());
            line.setTotal(departure);
            line.peekFront().setEventDeparture(departure);
        }else{
            tellerAvailable = true;
        }
    }
    /* 
    - otherwise teller is free. 
    - If there’s a customer, create departure event and add it to events priority queue, teller is in use
    */
}

int main(){
    ArrayQueue<Event> line;
    PriorityArrayQueue<Event> processedLine;
    PriorityArrayQueue<Event> aLine;
    PriorityArrayQueue<Event> dLine;

    bool tellerAvailable;
    int timeSum = 0;
    int customers = loadEvents();
    int aCounter = 0;
    int dCounter = 0;
    
    /*
    - While there are events in the priority queue, look at current event. 
    - Depending  on  the  event  type,   process  the  arrival  or  departure. 
    - Update  number  of  customers and wait time values. Output the final results.
    */
    while(!processedLine.isEmpty()){
        aLine.enqueue(processedLine.peekFront());
        dLine.enqueue(processedLine.peekFront());
        processedLine.dequeue();
    }

    for(int i = 0;!aLine.isEmpty();i++){
        if((aLine.peekFront()).getEventTime() < (dLine.peekFront()).getEventDeparture()){
            cout << aLine.peekFront();
            aLine.dequeue();
        }else if((aLine.peekFront()).getEventTime() >= (dLine.peekFront()).getEventDeparture()){
            cout << dLine.peekFront();
            dLine.dequeue();
        }
    }
    for(int i = 0;!dLine.isEmpty();i++){
        cout << dLine.peekFront();
        timeSum = (dLine.peekFront()).getEventDeparture();
        dLine.dequeue();
    }
    cout << "Simulation ends" << endl;
    float average = timeSum/customers;
    cout << "Final statistics: " << endl;
    cout << "   Total number of people processed: " << customers << endl;
    cout << "   Average customer wait time :" << average << endl;
    return 0;
}

int loadEvents(){
    int arrival;
    int duration;
    string data;
    int sum = 0;
    ArrayQueue<Event> line;
    PriorityArrayQueue<Event> priorityLine;

    ifstream file(FILE);
	if(file.is_open()){
	    while(getline(file, data)){
            istringstream eventInfo(data);
            eventInfo >> arrival >> duration;

            if(eventInfo.fail()){
                string loadError = "The data file is not formatted correctly";
                throw runtime_error(loadError);
            }

            sum++;
            Event newEvent;
            newEvent.setEventTime(arrival);
            newEvent.setEventDuration(duration);
            line.enqueue(newEvent);
	    }
	}else{
	    string error = "File could not be opened";
	    throw runtime_error(error);
	}
    return sum;
}