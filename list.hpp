#include "dynamic.hpp"

#ifndef LIST_H
#define LIST_H

// Linked list implementation for the dynamic datatype

class List {
	private:
		Dynamic * value;
		List* next;

	public:
		List();
        ~List();

        void Print();

        void Add(int);
        void Add(double);
        void Add(bool);
        void Add(const char*);
        void Add(Dynamic);

        void Remove(int);
        List* GetLastNode();
        int Length();
        void ClearList();
        Dynamic* Get(int);
};

#endif