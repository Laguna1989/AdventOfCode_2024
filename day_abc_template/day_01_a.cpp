#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <algorithm>
#include <ranges>
#include <sstream>
#include <vector>

// TODO Instructions for day setup:
/// - copy this folder and paste it e.g. as "day09"
/// - add new folder in top level CMakeLists.txt
/// - edit day09/CMakeLists.txt (new day)
/// - in this file (and in part_b): change "abc" -> "09"
/// - copy input from Advent of Code website to input.hpp
/// - paste readme in README.md

int day_abc_a(std::string const& input)
{
   return 0;
}

TEST_CASE("abc_a example input")
{
    auto const sum = day_abc_a(exampleInput);
    REQUIRE(sum == 1);
}

TEST_CASE("abc_a real input")
{
    auto const sum = day_abc_a(realInput);
    REQUIRE(sum == 2);
}
