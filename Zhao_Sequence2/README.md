Computer Science City College of New York 
  CSc21200 Data Structures, Fall 2017
Programming Assignment 3:  Revise the sequence Class to Use a Dynamic Array (Chapter 4)
Modified from projects of Chapter  4  at www.cs.colorado.edu/~main/projects/ 
of Data Structures and Other Objects Using C++  by Michael Main and Walter Savitch
The Assignment:
You will implement and test a revised sequence class that uses a dynamic array to store the items.
Purposes:
Ensure that you can write a small class that uses a dynamic array as a private member variable.
Before Starting:
Read all of Chapter 4 (textbook or slides).
Due Date:
Wednesday, Oct 11, 2017. If you have problems, late work will be accepted on Friday with no penalties. Late work may be submitted on Saturday or Sunday with 5% penalty per day. No work will be accepted after Sunday.
How to Turn In:
Files to be submitted: source code (*.cpp, *.cxx, *.h, see below for details)  and the text file (a *.txt file or *.pdf file) showing the running output results using seq_ex2.cxx. Please don't send your excutable files. Please submit your files to ds.zhu.ccny@gmail.com, with the subject line "CSc212 Assignment 3".
Programming files that you must write and turn in:
sequence2.h: The header file for the new sequence class. Actually, you don't have to write much of this file. Just start with our version and add your name and other information at the top. If some of your member functions are implemented as inline functions, then you may put those implementations in this file too. By the way, you might want to compare this header file with your first sequence header file (sequence1.h) . The new version no longer has a CAPACITY constant because the items are stored in a dynamic array that grows as needed. But there is a DEFAULT_CAPACITY constant, which provides the initial size of the array for a sequence created by the default constructor.
sequence2.cxx: The implementation file for the new sequence class. You will write all of this file, which will have the implementations of all the sequence's member functions.
Other files that you may find helpful (but you do not need to turn in):
sequence_test.cxx: This is in fact the same interactive test program that you used with the earlier sequence. If you want to use it with the new sequence, then copy it to your directory and open it with your editor. Then change the statement

#include "sequence1.h" 
to 
#include "sequence2.h"
And change the statement 
using namespace main_savitch_3 
to 
using namespace main_savitch_4

seq_ex2.cxx: A non-interactive test program that will be used to grade the correctness of your new sequence class. If you use MinGW, please use seq_ex2_MinGW.cxx
The sequence Class Using a Dynamic Array
Discussion of the Assignment
Your sequence class for this assignment will differ from the your previous sequence in the following ways:
The number of items which may be stored in the sequence should only be limited by the amount of memory available on the heap. When new items are added to a sequence which is at capacity, the size of the data array in which items are stored should be automatically enlarged.
Because you are dynamically allocation memory within your sequence class, you will need to define a copy constructor, an assignment operator, and a destructor.
The constructor should have a default argument which allows the user to set the initial capacity of the sequence.
There should be a resize function that allows the user to explicitly set the the capacity of the sequence.
Start by declaring the new sequence's private member variables in sequence2.h. This should include the dynamic array (which is declared as a pointer to a value_type). You will also need two size_type variables to keep track of the number of items in the sequence and the total size of the dynamic array. After you've declared your member variables, write an invariant for the top of sequence2.cxx.
Many of the features of this class are similar to the bag class from Section 4.3, so start by thoroughly reading Section 4.3 and pay attention to new features such as how the sequence differs from a bag (see page 119). Also the implementation of some of the functions are almost the same as in Part 1. Once again, do your work in small pieces. For example, my first version of the sequence had only a constructor, start, insert, advance, and current. My other member functions started out as stubs.

Use the interactive test program and the debugger to track down errors in your implementation. If you have an error, do not start making changes until you have identified the cause of the error.

The ability to initialize and use a static member constant within the class definition is a relatively new feature. If you have an older compiler (for example, Visual C++ 6.0) that does not support static const members, then you may use

enum {DEFAULT_CAPACITY = 30};

instead of

static const size_type DEFAULT_CAPACITY = 30;

After  this definition, the name bag::DEFAULT_CAPACITY is defined to have the integer value 30. Although this is not the intended use of an enum definition, the result is the same as using a static member constant (see more discussions at page 99 in the textbook).

When a member functions needs to increase the size of the dynamic array, it is a good idea to increase that size by at least 10% (rather than by just one item). 
 

The sequence Class Using a Dynamic Array
*Optional Part of the Assignment (for extra 10% points )
You may wish to provide some additional useful member functions, such as 
(1) Operators + and +=.. For + operator, x+y contains all the items of x, followed by all the items in y. The statement x += y appends all the items in y to the end of what's already in x. 
(2) Operator []. For a sequence x, we would like to be able to refer to the individual items using the usual C++ notation for arrays. For example, if x has three items, then we want to be able to write x[0], x[1] and x[2] to access these three items. The use of the square brackets is called the subscript operator. The subscript operator may be overloaded as a member function, with the prototype shown here as part of the sequence class:
class sequence 
{ 
public: 
    ... 
    value_type operator[](size_type index) const; 
    ... 
};

The only parameter is the index of the item we want to retrieve. The implementation of this member function should check that the index is valid, and then return the specified item. 
Zhigang Zhu ( ds.zhu.ccny@gmail.com ), 2017
