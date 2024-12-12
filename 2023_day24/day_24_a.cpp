#include "input.hpp"
#include <catch2/catch_all.hpp>
#include <common/file_line.hpp>
#include <common/strutils.hpp>
#include <algorithm>
#include <ranges>
#include <sstream>
#include <vector>

// TODO Instructions for day setup:
/// - copy this folder and paste it e.g. as "day09"
/// - add new folder in top level CMakeLists.txt
/// - edit day09/CMakeLists.txt (new day)
/// - in this file (and in part_b): change "abc" -> "09"
/// - copy input from Advent of Code website to input.hpp
/// - paste readme in README.md

struct HailInfo {
    float px;
    float py;
    float pz;

    float vx;
    float vy;
    float vz;
};

struct Crossing {
    float x;
    float y;
};

int day_24_a(std::string const& input, float min, float max)
{
    std::stringstream ss { input };
    std::vector<HailInfo> infos;

    for (auto const& [line, _] : std::views::istream<FileLine>(ss)) {
        auto linecopy = line;
        strutil::replace_all(linecopy, "@", "");
        strutil::replace_all(linecopy, ",", "");
        std::stringstream liness { linecopy };
        HailInfo info;
        liness >> info.px >> info.py >> info.pz >> info.vx >> info.vy >> info.vz;
        infos.emplace_back(info);
    }

    std::vector<Crossing> crossings;

    for (int i = 0; i < infos.size(); ++i) {
        float const a1 = static_cast<float>(infos[i].vy) / infos[i].vx;
        float const b1 = static_cast<float>(infos[i].py) - static_cast<float>(infos[i].px * a1);

        for (auto j = i + 1; j < infos.size(); ++j) {
            float const a2 = static_cast<float>(infos[j].vy) / infos[j].vx;
            float const b2 = static_cast<float>(infos[j].py) - static_cast<float>(infos[j].px * a2);

            if (a1 == a2) {
                continue;
            }

            float const xcross = (b2 - b1) / (a1 - a2);
            float const ycross = a1 * xcross + b1;

            if (xcross < min) {
                continue;
            }
            if (ycross < min) {
                continue;
            }
            if (xcross > max) {
                continue;
            }
            if (ycross > max) {
                continue;
            }

            if (infos[i].vx > 0 != xcross > infos[i].px) {
                continue;
            }
            if (infos[j].vx > 0 != xcross > infos[j].px) {
                continue;
            }
            crossings.emplace_back(Crossing { .x = xcross, .y = ycross });
        }
    }

    return crossings.size();
}

TEST_CASE("24_a example input")
{
    auto const sum = day_24_a(exampleInput, 7.0f, 27.0f);
    REQUIRE(sum == 2);
}

TEST_CASE("24_a real input")
{
    auto const sum = day_24_a(realInput, 200000000000000.0f, 400000000000000.0f);
    REQUIRE(sum == 12740);
}
