//
// Created by Songren Zhao on 10/8/2017.
// Professor: Zhigang Zhu

#include <algorithm>
#include "sequence2.h"
#include <cassert>

using namespace std;
namespace main_savitch_4
{
    sequence::sequence(sequence::size_type initial_capacity) //Constructor
    {
        array_ptr = new sequence::value_type[initial_capacity];
        capacity = initial_capacity;
        currentIdx = 0;
        used = 0;
    }
    sequence::sequence(const sequence &source) //Copy Constructor
    {
        if (this == &source)
            return; //Self Statement Checked
        delete [] array_ptr;
        array_ptr = new sequence::value_type[source.capacity];
        capacity = source.capacity;
        currentIdx = source.currentIdx;
        used = source.used;
        copy(source.array_ptr, source.array_ptr + source.used, array_ptr);
    }
    sequence::~sequence() //Destructor
    {
        delete [] array_ptr;
    }
    void sequence::start()
    {
        currentIdx = 0;
    }
    void sequence::advance()
    {
        /*assert(is_item());        1
        if(currentIdx < size())                     For some reasons 1&&2 won't let me compile
            currentIdx++;*/
        /*assert(is_item() && currentIdx < size())      2
            currentIdx++;*/

        if(is_item() && (currentIdx < size()))
            currentIdx++;
    }
    void sequence::insert(const value_type &entry)
    {
        if (capacity <= used) // Augment the size of capacity to ensure program doesn't crash
            resize(size()*1.1);

        if (!is_item())
        {
            if (used == 0) //When no items on array
                array_ptr[0] = entry;
            else
            {
                currentIdx = 0; //No current item, we will assign it to the front
                for (sequence::size_type i = used; i > 0; i--)
                    array_ptr[i] = array_ptr[i - 1];
                currentIdx++;
                array_ptr[0] = entry;
            }
            used++;
        }
        else
        {
            for (sequence::size_type i = used; i > currentIdx; i--) // Current exists
                array_ptr[i] = array_ptr[i - 1];
            array_ptr[currentIdx] = entry;
            used++;
        }
    }
    void sequence::attach(const value_type &entry)
    {
        if (capacity <= size())
            resize(size()+1);

        if (!is_item())
            array_ptr[currentIdx] = entry;
        else
        {
            for(sequence::size_type i = used; i > currentIdx; i--)
                array_ptr[i] = array_ptr[i-1];
            array_ptr[++currentIdx] = entry;
        }
        used++;
    }
    void sequence::remove_current()
    {
        assert(is_item());
        for(sequence::size_type i = currentIdx; i < size(); i++)
            array_ptr[i] = array_ptr[i+1];
        used--;
    }
    void sequence::resize(size_type new_capacity)
    {
        if(new_capacity > capacity) //Precondition
        {
            capacity = new_capacity;
            sequence::value_type* data = new sequence::value_type[capacity];
            copy(array_ptr, array_ptr + used, data);
            delete [] array_ptr;
            array_ptr = data;
        }
    }
    void sequence::operator=(const sequence &source)
    {
        if(this == &source)
            return;
        delete [] array_ptr;
        array_ptr = new sequence::value_type[source.capacity];
        currentIdx = source.currentIdx;
        used = source.used;
        copy(source.array_ptr, source.array_ptr + used, array_ptr);
    }
    sequence::size_type sequence::size() const
    {
        return used;
    }
    bool sequence::is_item() const
    {
        return currentIdx < used;
    }
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return array_ptr[currentIdx];
    }
}


