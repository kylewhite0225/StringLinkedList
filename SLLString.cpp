#include <string>
#include "SLLString.h"
using namespace std;

/*
Name: SLLString.h
Author: Kyle White
Date: 11/6/2020
Description: The SLLString class implementation includes several methods:
constructor, destructor, two copy constructors acepting a string and an SLLString
object, overloaded assignment and concatenation constructors, overloaded bracket[]
operator, erase which erases all instances of a char, length, insertNode, and AppendTail. 
*/

// Default constructor sets the head and tail fields to NULL, and the size to 0.
SLLString::SLLString()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

// Destructor
SLLString::~SLLString()
{
    Node* current = head;
    while(current != 0) {
        Node* next = current->next;
        current = NULL;
        delete current;
        current = next;
    }
}

// Copy constructor accepting a string, which uses the AppendTail helper method
// to construct an SLLString object.
SLLString::SLLString(const string &other)
{
    for (char c : other)
    {
        AppendTail(c);
    }
}

// Copy constructor accepting another SLLString object
SLLString::SLLString(const SLLString &other)
{
    Node *curr = other.head;
    this->head = curr;
    curr = curr->next;
    while (curr != NULL) {
        Node *newNode = NULL;
        newNode = curr;
        curr = curr->next;
    }
    this->tail = other.tail;
    this->size = other.size;
}

// Assignment constructor
SLLString &SLLString::operator=(const SLLString &other)
{
    // If they are the same or other is null
    if (this == &other || other.head == NULL)
    {
        return *this;
    }
    Node *curr = other.head;
    this->head = curr;
    curr = curr->next;
    while (curr != NULL) {
        Node *newNode = NULL;
        newNode = curr;
        curr = curr->next;
    }
    this->tail = other.tail;
    this->size = other.size;
    return *this;
}

// Concatenation constructor which uses the AppendTail helper function.
SLLString &SLLString::operator+=(const SLLString &other)
{
    Node *currNode = other.head;
    while (currNode != NULL)
    {
        this->AppendTail(currNode->data);
        currNode = currNode->next;
    }
    return *this;
}

// Returns the length of the list stored in the size field.
int SLLString::length()
{
    return size;
}

// Overloads the [] operator and returns a reference to the character stored at index n
char& SLLString::operator[](const int n) {
    Node *curr = new Node;
    curr = this->head;
    if (n == 0) {
        return this->head->data;
    } else if (n > this->size) {
        throw out_of_range("Out of bounds.");
    }
    for (int i = 0; i < n; i++) {
        curr = curr-> next;
    }
    return curr->data;
}

// Returns the index of the start of the first occurence of a substring
int SLLString::findSubstring(const SLLString &substring)
{
    int index = 0;
    Node *first = substring.head;
    Node *second = this->head;
    if (first == NULL && second == NULL) {
        index = 0;
        return index;
    } else if (first == NULL || first != NULL && second == NULL) {
        index = -1;
        return index;
    }
    Node *p1 = first;
    Node *p2 = second;
    while (second != NULL) {
        p2 = second;
        while (p1 != NULL) {
            if (p2 == NULL) {
                index = -1;
                return index;
            } else if (p1->data == p2->data) {
                p1 = p1->next;
                p2 = p2->next;
            } else {
                break;
            }
        }
        if (p1 == NULL) {
            return index;
        }
        p1 = first;
        second = second->next;
        index++;
    }

    return index;
}

// Overloaded findSubstring function which creates a pointer to an SLLString
// object created from the input constant reference to the string substring.
int SLLString::findSubstring(const string &substring) 
{
    SLLString *s = new SLLString(substring);
    int index = findSubstring(*s);
    return index;
}

// Erases all instances of char c from the SLLString object
void SLLString::erase(char c)
{
    Node *curr = this->head;
    Node *prev = NULL;
    while (curr != NULL) {
        if (curr->data == c) {
            prev->next = curr->next;
            delete curr;
            curr = prev;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
}

// Helper function that appends a node to the tail of the linked list.
void SLLString::AppendTail(char c)
{
    // If the list is empty, insert a node at the beginning of the list.
    if (head == NULL)
    {
        Node *newNode = new Node;
        newNode->data = c;
        newNode->next = head;
        head = newNode;
        tail = newNode;
        size++;
    }
    else // Else, create a new node and set the contents to char c and add it to the end.
    {
        Node *newNode = new Node;
        newNode->data = c;
        tail->next = newNode;
        tail = newNode;
        size++;
    }
}