// #include "bst.hpp"
#include <fstream>
#include <iostream>
#include <print>
#include <string>
#include <vector>

#include <CLI11.hpp>
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

int main(int argc, char **argv) {
    // Getting command line arguments
    CLI::App app{"App description"};
    argv = app.ensure_utf8(argv);

    std::vector<std::string> select_columns;
    app.add_option("-s, --select", select_columns,
                   "Selection. Can be multiple columns.");

    std::string col_search = "";
    app.add_option("-w, --where", col_search, "Column name to search with.");

    std::string operation = "==";
    app.add_option("-o, --operation", operation, "Operation to search with.");

    std::string value = "";
    app.add_option("-v, --value ", value, "Value to filter with.");

    CLI11_PARSE(app, argc, argv);

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

    // Filter specified columns
    auto results = filter(rows_v, select_columns, col_search, operation, value);

    std::println("");
    print_table(results);
    std::println("Found {} rows.", results.size());

    return 0;
}
