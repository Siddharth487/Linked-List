#include "doubly-linked-list.h"
#include <iostream>
#include <cstdlib>
using namespace std;

DoublyLinkedList::Node::Node(DataType data) {
    prev = nullptr;
    value= data;
    next = nullptr;
}

DoublyLinkedList::DoublyLinkedList() {
    this -> head_ = nullptr;
    this -> tail_ = head_;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node *temp_ = head_;


    while(temp_ != nullptr)
    {
        Node *newNode = temp_;
        temp_ = temp_-> next;
        delete newNode;
    }

}


unsigned int DoublyLinkedList::size() const {
    return size_;
}


unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}


bool DoublyLinkedList::empty() const {
    if (size_ == 0)
        return true;
    else
        return false;
}


bool DoublyLinkedList::full() const {
    if(size_ == CAPACITY)
        return true;
    else
        return false;
}


DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    if(index < 0 || index > size_-1)
        return tail_ -> value;
    if(this -> empty())
        return false;
    Node* newNode = getNode(index);
    return newNode -> value;
}


unsigned int DoublyLinkedList::search(DataType value) const {
    if(this -> empty())
        return false;
    Node* newNode = head_;
    for(int i = 0; i <= size_-1; i++)
    {
        if(newNode -> value == value) {
            return i;
        }
        newNode = newNode -> next;
    }
    return size_;
}


void DoublyLinkedList::print() const {
    if(head_ == nullptr)
        return;
    Node *temp_ = head_;
    while(temp_ != nullptr){
        cout << temp_-> value << "->";
        temp_ = temp_ -> next;
    }
    cout << endl;

}


DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    Node* newNode = head_;
    if(index < 0 || index > size_-1)
        return nullptr;
    for(unsigned int i = 0; i < index; i++)
    {
        newNode = newNode-> next;
    }
    return newNode;
}


bool DoublyLinkedList::insert(DataType value, unsigned int index) {

    Node *newNode = new Node(value);

    if(index < 0 || index > size_ || full())
        return false;
    if(size_ == 0)
    {
        head_ = newNode;
        tail_ = newNode;
    }

    else if(index == 0)
    {
        Node *curr = getNode(index);
        curr -> prev = newNode;
        newNode -> next = curr;
        newNode -> prev = nullptr;
        head_ = newNode;
    }

    else if(index == size_)
    {
        tail_ -> next = newNode;
        newNode -> prev = tail_;
        newNode -> next = nullptr;
        tail_ = newNode;


    }
    else
    {
        Node *curr = getNode(index);
        curr -> prev -> next = newNode;
        newNode -> prev = curr -> prev;
        newNode -> next = curr;
        curr -> prev= newNode;
    }

    size_++;
    return true;
}


bool DoublyLinkedList::insert_front(DataType value) {
    int index = 0;
    return  insert(value, index);

}



bool DoublyLinkedList::insert_back(DataType value) {
    return insert(value, size_);
}


bool DoublyLinkedList::remove(unsigned int index) {
    if (index < 0 || index > size_ || empty())
        return false;
    Node *temp = getNode(index);

    if(index == 0){
        head_ = temp->next;
        delete temp;
        temp = nullptr;
        size_--;
        return true;
    }

    if(index == size_-1)
    {
        tail_ = temp -> prev;
        tail_ -> next = nullptr;
        delete temp;
        temp = nullptr;
        size_--;
        return true;
    }

    else {
      //  Node *before = temp -> prev;
        Node *after = temp -> next;
        after -> prev = temp -> prev;
        temp -> prev = temp -> next;
        temp -> next = after;
        delete temp;
        temp = nullptr;
        size_--;
        return true;

    }
    }

bool DoublyLinkedList::remove_front() {
    return remove(0);
}

bool DoublyLinkedList::remove_back() {
    return remove(size_-1);
}


bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    Node* newNode = getNode(index);
    newNode -> value = value;
    return newNode;
}

