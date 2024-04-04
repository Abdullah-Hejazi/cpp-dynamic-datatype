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

    list.Add(5);
    list.Add(1);
    list.Add(6);

    list.Remove(2);
}

int main() {
    // make_dynamic();
    make_list();

    return 0;
}