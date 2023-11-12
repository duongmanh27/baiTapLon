#include <bits/stdc++.h>
#include "node_dual.cpp"
#include "slist_iterator_dual.cpp"
#ifndef __slist_dual_cpp__
#define __slist_dual_cpp__
using namespace std;

template <class T>

class slist
{
private:
    node<T> *pre, *head, *tail;
    unsigned int num;

public:
    typedef slist_iterator<T> iterator;
    slist()
    {
        pre = head = tail = nullptr;
        num = 0;
    }
    slist(int k, T x)
    {
        pre = head = tail = NULL;
        num = 0;
        for (int i = 0; i < k; i++)
        {
            push_back(x);
        }
    }
    unsigned size()
    {
        return num;
    }
    bool empty()
    {
        return num == 0;
    }
    iterator begin()
    {
        return head;
    }
    iterator end()
    {
        return NULL;
    }
    iterator rbegin()
    {
        return tail;
    }
    iterator rend()
    {
        return NULL;
    }

    T &front()
    {
        return head->getData();
    }

    T &back()
    {
        return tail->getData();
    }

    void push_front(T x)
    {
        node<T> *tmp = new node<T>(x, NULL);
        if (num == 0)
        {
            tail = head = tmp;
        }
        else
        {
            tmp->setNext(head);
            head->setPre(tmp);
            head = tmp;
        }
        num++;
    }

    void push_back(T x)
    {
        node<T> *tmp = new node<T>(x, NULL, NULL);
        if (num == 0)
        {
            push_front(x);
        }
        else
        {
            tmp->setPre(tail);
            tail->setNext(tmp);
            tail = tmp;
            num++;
        }
    }

    void pop_front()
    {
        if (num == 0)
        {
            return;
        }
        if (num == 1)
        {
            head = pre = tail = NULL;
        }
        else
        {
            head = head->getNext();
        }
        num--;
    }

    void pop_back()
    {
        if (num == 0)
        {
            return;
        }
        if (num == 1)
        {
            head = pre = tail = NULL;
        }
        else
        {
            node<T> *tmp = head;
            while (tmp->getNext() != NULL)
            {
                tmp = tmp->getNext();
            }
            tmp->setNext(NULL);
            tail = tmp;
        }
    }

    void insert(T x, int k)
    {
        if (k < 0 || k > size() + 1)
        {
            cout << "Vi tri chen khong hop le.\n";
        }
        if (k == size() + 1)
        {
            return;
        }
        if (k == 1)
        {
            return;
        }
        else
        {
            node<T> *fisrt = NULL, *last = head;
            for (int i = 0; i < k; i++)
            {
                fisrt = last;
                last = last->getNext();
            }
            fisrt->setNext(new node<T>(x, fisrt, last));
            last->setPre(fisrt->getNext());
            num++;
        }
    }

    void erase(int k)
    {
        if (k <= 0 || k > size())
        {
            return;
        }
        else
        {
            node<T> *fisrt = NULL, *last = head;
            for (int i = 0; i < k - 1; i++)
            {
                fisrt = last;
                last = last->getNext();
            }
            fisrt->setNext(last->getNext());
            last->getNext()->setPre(fisrt);
            num--;
        }
    }

    // ham them
    void eraseDataSame()
    {
        if (head == NULL)
        {
            return;
        }
        node<T> *tmp = head;

        node<T> *fisrt = NULL, *last = NULL;
        while (tmp != NULL)
        {
            fisrt = tmp;
            last = tmp->getNext();
            while (last != NULL)
            {
                if (tmp->getData() == last->getData())
                {
                    if (last->getNext() == NULL)
                    {
                        fisrt->setNext(NULL);
                        num--;
                    }
                    else
                    {
                        fisrt->setNext(last->getNext());
                        last->getNext()->setPre(fisrt);
                        num--;
                    }
                }
                else
                {
                    fisrt = last;
                }
                last = last->getNext();
            }
            tmp = tmp->getNext();
        }
    }

    void sortList()
    {
        for (node<T> *p1 = head; p1->getNext() != NULL; p1 = p1->getNext())
        {
            node<T> *q1 = p1;
            for (node<T> *q2 = p1->getNext(); q2 != NULL; q2 = q2->getNext())
            {

                if (q1->getData() > q2->getData())
                {
                    q1 = q2;
                }
            }
            T x = p1->getData();

            p1->setData(q1->getData());
            q1->setData(x);
        }
    }

    void insertAndSort(T x, int k)
    {
        insert(x, k);
        sortList();
    }
    void setNewData()
    {
        for (node<T> *tmp = head; tmp != NULL; tmp = tmp->getNext())
        {
         tmp->setData((tmp->getData() * tmp->getData() - 7 * tmp->getData() + 3) % 100);
        
        }
    }
};
#endif