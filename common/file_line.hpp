#pragma once
#include <string>
#include <istream>

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
