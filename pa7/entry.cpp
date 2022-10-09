#ifndef ENTRY_CPP
#define ENTRY_CPP

#include "entry.h"

template<class KeyType, class ValueType>
Entry<KeyType, ValueType>::Entry() : key(0), value(0){}

template<class KeyType, class ValueType>
Entry<KeyType, ValueType>::Entry(const KeyType& newKey, const ValueType& newValue) : key(newKey), value(newValue){}

template<class KeyType, class ValueType>
ValueType Entry<KeyType, ValueType>::getValue() const{
    return value;
}

template<class KeyType, class ValueType>
KeyType Entry<KeyType, ValueType>::getKey() const{
    return key;
}

template<class KeyType, class ValueType>
void Entry<KeyType, ValueType>::setValue(const ValueType& newValue){
    value = newValue;
}

template<class KeyType, class ValueType>
void Entry<KeyType, ValueType>::setKey(const KeyType& searchType){
    key = searchType;
}

// bool operator==(const Entry<class KeyType, class ValueType>& rhs const);
// bool operator>(const Entry<class KeyType, class ValueType>& rhs const);

#endif