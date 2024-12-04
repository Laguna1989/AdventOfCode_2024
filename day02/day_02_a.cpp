#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <sstream>
#include <type_traits>
#include <vector>

int day02_a(std::string const& input)
{
    std::stringstream ss { input };

    auto view = std::views::istream<FileLine>(ss) | std::views::transform([](auto const& fileLine) {
        // convert each line to report
        std::stringstream ssLine { fileLine.line };
        std::vector<int> report;
        int number;
        while (ssLine >> number) {
            report.push_back(number);
        }
        return report;
    }) | std::views::transform([](auto const& report) {
        // convert report to differences
        std::deque<int> differences;
        differences.resize(report.size());
        std::adjacent_difference(report.begin(), report.end(), differences.begin());
        differences.pop_front();
        return differences;
    }) | std::views::filter([](auto const& differences) {
        // filter each difference
        bool const all_positive = std::ranges::all_of(differences, [](auto v) { return v < 0; });
        bool const all_negative = std::ranges::all_of(differences, [](auto v) { return v > 0; });
        bool const in_allowed_range
            = std::ranges::all_of(differences, [](auto v) { return abs(v) > 0 && abs(v) <= 3; });

        return (all_positive != all_negative) && in_allowed_range;
    }) |
        // needed for counting
        std::views::transform([](auto const& /*differences*/) { return 1; });

    return std::ranges::fold_left(view, 0, std::plus());
}

TEST_CASE("02a example input")
{
    auto const sum = day02_a(exampleInput);
    REQUIRE(sum == 2);
}

TEST_CASE("02a real input")
{
    auto const sum = day02_a(realInput);
    REQUIRE(sum == 585);
}
