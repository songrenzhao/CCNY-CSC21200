Computer Science City College of New York 
  CSc21200 Data Structures Fall 2017
Programming Assignment 5  (Chapter 9) - Recursive Thinking
Adapted from Data Structures and Other Objects Using C++ 
by Michael Main and Walter Savitch
The Assignment:
You will implement and test four short recursive functions. With the proper use of recursion, none of these function should require more than a dozen lines of code.
Purposes:
Ensure that you can write and test small recursive functions.
Before Starting:
Read all of Chapter 9, especially Sections 9.1 and 9.3.
Due Date:
Wednesday, November 08, 2017. If you have problems, late work will be accepted on Tursday with no penalties. Late work may be submitted on Friday or Saturday with 5% penalty per day. No work will be accepted after Saturday.
How to Turn In:
Files to be submitted: source code (*.cpp, *.cxx, *.h, see below for details). Please don't send your excutable files. Please submit your files to ds.zhu.ccny@gmail.com, with the subject line "CSc212 Assignment 5".
Files that you must write and turn in:
rec_fun.cxx: This file should contain the implementations of the four functions described below. You might also want to put the functions prototypes in a separate file rec_fun.h and write a test program that includes rec_fun.h.
1. One Binary Number
Write a function with this prototype:
  void binary_print(ostream& outs, unsigned int n);
The function prints the value of n as a BINARY number to the ostream outs. If n is zero, then a single zero is printed; otherwise no leading zeros are printed in the output. The '\n' character is NOT printed at the end of the output. 
EXAMPLES:
  n=0  Output:0
  n=4  Output:100
  n=27 Output:11011
NOTE: Your recursive implementation must not use any local variables. 
 
2. Triangle Pattern
  void triangle(ostream& outs, unsigned int m, unsigned int n)
  // Precondition: m <= n
  // Postcondition: The function has printed a pattern of 2*(n-m+1) lines
  // to the output stream outs. The first line contains m asterisks, the next 
  // line contains m+1 asterisks, and so on up to a line with n asterisks.
  // Then the pattern is repeated backwards, going n back down to m.
  /* Example output:
     triangle(cout, 3, 5) will print this to cout:
     ***
     ****
     *****
     *****
     ****
     ***
  */
Hint: Only one of the arguments changes in the recursive call. Which one? 
 
3. Pow Function (Project 13, page 452)
Rewrite the recursive pow function from Fig. 9.10 on page 445, so that the time to compute pow(x,n) is log(n):
    double pow(double x, int n); 
    // Precondition: If x is zero, then n must be positive. 
    // Postcondition: The value returned is x raised to the power n.

Hint: use the formula x^2n = x^n  x^n

4.  Repeated and Indented Sentences (Project 1, page 450)

Write a  function that produces output like the following:

This was written by calling number 1. 
  This was written by calling number 2. 
    This was written by calling number 3. 
      This was written by calling number 4. 
      This was ALSO written by calling number 4. 
    This was ALSO written by calling number 3. 
  This was ALSO written by calling number 2. 
This was ALSO written by calling number 1.

In the above example, the recursion stopped when it reached four levels deep, but your function should be capable of continuing any specific level with the following function prototype.

     void indented_sentences(size_t m, size_t n); 
// precondition: m <=n; 
//postcondition: print out the above pattern by calling number from m to n

Zhigang Zhu ( ds.zhu.ccny@gmail.com ), 2017
