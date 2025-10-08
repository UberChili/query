#include <algorithm>
#include <map>
#include <print>
#include <string>
#include <vector>

#include "utils.hpp"

void print_table(std::vector<std::map<std::string, std::string>> &table) {
    if (table.empty()) {
        std::println("Empty table");
    }
    std::vector<std::string> column_names;
    std::vector<std::string> column_values;

    // Getting column names and column values
    for (const auto &[k, v] : table[0]) {
        column_names.push_back(k);
        column_values.push_back(v);
    }

    auto largest = std::max_element(column_values.begin(), column_values.end());
    size_t width = std::strlen(largest->data()) + 1;

    // Step 1: Just print column names, no formatting yet
    for (const auto &col_name : column_names) {
        size_t fixed_width = std::strlen(col_name) - width;
        std::string formatted = std::format(" {}", col_name);
        for (size_t i = 0; i < width; i++)
            formatted += " ";
        std::print("{}|", formatted);
    }
    std::println("");

    // Step 2: Print all rows
    for (const auto &row : table) {
        for (const auto &col_name : column_names) {
            std::print("{} | ", row.at(col_name));
        }
        std::println("");
    }
}
