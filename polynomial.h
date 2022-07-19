#ifndef LAB1_POLYNOMIAL_H
#define LAB1_POLYNOMIAL_H
#include "doubly-linked-list.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Polynomial {

private:
    unsigned int size_;
    DoublyLinkedList list;

    // member to store the doubly linked list?

    friend class PolynomialTest ;
    // add the other private members


public:



    Polynomial(int A[], unsigned int size);


    Polynomial* add(Polynomial* rhs);


    Polynomial* sub(Polynomial* rhs);


    Polynomial* mul(Polynomial* rhs);


    void print();

};

#endif
