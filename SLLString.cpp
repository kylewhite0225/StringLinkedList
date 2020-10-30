#include <string>
#include "SLLString.h"
using namespace std;

SLLString::SLLString()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

SLLString::~SLLString()
{
    Node *current = head;
    while (current != NULL)
    {
        current = current->next;
        delete head;
        head = current;
    }
}

// // Deep copy function
// void SLLString::copySLLString(const SLLString &otherSLLString)
// {
//     Node *head = new Node;
//     Node *current = new Node;
//     if (otherSLLString.head == NULL)
//     {
//         return;
//     }
//     Node *temp = otherSLLString.head;
//     // head = new Node;
//     head->data = temp->data;
//     head->next = NULL;
//     current = head;

//     temp = temp->next;

//     while (temp != NULL)
//     {
//         current->next = new Node;
//         current = current->next;
//         current->data = temp->data;
//         current->next = NULL;
//         temp = temp->next;
//     }
// }

// copy constructor accepting a string
SLLString::SLLString(const string &other)
{
    for (char c : other)
    {
        AppendTail(c);
    }
}

// copy constructor accepting another SLLString object
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

// Concatenation constructor
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

// Returns the length of the list
int SLLString::length()
{
    return size;
}

// Returns a reference to the character stored at index n
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
    return 1;
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

Node *SLLString::InsertNode(int index, char c)
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