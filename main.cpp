#include "dynamic.hpp"
#include "list.hpp"
#include <iostream>

int main() {
    List list;

    Dynamic a = 5;
    Dynamic b = 2.5;
    Dynamic c = 6;
    Dynamic d = "hello";
    Dynamic e = true;

    list.Add(a);
    list.Add(b);
    list.Add(c);
    list.Add(d);
    list.Add(e);

    a = "hi";

    list.Remove(1);

    list.Print();
    std::cout << "\n";

    return 0;
}