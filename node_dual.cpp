#include <bits/stdc++.h>
#ifndef __node_dual__cpp__
#define __node_dual__cpp__
using namespace std;

template <class T>
class node
{
private:
    T data;
    node *next, *pre;
    
public:
    node()
    {
    }
    node(T x, node<T> *p = NULL, node<T> *n = NULL)
    {
        data = x;
        pre = p;
        next = n;
    }
    node<T> *&getNext()
    {
        return next;
    }
    node<T> *&getPre()
    {
        return pre;
    }
    T &getData()
    {
        return data;
    }
    void setData(T x)
    {
        this->data = x;
    }
    void setNext(node<T> *n = NULL)
    {
        next = n;
    }
    void setPre(node<T> *p = NULL)
    {
        pre = p;
    }
};

#endif
// int main()
// {
//     node<int> A(4), C(2);
//     node<int> B(3,&C,&A) ;
//     node<int> *D = new node<int>(1, NULL, &C);
//     D->setNext(&C) ;
//     C.setNext(&B);
//     C.setPre(&*D);
//     cout << A.getData() << "\n";
//     cout << B.getData() << "\n";
//     cout << C.getData() << "\n";
//     cout << D->getData() << "\n";
//     cout << B.getPre()->getData()<<"\n" ;
//     for (node<int> *it = D; it != NULL; it = it->getNext())
//         cout << it->getData() << "\t";
//     return 0;
// }