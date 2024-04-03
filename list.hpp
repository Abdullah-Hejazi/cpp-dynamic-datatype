#ifndef LIST_H
#define LIST_H
#include "dynamic.hpp"

class List {
    private:
        Dynamic** data = NULL;
        int count = 0;

    public:
        List();

        void Print();

        void Add(Dynamic);
        void Add(int);
        void Add(double);
        void Add(bool);
        void Add(const char*);

        void Remove(int);
        int Length();
        void ClearList();
        Dynamic* Get(int);
};

#endif
