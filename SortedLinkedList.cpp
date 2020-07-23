//SortedLinkedList.cpp
//implements SortedLinkedList using base class SortedList

#include "SortedList.cpp"
#include <string>
#include <iostream>

using namespace std;

class SortedLinkedList: public SortedList
{
   struct ListNode
   {
        string info;
        ListNode* next;
        ListNode(string new_info, ListNode* new_next)
                :info(new_info), next(new_next) {}
   };
   ListNode* head;

public:
    SortedLinkedList()
            :head(nullptr) {}

    void insert(string word) override
    {
        ListNode* curr; //1
        //3
        if (head == nullptr or head->info >= word) //edge case: head is nullptr or new node should come before head
        {
            ListNode* new_node = new ListNode(word, head);
            head = new_node;
        }
        else //new node to be put in middle or end
        {
            curr = head;
            while (curr->next != nullptr and curr->next->info < word) //iterates through and stops once valid position found
            {
                    curr = curr->next;
            }
            ListNode* new_node = new ListNode(word, curr->next);
            curr->next = new_node;
            
        }
    }

    bool find(string word) override
    {
        ListNode* curr = head;
        while (curr != nullptr and curr->info <= word)
        {
            if (curr->info == word)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void remove(string word) override
    {
        if (head->next == nullptr or this->find(word) != 1)
        {
            return;
        }
        ListNode* curr = head;
        ListNode* prev;
        if (curr->info == word) //edge case
        {
            head = curr->next;
            delete curr;
        }
        else //node located in middle or end
        {
            while (curr->next != nullptr and curr->info <= word) //iterates through and stops once we know the value isn't there
            {
                if (curr->info == word)
                {
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
            if (curr->info == word)
            {
                prev->next = nullptr;
            }
            delete curr;
        }
    }

    bool isFull()
    {
        return false;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    ~SortedLinkedList()
    {
        ListNode* current = head;
        ListNode* next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }


};
