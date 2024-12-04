#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <map>
#include <ranges>
#include <sstream>
#include <vector>

int day01_b(std::string const& input)
{
    std::stringstream ss { input };

    std::vector<int> left;
    std::map<int, int> right;

    for (auto const& [line, _] : std::views::istream<FileLine>(ss)) {
        auto const split = strutil::split(line, ' ');
        left.emplace_back(stoi(split.front()));
        right[stoi(split.back())]++;
    }

    auto sum = 0;
    for (auto v : left) {
        sum += right[v] * v;
    }
    return sum;
}

TEST_CASE("01b example input")
{
    auto const sum = day01_b(exampleInput);
    REQUIRE(sum == 31);
}

TEST_CASE("01b real input")
{
    auto const sum = day01_b(realInput);
    REQUIRE(sum == 17191599);
}
