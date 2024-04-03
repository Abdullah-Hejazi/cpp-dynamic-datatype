#include "unity/unity.h"
#include "test_dynamic.hpp"
#include "test_list.hpp"

void setUp(void) { }

void tearDown(void) { }

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_DynamicCanBeBool);
    RUN_TEST(test_DynamicCanBeInteger);
    RUN_TEST(test_DynamicCanBeDouble);
    RUN_TEST(test_DynamicCanBeString);

    RUN_TEST(test_DynamicBooleanCanChange);
    RUN_TEST(test_DynamicIntegerCanChange);
    RUN_TEST(test_DynamicDoubleCanChange);
    RUN_TEST(test_DynamicStringCanChange);

    RUN_TEST(test_DynamicBooleanCanMutate);
    RUN_TEST(test_DynamicIntegerCanMutate);
    RUN_TEST(test_DynamicDoubleCanMutate);
    RUN_TEST(test_DynamicStringCanMutate);

    RUN_TEST(test_DynamicCanBeCleared);


    RUN_TEST(test_CreateList);

    RUN_TEST(test_AddBooleanToList);
    RUN_TEST(test_AddIntegerToList);
    RUN_TEST(test_AddDoubleToList);
    RUN_TEST(test_AddStringToList);
    RUN_TEST(test_AddDynamicToList);

    RUN_TEST(test_RemoveFirstElementFromList);
    RUN_TEST(test_RemoveFromList);
    RUN_TEST(test_RemoveLastElementFromList);

    RUN_TEST(test_ListLengthWorks);
    RUN_TEST(test_ListCanBeCleared);

    return UNITY_END();
}