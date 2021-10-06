//created by zhouNing 2021.10.6
//c++ 11
#pragma once
#include <iostream>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define INFEASIBLE -1
#define OVERFLOW -2
#define DEBUG
template <class T>
class List
{
public:
//Get length
    int Length() { return length; }
//    int Size() { return size; }

    List();

//It doesn't do anything
    int init();

//Put an item to the end of the List
    int push_back(T t);

    int insert(int ind, T t);

    int locate(T t, int (*p)(T t1, T t2));

    int deleteItem(int ind);

    int get(int ind, T &t);

    int set(int ind, T t);

    #ifdef DEBUG
    List* Head(){return head;}
    List* Next(){return next;}
    void itemSet(T t){item = t;}
    T itemGet(){return item;}
    #endif
    void listPrint(void (*p)(T t));

private:
    List<T> *next = nullptr;
    List<T> *head;
    T item;
    int length = 0;
//    The following variables were for SeqList
//    int initState;
//    int size;
//    int size_of_element;
//int realloc_list();
};

template<typename T>List<T>::List()
{
    head = this;
}

template<typename T>int List<T>::init()
{
    //Some problem maybe
    //return (head==nullptr) ? 0 : 1;
    //maybe this one don't need this fun??
    return 1;
}

template<typename T>int List<T>::push_back(T t)
{
    int status_code = OK;
    List<T> *tmp = this;
    while(true)
    {
        if(tmp->next == nullptr)
            break;
        else
            tmp = tmp->next;
    }
    tmp->next = new(std::nothrow) List();
    if (tmp->next == nullptr)
        return ERROR;
    tmp->next->head = tmp->head;//The head node always points to the first node
    tmp = tmp->next;
    tmp->item = t;
    length +=1;
    return status_code;
}

template<typename T>int List<T>::locate(T t, int (*p)(T t1, T t2))
{
    int location = -1;
    List<T> *L = head;
    while(true)
    {
        location += 1;
        L = L->next;
        if (L == nullptr)
            return ERROR;
        if (p(t,L->item) == 1)
            break;
    }
    return location;
}


//To be done
template<typename T>void List<T>::listPrint(void (*p)(T t))
{
    List<T> *L = head;
    while (true)
    {
         L = L->next;
        if (L == nullptr)
            return;
        p(L->item);
    }
}

template<typename T>int List<T>::set(int ind,T t)
{
    if (ind < 0 || ind >= length)
        return ERROR;
    List<T> *L = next; 
    for (int i = 0; i < ind; i++)
        L = L->next;
    L->item = t;
    return OK;
}

template<typename T>int List<T>::get(int ind, T &t)
{
    if (ind < 0 || ind >= length)
        return ERROR;
    List<T> *L = next;
    for (int i = 0; i < ind; i++)
        L = L->next;
    t = L->item;
    return OK;
}

template<typename T>int List<T>::deleteItem(int ind)
{
    List<T> *tmp;
    List<T> *L = head;
    if (ind < 0 || ind >= length)
        return ERROR;
    if (ind == 0)
    {
        tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        return OK;
    }
    for (int i = 0; i < ind ; i++)
        L = L->next;
    tmp = L->next;
    L->next = tmp->next;
    delete tmp;
    return OK;
}

template<typename T>int List<T>::insert(int ind,T t)
{
    if (ind < 0 || ind >= length)
        return ERROR;
    List<T> *L = next;
    List<T> *node = new(std::nothrow) List();
    if (node == nullptr)return ERROR;
    node->item = t;
    node->head = head;
    if (ind == 0)
    {
        next = node;
        node->next = L;
        return OK;    
    }
    
    for (int i = 0; i < ind - 1; i++)
        L = L->next;
    node->next = L->next;
    L->next = node;
    return OK;
}