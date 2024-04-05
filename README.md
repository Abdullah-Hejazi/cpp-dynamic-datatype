# Dynamic Datatype and Dynamic List in C++

My first attempt at making a dynamic datatype that can be (bool, int, double, string) at the same time and switch between them
And a List of dynamic.


### Build and Run
```
g++ main.cpp dynamic.cpp list.cpp node.cpp -o bin/main && ./bin/main
./bin/main
```

### Unit Tests
```
g++ tests/unity/unity.c tests/test.cpp tests/test_dynamic.cpp tests/test_list.cpp node.cpp list.cpp dynamic.cpp -o bin/test
./bin/test
```

### Memory debugging with valgrind

requires installation of valgrind

```
g++ -g main.cpp dynamic.cpp list.cpp node.cpp -o bin/main
valgrind --tool=memcheck ./bin/main --track-origins=yes --leak-check=full --track-origins=yes -s
```