#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <map>
#include <ranges>
#include <sstream>
#include <vector>

int day_04_b(std::string const& input)
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
            if (start != "A") {
                continue;
            }
            std::vector<std::string> neighboursA;
            std::vector<std::string> neighboursB;
            neighboursA.emplace_back(charAt(i + 1, j + 1));
            neighboursA.emplace_back(charAt(i - 1, j - 1));
            neighboursB.emplace_back(charAt(i + 1, j - 1));
            neighboursB.emplace_back(charAt(i - 1, j + 1));

            if (std::ranges::count(neighboursA, "M") == 1
                && std::ranges::count(neighboursA, "S") == 1) {
                if (std::ranges::count(neighboursB, "M") == 1
                    && std::ranges::count(neighboursB, "S") == 1) {
                    sum++;
                }
            }
        }
    }

    return sum;
}

TEST_CASE("04_b example input")
{
    auto const sum = day_04_b(exampleInput);
    REQUIRE(sum == 9);
}

TEST_CASE("04_b real input")
{
    auto const sum = day_04_b(realInput);
    REQUIRE(sum == 1967);
}
