#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "dictionary.h"
#include "IDictionary.h"
#include "linkedlist.h"
#include <string>
#define ARRAY_LENGTH 10

template<class KeyType, class ValueType>
class Dictionary : public IDictionary<KeyType, ValueType>{
private:
    LinkedList<ValueType> book[ARRAY_LENGTH];
public: 
    bool isEmpty() const;
    int getNumberOfEntries() const;
    int hashFunction(const KeyType& newKey);
    bool add(const KeyType& newKey, const ValueType& newValue); // calls linkedlist add function
    bool update(const KeyType& targetKey, const ValueType& newValue);
    std::string search(const KeyType& targetKey);
    bool remove(const KeyType& targetKey);
    void display() const; // driver
    // void clear() = 0;
    // bool contains(const KeyType& targetKey) const;
    // ValueType getValue(const KeyType& targetKey) const;
    // ~Dictionary() {}
};

#include "dictionary.cpp"
#endif