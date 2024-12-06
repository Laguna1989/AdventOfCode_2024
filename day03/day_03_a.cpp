#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <iostream>
#include <regex>

int day03_a(std::string const& input)
{
    std::stringstream const ss { input };
    std::string const str = ss.str();

    std::regex const exp("(mul\\([0-9]{1,3},[0-9]{1,3}\\))");
    std::smatch res;

    auto searchStart = str.cbegin();
    int sum = 0;
    while (regex_search(searchStart, str.cend(), res, exp)) {
        std::string single_instruction = res[0];
        // std::cout << single_instruction << std::endl;
        searchStart = res.suffix().first;
        strutil::replace_all(single_instruction, "mul(", "");
        strutil::replace_all(single_instruction, "(", "");
        strutil::replace_all(single_instruction, ",", " ");
        std::stringstream single_instruction_ss { single_instruction };
        int a;
        int b;
        single_instruction_ss >> a >> b;
        sum += a * b;
    }
    return sum;
}

TEST_CASE("03a example input")
{
    auto const sum = day03_a(exampleInput);
    REQUIRE(sum == 161);
}

TEST_CASE("03a real input")
{
    auto const sum = day03_a(realInput);
    REQUIRE(sum == 167650499);
}
