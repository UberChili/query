#include <algorithm>
#include <format>
#include <map>
#include <print>
#include <stdexcept>
#include <string>
#include <vector>

#include "utils.hpp"

void sort_table(std::vector<std::map<std::string, std::string>> &table, std::string &column) {
    if (table.empty()) {
        std::println("Empty table. Nothing to do.");
        return;
    }
    if (column.empty()) {
        return;
    }

    std::sort(table.begin(), table.end(), [&column](const auto& a, const auto& b) {
        try {
            float a_f = std::stof(a.at(column));
            float b_f = std::stof(b.at(column));

            return a_f < b_f;
        } catch (std::invalid_argument&) {
            return a.at(column) < b.at(column);
        }
    });
}


void print_table(std::vector<std::map<std::string, std::string>> &table) {
    if (table.empty()) {
        std::println("Empty table");
    }
    std::vector<std::string> column_names;

    // Getting column names and column values
    for (const auto &[k, v] : table[0]) {
        column_names.push_back(k);
    }

    // Finding largest value in column to use as width
    std::map<std::string, size_t> column_widths;
    for (const auto &col : column_names) {
        size_t max_width = col.size();

        for (const auto &row : table) {
            size_t curr_width = row.at(col).size();
            if (curr_width > max_width)
                max_width = curr_width;
        }

        column_widths[col] = max_width;
    }

    // Print column names
    for (const auto &col : column_names) {
        size_t this_col_width = column_widths[col];
        std::string formatted = std::format(" {} ", col);

        for (size_t i = 0; i < (this_col_width - col.size()); i++) {
            formatted += " ";
        }
        std::print("{}|", formatted);
    }
    std::println("");

    // Print separator
    for (const auto &col : column_names) {
        size_t this_col_width = column_widths[col];
        for (size_t i = 0; i < this_col_width + 2; i++) {
            std::print("-");
        }
        std::print("+");
    }
    std::println("");

    // Print row values
    for (const auto &row : table) {
        for (const auto &col : column_names) {
            size_t this_col_width = column_widths[col];
            std::string formatted = std::format(" {} ", row.at(col));

            for (size_t i = 0; i < (this_col_width - row.at(col).size()); i++) {
                formatted += " ";
            }
            std::print("{}|", formatted);
        }
        std::println("");
    }
}
