#include "dynamic.hpp"
#include "list.hpp"
#include <iostream>

void make_dynamic() {
    Dynamic a = true;
    Dynamic b = 5;
    Dynamic c = 5.5;
    Dynamic d = "hello world";

    std::cout << "A: " << a << "\n";
    std::cout << "B: " << b << "\n";
    std::cout << "C: " << c << "\n";

    d = "lel";

    std::cout << "D: " << d << " -> " << d.GetSize() << "\n";
}

void make_list() {
    List list;
    Dynamic x = 5;
    Dynamic y = true;
    Dynamic z = 2.5;
    Dynamic d = "hi there";

    list.Add(x);
    list.Add(y);
    list.Add(z);
    list.Add(d);
    list.Add(d);
    list.Add(d);
    list.Add(d);

    list.Remove();
    std::cout << "List length: " << list.Length() << "\n";

    std::cout << "List: ";
    list.Print();
    std::cout << "\n";
}

int main() {
    // make_dynamic();
    make_list();

    return 0;
}