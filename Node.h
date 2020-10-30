#ifndef NODE
#define NODE
#include <cstddef>
using namespace std;

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