#ifndef ENTRY_H
#define ENTRY_H

template<class KeyType, class ValueType>
class Entry{
private: 
    KeyType key; // name
    ValueType value; // node
public:
    Entry();
    Entry(const KeyType& newKey, const ValueType& newValue);
    ValueType getValue() const;
    KeyType getKey() const;
    void setValue(const ValueType& newValue);
    void setKey(const KeyType& searchType);
};

#include "entry.cpp"
#endif