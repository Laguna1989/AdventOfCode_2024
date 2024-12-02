#include "input.hpp"
#include "strutils.hpp"
#include <catch2/catch_all.hpp>
#include <algorithm>
#include <map>
#include <ranges>
#include <sstream>
#include <vector>

struct FileLine {
    std::string line;
    size_t line_number = 0;

    friend std::istream& operator>>(std::istream& s, FileLine& fl)
    {
        std::getline(s, fl.line);

        ++fl.line_number;

        return s;
    }
};

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
