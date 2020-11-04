#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

/*
Name: SLLString.h
Author: Kyle White
Date: 11/6/2020
Description: Header file for the SLLString class, which defines
the private members and prototypes of all methods. The SLLString class is a singly-linked
list maintaining a head and tail pointer, as well as an integer storing the size of the list.'
SLLString objects store strings as singly linked lists.
*/

class SLLString
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;
public:
    // Default constructor
    SLLString();
    // Copy constructor accepting a string as a parameter
    SLLString(const string& other);
    // Destructor
    ~SLLString();
    // Copy constructor accepting an SLLString object as a parameter
    SLLString(const SLLString &other);
    // Assignment constructor
    SLLString& operator=(const SLLString& other);
    // Overloaded concatenation operator
    SLLString& operator+=(const SLLString& other);
    // Length function which returns the length (size) of the SLLString object
    int length();   
    // Returns the character stored in the list at index n
    char& operator[](const int n);
    // Finds the index of the first occurence of substring, returns -1 if not found.
    int findSubstring(const SLLString& substring);
    // Helper function for findSubstring which accepts a string and creates an SLLString object.
    int findSubstring(const string & substring);
    // Erases all occurrences of character c from an SLLString object..
    void erase(char c);
    // Assigning the << operator as a friend allows iostream to print SLLString objects.
    friend ostream& operator<<(ostream& out, const SLLString & s) {
        for(Node* n = s.head; n != NULL; n = n->next) {
            out << n->data;
        }
        return out;
    }
    // AppendTail is a helper function that appends a new node to the end of the linked list.
    void AppendTail(char c);
};