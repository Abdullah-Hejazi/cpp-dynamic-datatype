#include "dynamic.hpp"
#include "list.hpp"
#include <iostream>

int main() {
    List list;

    // Dynamic a = 5;
    // Dynamic b = 2.5;
    // Dynamic c = 6;
    // Dynamic d = "hello";
    // Dynamic e = true;

    list.Add(true);
    list.Add(true);
    list.Add(true);
    list.Add(true);
    // list.Add("hi there");
    // list.Add(a);

    // a = "hi";

    // list.Remove(1);

    // Dynamic* first = list.Get(0);
    // *first = "first changed";

    // list.Print();
    // std::cout << "\n";
    // std::cout << "Length: " << list.Length() << "\n";

    return 0;
}