//main.cpp

#include "SortedList.cpp"
#include "SortedArrayList.cpp"
#include "SortedLinkedList.cpp"
#include <iostream>
#include <fstream>
#include "timer.h"

using namespace std;

//used for inserting all words from file into SortedList data structure
void insert_all_words(string file_name, SortedList& L)
{
    Timer timer;
    double time;
    timer.start();
    ifstream in;
    in.open(file_name);
    string word;
    while (in >> word)
    {
        L.insert(word);
    }
    in.close();
    timer.elapsedUserTime(time);
    cout << time << endl;
}

//used for finding all words from file into SortedList data structure
void find_all_words(string file_name, SortedList& L)
{
    Timer timer;
    double time;
    timer.start();
    ifstream in;
    in.open(file_name);
    string word;
    while (in >> word)
    {
       L.find(word);
    }
    in.close();
    timer.elapsedUserTime(time);
    cout << time << endl;
}

//used for removing all words from a file into SortedList data structure
void remove_all_words(string file_name, SortedList& L)
{
    Timer timer;
    double time;
    timer.start();
    ifstream in;
    in.open(file_name);
    string word;
    while (in >> word)
    {
        L.remove(word);
    }
    in.close();
    timer.elapsedUserTime(time);
    cout << time << endl;
}

int main()
{
    string file_name = "random.txt";
    SortedArrayList array;
    SortedLinkedList linkedList;
    
    cout << "Testing SortedArrayList" << endl;
    insert_all_words(file_name, array);
    find_all_words(file_name, array);
    remove_all_words(file_name, array);

    cout << "Testing SortedLinkedList" << endl;
    insert_all_words(file_name, linkedList);
    find_all_words(file_name, linkedList);
    remove_all_words(file_name, linkedList);

    return 0;
}
