// #include "bst.hpp"
#include <fstream>
#include <iostream>
#include <print>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include <csv.hpp>

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

struct IrisRow {
    std::string sepal_length, sepal_width, petal_length, petal_width, species;
};

// std::vector<IrisRow> filter_by_species(const std::vector<IrisRow> &rows,
//                                        const std::string &species) {
//     std::vector<IrisRow> results;

//     for (const auto &row : rows) {
//         if (row.species == species) {
//             results.push_back(row);
//         }
//     }
//     return results;
// }


std::string get_column_value(const IrisRow& row, const std::string& column) {
    if (column == "sepal_length") return row.sepal_length;
    if (column == "sepal_width") return row.sepal_width;
    if (column == "petal_length") return row.petal_length;
    if (column == "petal_width") return row.petal_width;
    if (column == "species") return row.species;

    return "";
}

std::vector<IrisRow> filter(const std::vector<IrisRow>& rows,
    const std::string& column,
    const std::string& operation,
    const std::string& value)
{
    std::vector<IrisRow> results;

    for (const auto &row : rows) {
        std::string column_value = get_column_value(row, column);
        bool matches = false;

        if (operation == "==") {
            if (column_value == value) 
                results.push_back(row);
        }
        try {
            if (operation == ">") {
                float value_f = std::stof(value);
                float column_f = std::stof(column_value);

                if (column_f > value_f) {
                    results.push_back(row);
                }
            }
            if (operation == "<") {
                float value_f = std::stof(value);
                float column_f = std::stof(column_value);

                if (column_f < value_f) {
                    results.push_back(row);
                }
            }
        } catch (std::invalid_argument) {
            std::println("Can't convert a value!");
            return {};
        }
    }

    return results;
}

int main(void) {
    // First clear of screen
    system("clear");

    // std::vector<std::string> file = load_file("iris.csv");
    // if (file.empty()) {
    //     return 1;
    // }

    // for (const auto& line : file) {
    //     println("{}", line);
    // }

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

    // Let's start with something simple, printing out all the rows where
    // species == "setosa"
    // auto results = filter_by_species(rows_v, "setosa");
    auto results = filter(rows_v, "sepal_lenght", ">", "5.0");

    for (const auto &row : results) {
        std::println("{},{},{},{},{}", row.sepal_length, row.sepal_width, row.petal_length, row.petal_width, row.species);
    }

    std::println("Found {} rows.", results.size());

    // // Testing our tree
    // std::vector<int> nums = {70, 5, 2, 4, 8, 7, 3, 3};
    // Tree tree =  Tree();
    // for (const auto& num : nums) {
    //   tree.insert(num);
    // }
    // tree.print_tree();

    // while (true) {
    //  std::string in_prompt = prompt();
    //  // Process the string, parse to AST
    // };

    return 0;
}
