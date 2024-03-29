#include "sequential-list.h"
#include <iostream>
using namespace std;

SequentialList::SequentialList(unsigned int cap) {
    size_ = 0;
    capacity_ = cap;
    DataType *array= new DataType[capacity_];
    data_=array;
}


SequentialList::~SequentialList() {
    delete[] data_;
    data_ = NULL;
}


unsigned int SequentialList::size() const {
    return size_;
}


unsigned int SequentialList::capacity() const {
    return capacity_;
}


bool SequentialList::empty() const {
    if(size_ == 0)
        return true;
    else
        return false;
}


bool SequentialList::full() const {
    if(size_ == capacity_)
        return true;
    else
        return false;
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
    if(index < 0 || index >= size_)
    {
        return data_[size_-1];
    }
    for(unsigned int i = 0; i < size_; i++)
    {
        if (i == index)
            return data_[i];

    }
}


unsigned int SequentialList::search(DataType val) const {
    //bool found = false;
    for(unsigned int i = 0; i < size_; i++)
    {
        if(data_[i] == val) {
            return i;
            //found = true;
            break;
        }
    }


    return size_;


}


void SequentialList::print() const {
    for(int i = 0; i < size_; i++)
    {
        cout << data_[i] << ", ";
    }
    cout << endl;
}


bool SequentialList::insert(DataType val, unsigned int index) {
    if(index < 0 || index > size_ || full())
        return false;
    for(unsigned int i = size_; i > index; i--)
    {
        data_[i] = data_[i-1];
    }
    data_[index] = val;

    size_++;
    return true;
}


bool SequentialList::insert_front(DataType val) {
    if(full())
        return false;
    for(unsigned int i = size_; i > 0; i--)
    {
        data_[i] = data_[i-1];
    }
    data_[0] = val;

    size_++;
    return true;
}


bool SequentialList::insert_back(DataType val) {
    if(full())
        return false;
    data_[size_] = val;

    size_++;
    return true;


}


bool SequentialList::remove(unsigned int index) {
    if (empty() || index < 0|| index > size_-1){
        return false;
    }

    for(unsigned int i = index; i < size_; i++)
    {
            data_[i] = data_[i+1];
    }

    size_--;
    return true;
    }



bool SequentialList::remove_front() {
    if (empty()){
        return false;
    }
    for(unsigned int i = 0; i < size_-1; i++){
        data_[i]=data_[i+1];
    }
    size_--;
    return true;
}


bool SequentialList::remove_back() {

    if (full())
        return false;

    data_[size_-1] = NULL;
    size_--;
    return true;
}


bool SequentialList::replace(unsigned int index, DataType val) {
    if(index < 0 || index > size_-1)
        return false;
    for(unsigned int i = 0; i < size_; i++)
    {
       if(i == index)
           data_[i] = val;
    }
}
