#include "../list.hpp"
#include "../dynamic.hpp"
#include "unity/unity.h"

void test_CreateList(void) {
    List list;

    list.Push(5);

	TEST_ASSERT_EQUAL(1, list.Length());
}

void test_AddBooleanToList(void) {
    List list;

    list.Push(true);

	TEST_ASSERT_EQUAL(1, list.Length());

	TEST_ASSERT_EQUAL(BOOL, list.Get(0)->GetType());
}

void test_AddIntegerToList(void) {
    List list;

    list.Push(5);

	TEST_ASSERT_EQUAL(1, list.Length());

	TEST_ASSERT_EQUAL(INTEGER, list.Get(0)->GetType());
}

void test_AddDoubleToList(void) {
    List list;

    list.Push(2.5);

	TEST_ASSERT_EQUAL(1, list.Length());

	TEST_ASSERT_EQUAL(DOUBLE, list.Get(0)->GetType());
}

void test_AddDynamicToList(void) {
    List list;
    Dynamic d = 5;

    list.Push(d);

	TEST_ASSERT_EQUAL(1, list.Length());

	TEST_ASSERT_EQUAL(INTEGER, list.Get(0)->GetType());
}

void test_AddStringToList(void) {
    List list;

    list.Push("Hello");

	TEST_ASSERT_EQUAL(1, list.Length());

	TEST_ASSERT_EQUAL(STRING, list.Get(0)->GetType());
}

void test_RemoveFirstElementFromList(void) {
    List list;

    list.Push(5);

	TEST_ASSERT_EQUAL(1, list.Length());

	TEST_ASSERT_EQUAL(INTEGER, list.Get(0)->GetType());

    list.Remove(0);

	TEST_ASSERT_EQUAL(0, list.Length());
}

void test_RemoveFromList(void) {
    List list;

    list.Push(5);
    list.Push(1);
    list.Push(6);

	TEST_ASSERT_EQUAL(3, list.Length());

    list.Remove(1);

	TEST_ASSERT_EQUAL(2, list.Length());
}

void test_RemoveLastElementFromList(void) {
    List list;

    list.Push(5);
    list.Push(1);
    list.Push(6);

	TEST_ASSERT_EQUAL(3, list.Length());

    list.Remove(2);

	TEST_ASSERT_EQUAL(2, list.Length());
}


void test_ListLengthWorks(void) {
    List list;

    list.Push(5);
	TEST_ASSERT_EQUAL(1, list.Length());

    list.Push(1);
	TEST_ASSERT_EQUAL(2, list.Length());

    list.Push(6);
	TEST_ASSERT_EQUAL(3, list.Length());

    list.Remove(0);
	TEST_ASSERT_EQUAL(2, list.Length());

    list.Remove(1);
	TEST_ASSERT_EQUAL(1, list.Length());
}

void test_ListCanBeCleared(void) {
    List list;

    list.Push(5);
	TEST_ASSERT_EQUAL(1, list.Length());

    list.Push(1);
	TEST_ASSERT_EQUAL(2, list.Length());

    list.Push(6);
	TEST_ASSERT_EQUAL(3, list.Length());

    list.ClearList();

	TEST_ASSERT_EQUAL(0, list.Length());
}