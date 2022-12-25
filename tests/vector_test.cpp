#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../data-structures-lib/vector.h"
#include <iostream>
#include "doctest/doctest/doctest.h"

TEST_CASE("Constructors")
{
    vector v1;
    CHECK(v1.size()== 0);
    CHECK(v1.capacity() == 10);

    vector v2(2);
    CHECK(v2.size()== 2);
    CHECK(v2.capacity() == 10);

    vector v3(20);
    CHECK(v3.size() == 20);
    CHECK(v3.capacity() == 40);

    vector v4(v3);
    CHECK(v4.size() == 20);
    CHECK(v4.capacity() == 40);
}

TEST_CASE("Adding elements")
{
    vector v1;
    v1.push_back(3);
    CHECK(v1[0] == 3);
    v1.push_back(23);
    CHECK(v1[1] == 23);
    CHECK(v1.size() == 2);
    CHECK(v1.capacity() == 10);
    v1.push_back(23);
    v1.push_back(13);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(6);

    CHECK(v1.size() == 8);
    CHECK(v1.capacity() == 10);
    v1.push_back(7);
    CHECK(v1.capacity() == 10);
    CHECK(v1.size() == 9);
    v1.push_back(8);
    CHECK(v1.size() == 10);
    CHECK(v1.capacity() == 10); // Reaching the capacity

    v1.push_back(7);
    CHECK(v1.size() == 11);
    CHECK(v1.capacity() == 22);
}

TEST_CASE("Reserve")
{
    vector v1;
    v1.reserve(20);
    v1.push_back(1);
    CHECK(v1.size() == 1);
    CHECK(v1.capacity() == 20);
}

TEST_CASE("Resize")
{
    vector v1 = vector();
    CHECK(v1.size() == 0);
    CHECK(v1.capacity() == 10);
    v1.resize(20);
    CHECK(v1.size() == 20);
    CHECK(v1.capacity() == 40);
}