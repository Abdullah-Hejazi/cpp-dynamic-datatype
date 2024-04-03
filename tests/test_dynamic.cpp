#include "../dynamic.hpp"
#include <cstdlib>
#include "unity/unity.h"

void test_DynamicCanBeBool(void) {
	Dynamic d = true;

	TEST_ASSERT_EQUAL(true, *(bool*)d.GetValue());

	Dynamic d2 = false;

	TEST_ASSERT_EQUAL(false, *(bool*)d2.GetValue());
}

void test_DynamicCanBeInteger(void) {
	Dynamic d = 25;

	TEST_ASSERT_EQUAL(25, *(int*)d.GetValue());
}

void test_DynamicCanBeDouble(void) {
	Dynamic d = 2.5;

	TEST_ASSERT_EQUAL(2.5, *(double*)d.GetValue());
}

void test_DynamicCanBeString(void) {
	Dynamic d = "hello";

	TEST_ASSERT_EQUAL_STRING("hello", (char*)d.GetValue());
}

void test_DynamicBooleanCanChange(void) {
	Dynamic d = true;

	TEST_ASSERT_EQUAL(true, *(bool*)d.GetValue());

	d = false;

	TEST_ASSERT_EQUAL(false, *(bool*)d.GetValue());
}

void test_DynamicIntegerCanChange(void) {
	Dynamic d = 25;

	TEST_ASSERT_EQUAL(25, *(int*)d.GetValue());

	d = 30;

	TEST_ASSERT_EQUAL(30, *(int*)d.GetValue());
}

void test_DynamicDoubleCanChange(void) {
	Dynamic d = 5.5;

	TEST_ASSERT_EQUAL(5.5, *(double*)d.GetValue());

	d = 1.15;

	TEST_ASSERT_EQUAL(1.15, *(double*)d.GetValue());
}

void test_DynamicStringCanChange(void) {
	Dynamic d = "hello";

	TEST_ASSERT_EQUAL_STRING("hello", (char*)d.GetValue());

	d = "world";

	TEST_ASSERT_EQUAL_STRING("world", (char*)d.GetValue());
}

void test_DynamicBooleanCanMutate(void) {
	Dynamic d = true;

	TEST_ASSERT_EQUAL(true, *(bool*)d.GetValue());

	d = "hello";

	TEST_ASSERT_EQUAL_STRING("hello", (char*)d.GetValue());
}

void test_DynamicIntegerCanMutate(void) {
	Dynamic d = 25;

	TEST_ASSERT_EQUAL(25, *(int*)d.GetValue());

	d = "hello";

	TEST_ASSERT_EQUAL_STRING("hello", (char*)d.GetValue());
}

void test_DynamicDoubleCanMutate(void) {
	Dynamic d = 5.5;

	TEST_ASSERT_EQUAL(5.5, *(double*)d.GetValue());

	d = "hello";

	TEST_ASSERT_EQUAL_STRING("hello", (char*)d.GetValue());
}

void test_DynamicStringCanMutate(void) {
	Dynamic d = "hello";

	TEST_ASSERT_EQUAL_STRING("hello", (char*)d.GetValue());

	d = 25;

	TEST_ASSERT_EQUAL(25, *(int*)d.GetValue());
}


void test_DynamicCanBeCleared(void) {
	Dynamic d = 25;

	TEST_ASSERT_EQUAL(25, *(int*)d.GetValue());
	TEST_ASSERT_EQUAL(INTEGER, d.GetType());

	d.Clear();

	TEST_ASSERT_EQUAL(NULL, d.GetValue());
	TEST_ASSERT_EQUAL(NONE, d.GetType());
}