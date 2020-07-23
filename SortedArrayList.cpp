//SortedArrayList.cpp
//implements SortedArrayList using base class SortedList

#include "SortedList.cpp"
#include <string>
#include <iostream>

using namespace std;

class SortedArrayList: public SortedList
{
    string* buf;
    int capacity;
    int size;

public:
    SortedArrayList(int max_len = 45500)
        :buf(new string[max_len]), capacity(max_len), size(0) {}

    void insert(string word) override
    {
        if (size < capacity) //1
        {
            int index = binary_search(word, 0, size); //
            copy_down(index);
            buf[index] = word;
        }
        else
        {
            cout << "MAX CAPACITY REACHED" << endl;
        }
    }

    bool find(string word) override
    {
        return buf[binary_search(word, 0, size)] == word;
    }

    void remove(string word) override
    {
        copy_up(binary_search(word, 0, size));
    }
    
    ~SortedArrayList()
    {   
        delete[] buf;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    
    bool isFull()
    {
        return size != 0;        
    }

private:
    //returns which index the key should reside in lexicographically
    int binary_search(string key, int min, int max)
    {
        int mid; //1
        while (min <= max) //1
        {
            mid = min + (max - min)/2;
            if (key < buf[mid])
            {
                max = mid - 1;
            }
            else if (key > buf[mid])
            {
                min = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return mid;
    } 

    //used for insert: makes room in array at hole index
    void copy_down(int hole)
    {
        for (int i = size; i > hole; --i)
        {
            buf[i] = buf[i-1];
        }
        ++size;
    }

    //used for remove: shifts everything down at hole index
    void copy_up(int hole)
    {
        for (int i = hole; i < size - 1; ++i)
        {
            buf[i] = buf[i + 1];
        }
        --size;
    }
};
