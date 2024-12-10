#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <algorithm>
#include <ranges>
#include <sstream>
#include <vector>

int day01_a(std::string const& input)
{
   return 0;
}

TEST_CASE("01a example input")
{
    auto const sum = day01_a(exampleInput);
    REQUIRE(sum == 1);
}

TEST_CASE("01a real input")
{
    auto const sum = day01_a(realInput);
    REQUIRE(sum == 2);
}
