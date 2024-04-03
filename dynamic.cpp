#include "dynamic.hpp"
#include <iostream>
#include <cstring>

Dynamic::Dynamic() { }

Dynamic::Dynamic(bool value) {
    this->SetBoolean(value);
}

Dynamic::Dynamic(int value) {
    this->SetInteger(value);
}

Dynamic::Dynamic(double value) {
    this->SetDouble(value);
}

Dynamic::Dynamic(const char* value) {
    this->SetString(value);
}

Type Dynamic::GetType() const {
    return this->type;
}

bool Dynamic::GetBool() const {
    return *((bool*)this->value);
}

int Dynamic::GetInteger() const {
    return *((int*)this->value);
}

double Dynamic::GetDouble() const {
    return *((double*)this->value);
}

char* Dynamic::GetString() const {
    return ((char*)this->value);
}

void Dynamic::Print() const {
    switch (this->GetType()) {
        case BOOL: {
            std::cout << (this->GetBool() ? "true" : "false");
            break;
        }

        case INTEGER: {
            std::cout << this->GetInteger();
            break;
        }

        case DOUBLE: {
            std::cout << this->GetDouble();
            break;
        }

        case STRING: {
            std::cout << this->GetString();
            break;
        }
    }
}

void* Dynamic::GetValue() const {
    return this->value;
}

int Dynamic::GetSize() const {
    return this->size;
}

std::ostream& operator<<(std::ostream& os, const Dynamic& obj) {
    obj.Print();

    return os;
}

void Dynamic::SetBoolean(const bool other) {
    if (this->value != NULL) {
        free(this->value);
    }

    bool* newValue = new bool;
    *newValue = other;

    this->value = newValue;
    this->type = BOOL;

    this->size = sizeof(bool);
}

void Dynamic::SetInteger(const int other) {
    if (this->value != NULL) {
        free(this->value);
    }

    int* newValue = (int*)malloc(sizeof(int));
    *newValue = other;

    this->value = newValue;
    this->type = INTEGER;

    this->size = sizeof(int);
}

void Dynamic::SetDouble(const double other) {
    free(this->value);

    double* newValue = new double;
    *newValue = other;

    this->value = newValue;
    this->type = DOUBLE;

    this->size = sizeof(double);
}

void Dynamic::SetString(const char* other) {
    free(this->value);

    this->value = (char*)malloc(strlen(other) * sizeof(char));

    strcpy((char*)this->value, other);

    this->type = STRING;

    this->size = sizeof(strlen(other));
}

void Dynamic::SetDynamic(const Dynamic other) {
    this->type = other.GetType();

    switch (this->type) {
        case BOOL: {
            this->SetBoolean(*(const bool*)other.GetValue());
            break;
        }

        case INTEGER: {
            this->SetInteger(*(const int*)other.GetValue());
            break;
        }

        case DOUBLE: {
            this->SetDouble(*(const double*)other.GetValue());
            break;
        }

        case STRING: {
            this->SetString((char*)other.GetValue());
            break;
        }
    }
}

Dynamic& Dynamic::operator=(const bool other) {
    this->SetBoolean(other);
    return *this;
}

Dynamic& Dynamic::operator=(const int other) {
    this->SetInteger(other);

    return *this;
}

Dynamic& Dynamic::operator=(const double other) {
    this->SetDouble(other);

    return *this;
}

Dynamic& Dynamic::operator=(const char* other) {
    this->SetString(other);

    return *this;
}
