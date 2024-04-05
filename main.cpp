#include "dynamic.hpp"
#include "list.hpp"
#include <iostream>


void make_list() {
    List list;

    Dynamic x = 5;

    list.Push(5);
    list.Push(5);

    list.Remove(0);

    list.Print();

    Dynamic* d = list.Get(0);

    if (d) {
        std::cout << d->GetString() << "\n";
    }
}

int main() {
    // make_dynamic();
    make_list();

    return 0;
}