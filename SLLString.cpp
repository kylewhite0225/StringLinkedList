#include <string>
#include "SLLString.h"
using namespace std;

SLLString::SLLString() {
    head = NULL;
    tail = NULL;
    size = 0;
}

SLLString::~SLLString() {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

// copy constructor accepting a string
SLLString::SLLString(const string& other) {

}

// copy constructor accepting another SLLString object
SLLString::SLLString(const SLLString& other) {

}

// Assignment constructor
SLLString& SLLString::operator=(const SLLString& other) {

}

// Concatenation constructor
SLLString& SLLString::operator+=(const SLLString& other) {
    Node *currNode = other.head;
    while (currNode != NULL)
    {
        this->AppendTail(currNode->data);
        currNode = currNode->next;
    }
    return *this;
}

// Returns the length of the list
int SLLString::length() {
    return size;
}

// Returns the character stored at index n
char& SLLString::operator[](const int n) {

}

// Returns the index of the start of the first occurence of a substring 
int SLLString::findSubstring(const SLLString& substring) {

}

// Erases all instances of char c from the SLLString object
void SLLString::erase(char c) {

}

Node* SLLString::InsertNode(int index, char c)
{
    if (index < 0)
        return NULL;

    int prevIndex = 0;
    Node *prevNode = head;
    while (prevNode != NULL && index - 1 > prevIndex)
    {
        prevNode = prevNode->next;
        prevIndex++;
    }
    if (index > 0 && prevNode == NULL)
        return NULL;

    Node *newNode = new Node;
    newNode->data = c;
    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    size++;
    if (index == size - 1)
    {
        tail = newNode;
    }
    return newNode;
}

void SLLString::AppendTail(char c)
{
    if (head == NULL)
    {
        InsertNode(0, c);
    }
    else
    {
        Node *newNode = new Node;
        newNode->data = c;
        tail->next = newNode;
        tail = newNode;
        size++;
    }
}