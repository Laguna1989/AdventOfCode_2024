#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <algorithm>
#include <ranges>
#include <sstream>
#include <vector>

// TODO Instructions for day setup:
/// - copy input from Advent of Code website to input.hpp
/// - paste readme in README.md

int day_04_a(std::string const& input)
{
    std::stringstream ss { input };

    std::vector<std::string> tokens;
    int width = 0;
    int height = 0;

    for (auto const& fileLine : std::views::istream<FileLine>(ss)) {
        width = fileLine.line.size();
        height = fileLine.line_number;
        for (auto const c : fileLine.line) {
            std::string cs { c };
            tokens.push_back(cs);
        }
    }

    auto const charAt = [&](int x, int y) {
        if (x < 0 || x >= width) {
            return std::string { "" };
        }
        if (y < 0 || y >= height) {
            return std::string { "" };
        }
        auto const idx = x + y * width;
        return std::string { tokens.at(idx) };
    };

    int sum = 0;
    for (auto i = 0; i != width; ++i) {
        for (auto j = 0; j != height; ++j) {
            auto const start = charAt(i, j);
            if (start != "X") {
                continue;
            }
            for (auto dir : std::vector<std::pair<int, int>> { { 1, 0 }, { 1, 1 }, { 0, 1 },
                     { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 } }) {
                bool found = true;
                for (auto [idx, c] :
                    std::ranges::views::enumerate(std::vector { "X", "M", "A", "S" })) {
                    auto const x = i + dir.first * idx;
                    auto const y = j + dir.second * idx;
                    auto const current = charAt(x, y);
                    if (current != std::string { c }) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    sum++;
                }
            }
        }
    }

    return sum;
}

TEST_CASE("04_a example input")
{
    auto const sum = day_04_a(exampleInput);
    REQUIRE(sum == 18);
}

TEST_CASE("04_a real input")
{
    auto const sum = day_04_a(realInput);
    REQUIRE(sum == 2496);
}
