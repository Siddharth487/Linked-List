#include "polynomial.h"

// ask about calling polynomial indexes

Polynomial::Polynomial(int A[], unsigned int size)
{
    size_ = size;

    for(int i =0; i < size_; i++)
    {
        list.insert_back(A[i]);
    }

}

Polynomial* Polynomial::add(Polynomial* rhs)
{
    unsigned int psize;
    if(this->list.size() >= rhs->list.size())
        psize = this->list.size();
    else
        psize = rhs->list.size();

    int Add[psize];

    for(int i = 0; i < psize; i++)
    {

        if(i > this->list.size())
        {
            Add[i] = 0 + rhs->list.select(i);
        }

        else if(i > rhs->list.size())
        {
            Add[i] = this->list.select(i) + 0;
        }
        else
            Add[i] = this->list.select(i) + rhs->list.select(i);

    }
    /*
    for(unsigned int i = 0; i < size_; i++)
    {
        cout << Add[i] << ",";
    }
     */
    cout << endl;
    static Polynomial Newpoly(Add, psize);
    return &Newpoly;

}

Polynomial* Polynomial::sub(Polynomial* rhs)
{
    unsigned int psize;
    if(this->list.size() >= rhs->list.size())
        psize = this->list.size();
    else
        psize = rhs->list.size();

    int Sub[psize];
    for(int i =0; i < psize; i++)
    {
        Sub[i] = 0;
    }

    for(int i = 0; i < psize; i++)
    {
        if(i > this->list.size())
        {
            Sub[i] = 0 - rhs->list.select(i);
        }
        else if(i > rhs->list.size())
        {
            Sub[i] = this->list.select(i) - 0;
        }
        else
            Sub[i] = this->list.select(i) - rhs->list.select(i);

    }
    static Polynomial Newpoly(Sub, psize);
    return &Newpoly;
}

Polynomial* Polynomial::mul(Polynomial* rhs)
{

    unsigned int psize = (this->list.size())+(rhs->list.size());
    int Mul[psize];
    for(int i = 0; i < this->list.size(); i++)
    {
        for(int j = 0; j < rhs->list.size(); j++)
        {
            Mul[i+j] += (this->list.select(i))*(rhs->list.select(j));
        }
    }
    static Polynomial Newpoly(Mul, psize);
    return &Newpoly;
}

void Polynomial::print()
{
    unsigned int exp = size_-1;
    for(unsigned int i = size_; i > 0; i--)
    {
        if(this->list.select(i-1)  != 0) {
            if(list.select(i-1) < 0)
                cout << "(" << this->list.select(i-1) << ")" << "x^" << exp;
            else
                cout << this->list.select(i-1) << "x^" << exp;
            if (i != 1 && this->list.select(i-1)) {
                cout << " + ";
            }
        }
        exp--;

    }
    cout << endl;
}



