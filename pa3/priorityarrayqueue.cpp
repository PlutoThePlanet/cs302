#ifndef P_ARRAY_QUEUE_CPP
#define P_ARRAY_QUEUE_CPP

#include <exception>
#include <iostream>
#include "priorityarrayqueue.h"

template<class ItemType>
PriorityArrayQueue<ItemType>::PriorityArrayQueue() : front(0), back(0), count(0){}

template<class ItemType>
bool PriorityArrayQueue<ItemType>::isEmpty() const{
    return count == 0;
}

template<class ItemType>
bool PriorityArrayQueue<ItemType>::enqueue(const ItemType& newEntry){
    if(this->isEmpty()){ // array is empty, increment back and add item to the end
        back++;
        items[back] = newEntry;
    }else{ // array is not empty
        int newIndex;
        for(int i=0; i <= back; i++){ // assuming that we will never enqueue after dequeuing
            if(newEntry < items[i]){ // find the highest priority location
                newIndex = i;
            }
        }
        for(int i=count-1; i >= newIndex; i--){ // shift the elements back to make room
            items[i+1] = items[i];
        }
        items[newIndex] = newEntry;
    }
}

template<class ItemType>
bool PriorityArrayQueue<ItemType>::dequeue(){ //circular implementation
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
ItemType PriorityArrayQueue<ItemType>::peekFront() const {
    if(this->isEmpty()){
        std::cout << "peekFront() called with empty queue" << std::endl;
    }else{
        return items[front];
    }
}

#endif