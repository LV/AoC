#include <charconv>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include "utils.h"

static const unsigned int EARLIEST_YEAR = 2015;
static const unsigned int LATEST_YEAR = 2024;

std::optional<Solution> processArguments(int argc, char* argv[]) {
    // Checks whether entered arguments are valid
    if (argc == 2) {
        std::string_view command{argv[1]};
        if (command == "--help" || command == "-h") {
            std::cout << "Usage: ./aoc <YEAR> <DAY> <PART>\n\n";
            std::cout << "Example: ./aoc 2020 4 2\n";
            return {};
        }
    }

    if (argc == 4) {
        std::string_view year_str{argv[1]};
        std::string_view day_str{argv[2]};
        std::string_view part_str{argv[3]};
        unsigned int year;
        unsigned int day;
        unsigned int part;

        auto year_res = std::from_chars(year_str.data(), year_str.data() + year_str.size(), year);
        auto day_res = std::from_chars(day_str.data(), day_str.data() + day_str.size(), day);
        auto part_res = std::from_chars(part_str.data(), part_str.data() + part_str.size(), part);

        // Argument input type validation
        if (year_res.ec != std::errc{})
            throw std::invalid_argument("Year is an invalid number format\n");

        if (day_res.ec != std::errc{})
            throw std::invalid_argument("Day is an invalid number format\n");

        if (part_res.ec != std::errc{})
            throw std::invalid_argument("Part is an invalid number format\n");


        // Argument input value validation
        if (year < EARLIEST_YEAR || year > LATEST_YEAR)
            throw std::invalid_argument(std::format("Year must be between {} and {}", EARLIEST_YEAR, LATEST_YEAR));

        if (day < 1 || day > 25)
            throw std::invalid_argument("Day must be between 1 and 25");

        if (part != 1 && part != 2)
            throw std::invalid_argument("Part must be either 1 or 2");

        return Solution(year, day, part);
    }

    std::cout << "Invalid inputs! Run with `--help`\n";
    std::cout << "Usage: ./aoc <YEAR> <DAY> <PART>\n";
    return {};
}
