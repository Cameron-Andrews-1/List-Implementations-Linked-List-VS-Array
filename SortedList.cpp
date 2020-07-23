//SortedList.cpp
//implements base class for SortedArrayList and SortedLinkedList

#ifndef SORTED_LIST_CPP
#define SORTED_LIST_CPP

#include <string>

using namespace std;

class SortedList
{
public:
    virtual void insert(string word) = 0;
    virtual bool find(string word) = 0;
    virtual void remove(string word) = 0;
};

#endif

