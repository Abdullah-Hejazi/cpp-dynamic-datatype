#include "list.hpp"
#include "dynamic.hpp"
#include <cstdlib>
#include <cstring>

List::List() {
    this->data = NULL;
    this->count = 0;
}

void List::Print() {
    if (this->count == 0) {
        std::cout << "(Empty List)";
        return;
    }

    for(int i = 0; i < this->count; i++) {
        this->data[i]->Print();
        if (i < this->count - 1) {
            std::cout << ", ";
        }
    }
}

Dynamic* List::Get(int index) {
    if (this->data == NULL) {
        return NULL;
    }

    if (index >= this->count) {
        return NULL;
    }

    if (index < 0) {
        return NULL;
    }

    return this->data[index];
}

void List::Add(Dynamic d) {
    if (this->data == NULL) {
        this->data = (Dynamic**)malloc(sizeof(Dynamic*));
    } else {
        this->data = (Dynamic**)realloc(this->data, (this->count + 1) * sizeof(Dynamic*));
    }

    this->data[this->count] = (Dynamic*)malloc(sizeof(Dynamic));

    this->data[this->count]->SetDynamic(d);

    this->count++;
}

void List::Add(int value) {
    Dynamic d = value;

    this->Add(d);
}

void List::Add(double value) {
    Dynamic d = value;

    this->Add(d);
}

void List::Add(bool value) {
    Dynamic d = value;

    this->Add(d);
}

void List::Add(const char* value) {
    Dynamic d = value;

    this->Add(d);
}

void List::Remove(int index) {
    if (this->data == NULL) {
        return;
    }

    if (index >= this->count) {
        return;
    }

    if (index < 0) {
        return;
    }

    free(this->data[index]);

    for(int i = index+1; i < this->count; i++) {
        memcpy(this->data[i - 1], this->data[i], sizeof(*this->data[i]));
    }

    this->count--;
}

int List::Length() {
    return this->count;
}

void List::ClearList() {
    for(int i = this->count - 1; i >= 0; i--) {
        this->Remove(i);
    }
}