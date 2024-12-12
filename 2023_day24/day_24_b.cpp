#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <map>
#include <ranges>
#include <sstream>
#include <vector>

int day_24_b(std::string const& input)
{
    return 0;
}

TEST_CASE("24_b example input")
{
    auto const sum = day_24_b(exampleInput);
    REQUIRE(sum == 1);
}

TEST_CASE("24_b real input")
{
    auto const sum = day_24_b(realInput);
    REQUIRE(sum == 2);
}
