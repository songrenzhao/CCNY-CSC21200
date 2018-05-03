//Songren Zhao
//CSC212 Fall 2017
//Professor: Zhigang Zhu

/* Invariants
 * head_ptr is simply the first node pointer
 * tail pointer is the last node pointer
 * cursor is the current item, which is similar to current index in the previous assignment
 * precursor is the previous pointer, if cursor = head pointer, then precursor must be null
 * num is the number of elements in the lists, served as used in the previous assignment
 */

#include <cassert>
#include "sequence3.h"
using namespace std;

namespace main_savitch_5
{
    sequence::sequence()
    {
        //Using linked lists: O(1)
        //Using dynamic arrays: O(1)
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        num = 0;
    }

    sequence::sequence(const sequence& source)
    {
        //Using linked lists: O(n)
        //Using dynamic arrays: O(n)
        list_copy(source.head_ptr, head_ptr, tail_ptr); // Copies everything from source
        num = source.size(); //Simply make numbers of elements equal
        cursor = head_ptr; //Assume the cursor is the head pointer, then we can find where the current item is
        precursor = NULL; //Since cursor is head pointer, there is nothing before cursor
        node* travel = source.head_ptr;
        while(travel != NULL && travel != source.cursor) //Pointer will travel until it detects the current item
        {
            travel = travel ->link();
            precursor = cursor; //As pointer is traveling, the precursor and cursor also move until the current item is detected
            cursor = cursor ->link();
        }
    }
    sequence::~sequence()
    {
        //Using linked lists: O(n)
        //Using dynamic arrays: O(n)
        list_clear(head_ptr);
    }
    void sequence::start()
    {
        //Using linked lists: O(1)
        //Using dynamic arrays: O(1)
        cursor = head_ptr;
        precursor = NULL;
    }
    void sequence::advance()
    {
        //Using linked lists: O(1)
        //Using dynamic arrays: O(1)
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }
    void sequence::insert(const value_type& entry)
    {
        //Using linked lists: O(1) simply insert, not doing any loops and such
        //Using dynamic arrays: O(n) because it has to insert the enrty to the end if no current item
        if(!is_item())
        {
                list_head_insert(head_ptr, entry);
                precursor = NULL;
                cursor = head_ptr;
        }
        else
        {
            if(cursor == head_ptr) //Current item is on head point
            {
                list_head_insert(head_ptr,entry);
                cursor = head_ptr;
                precursor = NULL;
            }
            else //Current item is somewhere in the list
            {
                list_insert(precursor, entry);
                cursor = precursor->link();
            }
        }
        num++;
    }
    void sequence::attach(const value_type& entry)
    {
        //Using linked lists: O(1)
        //Using dynamic arrays: O(n) because it has to attach the enrty to the end if no current item
        if(is_item())
        {
            list_insert(cursor,entry);
            precursor = cursor;
            cursor = cursor->link();
        }
        else
        {
            if(precursor == NULL) //Attaching the first item
            {
                list_head_insert(head_ptr,entry);
                cursor = head_ptr;
                precursor = NULL;
            }
            else
            {
                cursor = list_locate(head_ptr, list_length(head_ptr)); //Since current item doesn't exist, we have to find the head pointer. the function is given in node1.h
                list_insert(cursor, entry);
                cursor = precursor->link();
            }
        }
        num++;
    }
    void sequence::remove_current()
    {
        //Using linked lists: O(1) I didn't use loops for this one
        //Using dynamic arrays: O(n) I used loop in the previous assignments
        assert(is_item());
        if(cursor == head_ptr)
        {
            list_head_remove(head_ptr);
            cursor = head_ptr;
            precursor = NULL;
        }
        else
        {
            cursor = cursor ->link();
            list_remove(precursor);
        }
        num--;
    }
    void sequence::operator=(const sequence& source)
    {
        //Using linked lists: O(n)
        //Using dynamic arrays: O(n)
        if(this == &source) //Self check
            return;
        list_clear(head_ptr);
        list_copy(source.head_ptr, head_ptr, tail_ptr); // Copies everything from source
        num = source.size(); //Simply make numbers of elements equal
        cursor = head_ptr; //Assume the cursor is the head pointer, then we can find where the current item is
        precursor = NULL; //Since cursor is head pointer, there is nothing before cursor
        node* travel = source.head_ptr;
        while(travel != NULL && travel != source.cursor) //Pointer will travel until it detects the current item
        {
            travel = travel ->link();
            precursor = cursor; //As pointer is traveling, the precursor and cursor also move until the current item is detected
            cursor = cursor ->link();
        }
    }

    size_t sequence::size() const
    {
        //Using linked lists: O(1)
        //Using dynamic arrays: O(1)
        return num;
    }
    bool sequence::is_item() const
    {
        //linked lists: O(1)
        //dynamic arrays: O(1)
        return cursor != NULL && size() > 0;
    }
    sequence::value_type sequence::current() const
    {
        //linked lists: O(1)
        //dynamic arrays: O(1)
        return cursor->data();
    }
}