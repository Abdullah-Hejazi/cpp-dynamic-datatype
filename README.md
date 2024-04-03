# Dynamic Datatype and Dynamic List in C++

My first attempt at making a dynamic datatype that can be (bool, int, double, string) at the same time and switch between them
And a List of dynamic.


### Build and Run
```
g++ main.cpp dynamic.cpp list.cpp -o bin/main
./bin/main
```

### Unit Tests
```
g++ tests/unity/unity.c tests/test.cpp tests/test_dynamic.cpp tests/test_list.cpp list.cpp dynamic.cpp -o bin/test
./bin/test
```