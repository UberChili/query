// #include "bst.hpp"
#include <fstream>
#include <iostream>
#include <print>
#include <string>
#include <unordered_map>
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

while(std::getline(ifs, line)) {
    lines.push_back(line);
}

return lines;
}

struct IrisRow {
    std::string sepal_length, sepal_width, petal_length, petal_width, species;
};

std::vector<std::string> filter_by_species(const std::vector<IrisRow>& rows, const std::string& species) {
    std::vector<std::string> results;

    for (const auto& row : rows) {
        if (row.species == species) {
            std::string line = row.petal_length + "," + row.petal_width + "," + row.sepal_length + "," + row.sepal_width + "," + row.species;
            results.push_back(line);
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
    in.read_header(io::ignore_no_column, "sepal_length", "sepal_width", "petal_length", "petal_width", "species");
    std::string sepal_length, sepal_width, petal_length, petal_width, species;
    std::vector<IrisRow> rows_v;
    while (in.read_row(sepal_length, sepal_width, petal_length, petal_width, species)) {
        rows_v.push_back(IrisRow{sepal_length, sepal_width, petal_length, petal_width, species});
    }

    // Let's start with something simple, printing out all the rows where species == "setosa"
    auto results = filter_by_species(rows_v, "setosa");

    for (const auto& row : results) {
        std::println("{}", row);
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
