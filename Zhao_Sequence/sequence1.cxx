#include <cassert>
#include "sequence1.h"
#include <cstdlib>
#include <iostream>
// Songren Zhao
// CSC 212 Fall 2017
// Professor Zhu
using namespace std;

namespace main_savitch_3
{
    sequence::sequence()
    {
        used = 0;
        current_index = 0;
    }
    void sequence::start()
    {
        current_index = 0;
    }
    void sequence::advance()
    {
        //assert(is_item());
        if(current_index < used && is_item())
            current_index++;
    }
    void sequence::insert(const value_type& entry)
    {
        assert(size() < CAPACITY);
        if(!is_item())
        {
            if(used == 0)
            {
                data[0] = entry;
                used++;
            }
            else
            {
                current_index = 0;
                for(int i = used; i > current_index; i--)
                    data[i] = data[i-1];
                current_index++;
                data[0] = entry;
                used++;
            }
        }
        else
        {
            for(int i = used; i > current_index; i--)
            {
                data[i] = data[i-1];
            }
            data[current_index] = entry;
            used++;
        }
    }
    void sequence::attach(const value_type& entry)
    {
        assert (size()< CAPACITY);
        if (!is_item())
        {
            data[current_index]= entry;
            used++;
        }
        else
        {
            for (sequence::size_type i= used; i> current_index; i--)
            {
                data[i]= data[i-1];
            }
            current_index++;
            data[current_index]= entry;
            used++;
        }
    }
    void sequence::remove_current()
    {
        assert(is_item());
        for(sequence::size_type i = current_index; i < used; i++)
            data[i] = data[i+1];
        used--;
    }
    sequence::size_type sequence::size() const
    {
        return used;
    }
    bool sequence::is_item() const
    {
        return current_index < used;
    }
    sequence::value_type sequence::current( ) const
    {
        assert(is_item());
        return data[current_index];
    }
}

