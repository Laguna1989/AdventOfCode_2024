#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <map>
#include <ranges>
#include <sstream>
#include <vector>

int day_abc_b(std::string const& input)
{
    return 0;
}

TEST_CASE("abc_b example input")
{
    auto const sum = day_abc_b(exampleInput);
    REQUIRE(sum == 1);
}

TEST_CASE("abc_b real input")
{
    auto const sum = day_abc_b(realInput);
    REQUIRE(sum == 2);
}
