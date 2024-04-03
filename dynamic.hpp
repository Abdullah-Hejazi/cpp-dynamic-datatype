#ifndef DYNAMIC_H
#define DYNAMIC_H
#include <iostream>

enum Type {
    BOOL,
    INTEGER,
    DOUBLE,
    STRING
};

class Dynamic {
    private:
        void* value = NULL;
        Type type;
        int size = 0;

    public:
        Type GetType() const;
        int GetSize() const;

        void Print() const;
        void* GetValue() const;

        Dynamic();
        Dynamic(bool);
        Dynamic(int);
        Dynamic(double);
        Dynamic(const char*);

        int GetInteger() const;
        double GetDouble() const;
        char* GetString() const;
        bool GetBool() const;

        Dynamic& operator=(const int other);
        Dynamic& operator=(const double other);
        Dynamic& operator=(const char* other);
        Dynamic& operator=(const bool other);
        Dynamic& operator=(const Dynamic other);

        void SetBoolean(const bool);
        void SetInteger(const int);
        void SetDouble(const double);
        void SetString(const char*);
        void SetDynamic(const Dynamic);
};

std::ostream& operator<<(std::ostream& os, const Dynamic& obj);

#endif