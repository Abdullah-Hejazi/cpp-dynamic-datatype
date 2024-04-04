#include "dynamic.hpp"
#include <iostream>
#include <cstring>

Dynamic::Dynamic() {
    this->value = NULL;
}

Dynamic::~Dynamic() {
    this->Clear();
}

Dynamic::Dynamic(bool val) {
    this->SetBoolean(val);
}

Dynamic::Dynamic(int val) {
    this->SetInteger(val);
}

Dynamic::Dynamic(double val) {
    this->SetDouble(val);
}

Dynamic::Dynamic(const char* val) {
    this->SetString(val);
}

Dynamic::Dynamic(const Dynamic& val) {
    switch (val.GetType()) {
         case BOOL: {
             this->SetBoolean(*(bool*)val.GetValue());
             break;
         }

         case INTEGER: {
             this->SetInteger(*(int*)val.GetValue());
             break;
         }

         case DOUBLE: {
             this->SetDouble(*(double*)val.GetValue());
             break;
         }

         case STRING: {
             this->SetString((char*)val.GetValue());
             break;
         }
    }
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
    this->Clear();

    this->value = new bool(other);

    this->type = BOOL;

    this->size = sizeof(bool);
}

void Dynamic::SetInteger(const int other) {
    this->Clear();

    this->value = new int(other);

    this->type = INTEGER;

    this->size = sizeof(int);
}

void Dynamic::SetDouble(const double other) {
    this->Clear();

    this->value = new double(other);

    this->type = DOUBLE;

    this->size = sizeof(double);
}

void Dynamic::SetString(const char* other) {
    this->Clear();

    this->value = new char[strlen(other) + 1];

    strcpy((char*)this->value, other);

    this->type = STRING;

    this->size = strlen(other);
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

Dynamic& Dynamic::operator=(const Dynamic other) {
    this->SetDynamic(other);

    return *this;
}

void Dynamic::Clear() {
    if (this->size == 0 || this->type == NONE) {
        return;
    }

    if (this->value == NULL) {
        return;
    }

    switch(this->type) {
        case BOOL: {
            delete (bool*) this->value;
            break;
        }
        case INTEGER: {
            delete (int*) this->value;
            break;
        }
        case DOUBLE: {
            delete (double*) this->value;
            break;
        }
        case STRING: {
            delete[] (char*) this->value;
            break;
        }
    }

    this->value = NULL;

    this->type = NONE;

    this->size = 0;
}