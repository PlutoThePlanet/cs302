#ifndef ARRAY_QUEUE_CPP
#define ARRAY_QUEUE_CPP

#include <exception>
#include <iostream>
#include "arrayqueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(0), count(0), totalTime(0){} // end default constructor

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const{
    return (count == 0);
}

template<class ItemType>
int ArrayQueue<ItemType>::getTotal(){
    return totalTime;
}
template<class ItemType>
void ArrayQueue<ItemType>::setTotal(int newTotal){
    totalTime = newTotal;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry){ // circular implementation
    bool canEnqueue = (count <= DEFAULT_CAPACITY);
    if(back = DEFAULT_CAPACITY-1){
        back = 0;
        items[back] = newEntry;
        count++;
    }else if(count == 0){
        items[back] = newEntry;
        count++;
    }else{
        back++;
        items[back] = newEntry;
        count++;
    }
    return canEnqueue;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue(){ //circular implementation
    bool canDequeue = !(this->isEmpty());
    if(front == (DEFAULT_CAPACITY-1)){
        front = 0;
        count--;
    }else if(front != back){
        front++;
        count--;
    }else{
        count--;
    }
    return canDequeue;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const{
    if(this->isEmpty()){
        std::cout << "peekFront() called with empty queue" << std::endl;
    }else{
        return items[front];
    }
}

#endif