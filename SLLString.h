#include <iostream>
#include <string>
using namespace std;

/*
Name: SLLString.h
Author: Kyle White
Date: 11/6/2020
Description: Header file for the SLLString class, which defines
the private members and all methods.
*/
struct Node {
    char data;
    Node *next;
};

class SLLString
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;
public:
    SLLString();    // Default Constructor
    SLLString(const string& other);     // Copy constructor taking a string as parameter
    ~SLLString();   // Destructor
    SLLString(const SLLString& other);  // Copy constructor taking another SLLString
    SLLString& operator=(const SLLString& other);   // Assignment constructor
    SLLString& operator+=(const SLLString& other);  // Concatenation constructor
    int length();   // Return length of the SLLString
    char& operator[](const int n);  // Return character at index n
    int findSubstring(const SLLString& substring);  // Find the index of the first
    // occurrence of substring in the current string. Returns -1 if not found.
    void erase(char c); // Erase all occurrences of character c from the current string.
    // support cout << operator
    friend ostream& operator<<(ostream& out, const SLLString & s) {
        for(Node* n = s.head; n != NULL; n = n->next) {
            out << n->data;
        }
        return out;
    }
    Node* InsertNode(int index, char c);
    void AppendTail(char c);
};