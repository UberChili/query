#include <algorithm>
#include <cstring>
#include <format>
#include <map>
#include <print>
#include <string>
#include <vector>

#include "utils.hpp"

void print_table(std::vector<std::map<std::string, std::string>>& table) {
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
    // Getting column width
    // This is wrong, or incomplete
    size_t col_width = std::strlen(std::max_element(column_values.begin(), column_values.end())->data()) + 1;

    // print header row
    for (auto it = column_names.begin(); it != column_names.end(); it++) {
        // format the string to print
        std::string col_name = std::format("{}", it->data());
        for (size_t i = 0; i < strlen(it->data()) - col_width; i++) {
            col_name += " ";
        }
        
        // print last column name
        if (it == column_names.end()) {
            std::println("| {}", col_name);
            break;
        }

        // print first column name
        if (it == column_names.begin()) {
            std::print("{}", col_name);
        }

        // print normal (not first not last) column names
        std::string col = std::format("| {}", col_name);
        std::print("{}", col);
    }

    // print column values
    for (auto it = column_values.begin(); it != column_values.end(); it++) {
        // format the string to print
        std::string col = std::format("{}", it->data());
        for (size_t i = 0; i < strlen(it->data()) - col_width; i++) {
            col += " ";
        }
        
        // print last column name
        if (it == column_values.end()) {
            std::println("| {}", col);
            break;
        }

        // print first column name
        if (it == column_values.begin()) {
            std::print("{}", col);
        }

        // print normal (not first not last) column names
        std::string col_ = std::format("| {}", col);
        std::print("{}", col_);
    }
}
