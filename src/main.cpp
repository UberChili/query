// #include "bst.hpp"
#include <fstream>
#include <iostream>
#include <print>
#include <string>
#include <vector>

#include <csv.hpp>
#include <filter.hpp>
#include <utils.hpp>

std::string prompt() {
    std::string input;
    do {
        std::print("prompt> ");
        std::getline(std::cin, input);
        if (input.empty()) {
            continue;
        } else {
            std::print("\t{}\n", input);
            return input;
        }
    } while (true);
}

void parse(std::string query) {
    if (query.empty()) {
        std::println("Empty query");
        return;
    }
}

std::vector<std::string> load_file(std::string filename) {
    std::string line;
    std::vector<std::string> lines;

    // Need to open the file first!
    std::ifstream ifs{filename};
    if (!ifs) {
        std::println("Error: Could not open file {}.", filename);
        return {};
    }

    while (std::getline(ifs, line)) {
        lines.push_back(line);
    }

    return lines;
}

int main(void) {
    // First clear of screen
    system("clear");

    io::CSVReader<5> in("iris.csv");
    in.read_header(io::ignore_no_column, "sepal_length", "sepal_width",
                   "petal_length", "petal_width", "species");
    std::string sepal_length, sepal_width, petal_length, petal_width, species;
    std::vector<IrisRow> rows_v;
    while (in.read_row(sepal_length, sepal_width, petal_length, petal_width,
                       species)) {
        rows_v.push_back(IrisRow{sepal_length, sepal_width, petal_length,
                                 petal_width, species});
    }

    // Trying to get to specified columns
    std::vector<std::string> select_v = {"species", "petal_length"};
    auto results = filter(rows_v, select_v, "petal_length", ">", "4.9");

    std::println("Found {} rows.", results.size());
    print_table(results);

    return 0;
}
