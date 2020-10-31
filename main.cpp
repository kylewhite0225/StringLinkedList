#include <iostream>
#include "SLLString.h"

using namespace std;

/*
Name: main.cpp
Author: Kyle White
Date: 11/6/2020
Description: The provided main.cpp function which tests the SLLString and Node classes.
*/

int main()
{
    SLLString str("Hello world!");
    cout << str << endl;
    SLLString newStr; // = new SLLString;

    newStr = str;
    newStr += SLLString(" CS@BC");
    newStr[6] = 'W';

    cout << newStr << endl;          // Hello World! CS@BC
    cout << newStr.length() << endl; //18

    int loc = newStr.findSubstring("World");
    cout << loc << endl; // 6

    newStr.erase('l');      //erase the letter l.
    cout << newStr << endl; // Heo Word! CS@BC

    newStr.erase('C');
    cout << newStr << endl; // Heo Word! S@B
    return 0;
}
