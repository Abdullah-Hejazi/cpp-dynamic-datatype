#include "dynamic.hpp"

#ifndef NODE_H
#define NODE_H

class Node {
    private:
        Dynamic* value;

    public:
        Node* next;

        Node(bool);
        Node(int);
        Node(double);
        Node(const char*);
        Node(Dynamic);

        ~Node();

        Dynamic* Get();
};

#endif