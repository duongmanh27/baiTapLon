#include <bits/stdc++.h>
#include "node_dual.cpp"
#ifndef __slist_iterator_dual__cpp__
#define __slist_iterator_dual__cpp__
using namespace std;

template <class T>

class slist_iterator
{
private:
    node<T> *curr;

public:
    slist_iterator()
    {
        curr = NULL;
    }
    slist_iterator(node<T> *p)
    {
        curr = p;
    }
    node<T> *getCurr()
    {
        return curr;
    }
    slist_iterator<T> &operator=(slist_iterator<T> p)
    {
        this->curr = p.getCurr();
        return *this;
    }
    bool operator!=(slist_iterator<T> p)
    {
        return this->curr != p.getCurr();
    }
    slist_iterator<T> operator++()
    {
        curr = curr->getNext();
        return curr;
    }
    slist_iterator<T> operator++(int)
    {
        node<T> *tmp = curr;
        curr = curr->getNext();
        return tmp;
    }
    slist_iterator<T> operator--()
    {
        curr = curr->getPre();
        return curr;
    }
    slist_iterator<T> operator--(int)
    {
        node<T> *tmp = curr;
        curr = curr->getPre();
        return tmp;
    }
    T &operator*()
    {
        return curr->getData();
    }
};
#endif
