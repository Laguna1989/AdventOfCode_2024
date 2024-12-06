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

int day02_b(std::string const& input)
{
    std::stringstream ss { input };

    auto view = std::views::istream<FileLine>(ss) | std::views::transform([](auto const& fileLine) {
        std::stringstream ssline { fileLine.line };
        std::vector<int> report;
        int number;
        while (ssline >> number) {
            report.push_back(number);
        }

        return report;
    }) | std::views::transform([](auto const& report) {
        std::vector<std::deque<int>> allReportOptions;
        // create all possible options from dropping any number
        for (auto i = 0u; i < report.size(); ++i) {
            std::vector<int> difCopy { report.cbegin(), report.cend() };
            difCopy.erase(std::next(difCopy.begin(), i));

            std::deque<int> differences;
            differences.resize(difCopy.size());
            std::adjacent_difference(difCopy.begin(), difCopy.end(), differences.begin());
            differences.pop_front();
            allReportOptions.push_back(differences);
        }

        return allReportOptions;
    }) | std::views::filter([](auto const& allOptions) {
        return std::ranges::any_of(allOptions, [](auto const& difference_option) {
            bool const all_positive
                = std::ranges::all_of(difference_option, [](auto v) { return v < 0; });
            bool const all_negative
                = std::ranges::all_of(difference_option, [](auto v) { return v > 0; });
            bool const in_allowed_range = std::ranges::all_of(
                difference_option, [](auto v) { return abs(v) > 0 && abs(v) <= 3; });

            return (all_negative != all_positive) && in_allowed_range;
        });
    });

    return std::ranges::distance(view.cbegin(), view.cend());
}

TEST_CASE("02b example input")
{
    auto const sum = day02_b(exampleInput);
    REQUIRE(sum == 4);
}

TEST_CASE("02b real input")
{
    auto const sum = day02_b(realInput);
    REQUIRE(sum == 626);
}
