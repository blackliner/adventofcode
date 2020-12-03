#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "aoc_1.h"

SCENARIO("advent of code 1")
{
    GIVEN("no file")
    {
        const std::string filename{};
        WHEN("parseFile is called")
        {
            const auto list = parseFile(filename);
            THEN("an empty list is returned")
            {
                REQUIRE(list.empty());
            }
        }
    }

    GIVEN("empty file")
    {
        TempFile temp_file;
        WHEN("parseFile is called")
        {
            const auto list = parseFile(temp_file.getFileName());
            THEN("an empty list is returned")
            {
                REQUIRE(list.empty());
            }
        }
    }

    GIVEN("file with one entry")
    {
        TempFile temp_file;
        temp_file.write("1713");
        WHEN("parseFile is called")
        {
            const auto list = parseFile(temp_file.getFileName());
            THEN("a list with size 1 is returned")
            {
                REQUIRE(list.size() == 1);
            }
            THEN("the number in the list is correct")
            {
                REQUIRE(list[0] == 1713);
            }
        }
    }

    GIVEN("file with example entries")
    {
        TempFile temp_file;
        temp_file.write("1721");
        temp_file.write("979");
        temp_file.write("366");
        temp_file.write("299");
        temp_file.write("675");
        temp_file.write("1456");

        WHEN("parseFile is called")
        {
            const auto list = parseFile(temp_file.getFileName());
            THEN("a list with size 1 is returned")
            {
                REQUIRE(list.size() == 6);
            }
            THEN("the numbers in the list are correct")
            {
                REQUIRE(list[0] == 1721);
                REQUIRE(list[1] == 979);
                REQUIRE(list[2] == 366);
                REQUIRE(list[3] == 299);
                REQUIRE(list[4] == 675);
                REQUIRE(list[5] == 1456);
            }
        }

        WHEN("findSum is called")
        {
            const auto result = findSum(temp_file.getFileName());
            THEN("result should be a pair with 299 and 1721")
            {
                REQUIRE(result.first == 299);
                REQUIRE(result.second == 1721);
            }
        }
    }

    GIVEN("file with many entries")
    {
        const std::string filename{"advent_input.txt"};

        WHEN("parseFile is called")
        {
            const auto list = parseFile(filename);
            THEN("a list with size 200 is returned")
            {
                REQUIRE(list.size() == 200);
            }
            THEN("the first few numbers in the list are correct")
            {
                REQUIRE(list[0] == 1713);
                REQUIRE(list[1] == 1281);
                REQUIRE(list[2] == 1185);
                REQUIRE(list[3] == 1501);
            }
        }

        WHEN("findSum is called")
        {
            const auto result = findSum(filename);
            THEN("result should be a pair with 438 and 1582")
            {
                REQUIRE(result.first == 438);
                REQUIRE(result.second == 1582);
            }
        }
    }
}