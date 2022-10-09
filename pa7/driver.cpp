#include <iostream>
#include <string>
#include "dictionary.h"
#define DICTIONARY_LENGTH 10

/*
Build a program for managing your Contact List. 
Each contact should consist of a name and a phone number. 
You should be able to add, update, search, delete, and display all contacts.
*/

int main(){
    int choice;
    Dictionary<std::string, std::string> phonebook;

    do{
        std::cout << "\nCONTACT LIST\n1. add\n2. update\n3. search\n4. delete\n5. display\n0. Exit\n" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 1:{ // add
                std::string name, phoneNumber;
                std::cout << "what is your frind's name? ";
                std::cin >> name;
                std::cout << "what is your frind's number? ";
                std::cin >> phoneNumber;
                phonebook.add(name, phoneNumber);
                break;
            }case 2:{ // update
                std::string name, phoneNumber;
                std::cout << "who's number do you want to update? ";
                std::cin >> name;
                std::cout << "what is their phone number? ";
                std::cin >> phoneNumber;
                phonebook.update(name, phoneNumber);
                break;
            }case 3:{ // search
                std::string name;
                std::cout << "who would you like to look up? ";
                std::cin >> name;
                phonebook.search(name);
                break;
            }case 4:{ // delete
                std::string name;
                std::cout << "who would you like to delete? ";
                std::cin >> name;
                phonebook.remove(name);
                break;
            }case 5:{ // display
                phonebook.display();
                break;}
            case 0: // exit
                return 0;
        }
    }while(choice != 0);
    return 0;
}