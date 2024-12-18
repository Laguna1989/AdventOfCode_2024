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
    std::stringstream ss { input };

    std::vector<int> left;
    std::vector<int> right;

    for (auto const& [line, _] : std::views::istream<FileLine>(ss)) {
        auto const split = strutil::split(line, ' ');
        left.emplace_back(stoi(split.front()));
        right.emplace_back(stoi(split.back()));
    }
    std::ranges::sort(left);
    std::ranges::sort(right);

    auto view = std::views::zip(left, right)
        | std::views::transform([](auto const& kvp) { return abs(std::get<0>(kvp) - std::get<1>(kvp)); });

    return std::ranges::fold_left(view, 0, std::plus());
}

TEST_CASE("01a example input")
{
    auto const sum = day01_a(exampleInput);
    REQUIRE(sum == 11);
}

TEST_CASE("01a real input")
{
    auto const sum = day01_a(realInput);
    REQUIRE(sum == 1970720);
}
