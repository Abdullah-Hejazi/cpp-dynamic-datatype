#include "dynamic.hpp"
#include "node.hpp"

#ifndef LIST_H
#define LIST_H

class List {
	private:
		Node* head;
        Node* tail;
        int count;

	public:
        List();
        ~List();

        void Print();

        void Push(bool);
        void Push(int);
        void Push(double);
        void Push(const char*);
        void Push(Dynamic);

        void Remove(int);
        void RemoveFirst();
        int Length();
        void ClearList();
        Dynamic* Get(int);
};

#endif