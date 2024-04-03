#include "list.hpp"
#include "dynamic.hpp"
#include <cstdlib>
#include <cstring>

List::List() {
    this->data = NULL;
    this->count = 0;
}

List::~List() {
    this->ClearList();
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
    switch(d.GetType()) {
        case BOOL: {
            this->Add(*(bool*)(d.GetValue()));
            break;
        }

        case INTEGER: {
            this->Add(*(int*)(d.GetValue()));
            break;
        }

        case DOUBLE: {
            this->Add(*(double*)(d.GetValue()));
            break;
        }

        case STRING: {
            this->Add((char*)(d.GetValue()));
            break;
        }
    }
}

void List::Add(int value) {
    if (this->data == NULL) {
        this->data = new (Dynamic*);
    } else {
        this->data = (Dynamic**)realloc(this->data, (this->count + 1) * sizeof(Dynamic*));
    }

    this->data[this->count] = new Dynamic(value);

    this->count++;
}

void List::Add(double value) {
    if (this->data == NULL) {
        this->data = new (Dynamic*);
    } else {
        this->data = (Dynamic**)realloc(this->data, (this->count + 1) * sizeof(Dynamic*));
    }

    this->data[this->count] = new Dynamic(value);

    this->count++;
}

void List::Add(bool value) {
    if (this->data == NULL) {
        this->data = new (Dynamic*);
    } else {
        this->data = (Dynamic**)realloc(this->data, (this->count + 1) * sizeof(Dynamic*));
    }

    this->data[this->count] = new Dynamic(value);

    this->count++;
}

void List::Add(const char* value) {
    if (this->data == NULL) {
        this->data = new (Dynamic*);
    } else {
        this->data = (Dynamic**)realloc(this->data, (this->count + 1) * sizeof(Dynamic*));
    }

    this->data[this->count] = new Dynamic(value);

    this->count++;
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

    this->data[index]->Clear();

    delete this->data[index];

    for(int i = index+1; i < this->count; i++) {
        memcpy(this->data[i - 1], this->data[i], sizeof(*this->data[i]));
    }

    this->count--;
}

int List::Length() {
    return this->count;
}

void List::ClearList() {
    if (this->count == 0) {
        return;
    }

    for(int i = this->count; i >= 0; i--) {
        this->data[i]->Clear();

        delete (Dynamic*)this->data[i];
    }

    this->count = 0;
}