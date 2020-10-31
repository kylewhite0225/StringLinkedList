#ifndef NODE
#define NODE
#include <cstddef>
using namespace std;

/*
Name: Node.h
Author: Kyle White
Date: 11/6/2020
Description: The Node class provides the fields data which store a character,
and next which store a pointer to a Node object as the building blocks for a linked list.
*/

class Node
{
public:
    char data;
    Node *next = NULL;
    Node(char data) {
        this->data = data;
    }
    Node() {
        data;
        next = NULL;
    }
};
#endif