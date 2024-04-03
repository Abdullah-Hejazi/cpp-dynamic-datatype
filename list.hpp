#include "dynamic.hpp"

class List {
    private:
        Dynamic** data = NULL;
        int count = 0;

    public:
        List();

        void Print();
        void Add(Dynamic d);
        void Remove(int);
};
