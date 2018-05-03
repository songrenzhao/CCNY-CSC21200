//Songren Zhao
//CSC 212 Fall 2017
//Professor: Zhigang Zhu

#include <iostream>
#include "rec_fun.h"
using namespace std;

int main()
{
    cout << "n = 0\t";          //First function
    binary_print(cout, 0);
    cout << endl;
    cout << "n = 4\t";
    binary_print(cout, 4);
    cout << endl;
    cout << "n = 27\t";
    binary_print(cout, 27);
    cout << endl;

    cout << endl;
    triangle(cout, 3, 5);       //Second function

    cout << endl;
    cout << "100^0 is " << pow(100, 0) << endl;     //Third function
    cout << "2^-3 is " << pow(2, -3) << endl;
    cout << "3^-1 is " << pow(3, -1) << endl;
    cout << "4^-2 is " << pow(4, -2) << endl;
    cout << "5^5 is " << pow(5, 5) << endl;

    cout << endl;
    indented_sentences(1, 6);    //Fourth function
    return 0;
}
