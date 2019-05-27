#include "catch.hpp"
#include "main.h"
#include "UnionFind.h"

SCENARIO("Testing Disjoint-Set data structure")
{
    GIVEN("A set of 25 elements")
    {
        UTEC::UnionFind<int> uf(25);
        uf.join(3, 8);
        uf.join(15, 2);
        uf.join(23, 15);
        WHEN("3 is into 8")
        {
            THEN("Test if 3 is into 8")
            {
                REQUIRE(uf.find(3) == 8);
                REQUIRE(uf[3] << uf[8]);
            }
        }
        WHEN("15 is into 2")
        {
            THEN("Test if 15 is into 2")
            {
                REQUIRE(uf[15] << uf[2]);
            }
        }
        WHEN("23 is into 15")
        {
            THEN("Test if 23 is into 15")
            {
                REQUIRE(uf[23] << uf[15]);
            }
            THEN("Find parent of 23")
            {
                REQUIRE(uf.find(23) == 2);
            }
        }
    }
}