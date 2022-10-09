//Paige Mortensen
//cs302 - data structures
//linked list
//9-18-21

#include <iostream>
#include <string>
#include "linkedlist.h"

void displayList(LinkedList<std::string>&);
void deleteTask(LinkedList<std::string>&);
void addTask(LinkedList<std::string>&);
void replaceTask(LinkedList<std::string>&);

int main(){
    int choice;
    LinkedList<std::string> stringList;

    do{
        std::cout << "\nTODO LIST\n1. Add task\n2. Complete task\n3. Display list\n4. Complete list\n0. Exit\n" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 1:
                addTask(stringList);
                break;
            case 2:
                deleteTask(stringList);
                break;
            case 3:
                displayList(stringList);
                break;
            case 4:
                stringList.clear();
                break;
            case 0: // exit
                return 0;
        }
    }while(choice != 0);

    return 0;
}

void displayList(LinkedList<std::string>& list){
    if(list.isEmpty()){
        std::cout << "No Tasks Currently!" << std::endl;
    }else{
        for(int pos=1; pos<=list.getLength(); pos++){
            std::cout << pos << ": " << list.getEntry(pos) << std::endl;
        }
    }
    return;
}

void deleteTask(LinkedList<std::string>& list){
    if(list.isEmpty()){
        std::cout << "No Tasks Currently!" << std::endl;
    }else{
        int pos;
        std::string temp;
        displayList(list);
        
        std::cout << "Which task would you like to complete?" << std::endl;
        std::cin >> pos;

        temp = list.getEntry(pos);

        if(list.remove(pos)){
            std::cout << "Removed " << temp << std::endl;
        }else{
            std::cout << "Could not remove " << temp << std::endl;
        }
    }
    return;
}

void addTask(LinkedList<std::string>& list){
    int priority;
    std::string newTask;

    displayList(list);

    std::cout << "What is the priority of your task?" << std::endl;
    std::cin >> priority;
    std::cout << "What is your new task? " << std::endl;
    std::cin >> newTask;

    if((priority>=1) && (priority<=list.getLength()+1)){
        list.insert(priority, newTask);
    }else{
        std::cout << "Please chose a priority between 1 and " << list.getLength()+1 << std::endl;
    }
}