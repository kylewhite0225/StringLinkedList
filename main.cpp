#include <iostream>
#include "SLLString.h"

using namespace std;

int main(){
    SLLString str("Hello world!");
    cout << str << endl;
    SLLString newStr; // = new SLLString;
    // SLLString newStr2(str);
    // cout << newStr2 << endl;

    newStr = str;
    // out << newStr << endl;
    newStr += SLLString(" CS@BC");
    newStr[6] = 'W';
    
    cout << newStr << endl; // Hello World! CS@BC
    cout << newStr.length() << endl; //18
    
    // int loc = newStr.findSubstring("World");
    // cout << loc << endl; // 6
    
    newStr.erase('l'); //erase the letter l.
    cout << newStr << endl; // Heo Word! CS@BC
    
    newStr.erase('C');
    cout << newStr << endl; // Heo Word! S@B
    
    return 0;
}