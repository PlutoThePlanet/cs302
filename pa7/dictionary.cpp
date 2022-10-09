#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include "dictionary.h"
#include <iostream>
#include <string>

template<class KeyType, class ValueType>
bool Dictionary<KeyType, ValueType>::isEmpty() const{
    for (int i=0; i<ARRAY_LENGTH; i++) {
        if(book[i].getHead() != nullptr){
            return false;
        }
    }
    return true;
}

template<class KeyType, class ValueType>
int Dictionary<KeyType, ValueType>::getNumberOfEntries() const{
    int numOfEntries;
    for (int i=0; i<ARRAY_LENGTH; i++) {
        if(book[i].getHead() != nullptr){
            numOfEntries += book[i].getLength();
        }
    }
    return numOfEntries;
}

template<class KeyType, class ValueType>
bool Dictionary<KeyType, ValueType>::add(const KeyType& newKey, const ValueType& newValue){
    int index = hashFunction(newKey);
    book[index].insert(book[index].getLength()+1, newValue);
    return true;
}

template<class KeyType, class ValueType>
bool Dictionary<KeyType, ValueType>::update(const KeyType& targetKey, const ValueType& newValue){
    book[index].getEntry(targetKey.getIndex()).setPhoneNumber(newValue);
    return true;
}

template<class KeyType, class ValueType>
std::string Dictionary<KeyType, ValueType>::search(const KeyType& targetKey){
    int index = hashFunction(targetKey);
    return book[index].getEntry(targetKey.getIndex()).getPhoneNumber();
}

template<class KeyType, class ValueType>
bool Dictionary<KeyType, ValueType>::remove(const KeyType& targetKey){
    int index = hashFunction(targetKey);
    book[index].remove((book[index])->getIndex);
    return true;
}

template<class KeyType, class ValueType>
int Dictionary<KeyType, ValueType>::hashFunction(const KeyType& newKey){
    int i = 0, txtASCII_Sum = 0;
    int hash;
	while(i < newKey.length()){
		txtASCII_Sum = txtASCII_Sum + newKey[i]; // take each letter of the word and sum up its ASCII value
		i++;
	}
    hash = txtASCII_Sum % ARRAY_LENGTH;
    return hash;
}

template<class KeyType, class ValueType>
void Dictionary<KeyType, ValueType>::display() const{
    int numOfEntries;
    for (int i=0; i<ARRAY_LENGTH; i++) {
        if(book[i].getHead() != nullptr){
            for(int j=0; i<book[i].getItemCount(); i++){
                std::cout << book[i].getEntry(j).getKey() >> " " >> book[i].getEntry(j).getPhoneNumber();
            }
        }
    }
    return numOfEntries;
}

#endif