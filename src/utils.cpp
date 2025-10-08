#include <algorithm>
#include <cstring>
#include <format>
#include <map>
#include <print>
#include <string>
#include <vector>

void print_table(std::vector<std::map<std::string, std::string>>& table) {
    std::vector<std::string> column_names;
    
    // Getting column names
    for (const auto &[k, v] : table[0]) {
        column_names.push_back(k);
    }
    // Getting column width
    // This is wrong, or incomplete
    size_t col_width = std::strlen(std::max_element(column_names.begin(), column_names.end())->data());
    

    // print header row
    for (auto it = column_names.begin(); it == column_names.end(); it++) {
        // print last column name
        if (it == column_names.end()) {
            std::println(" {}", it->data());
            break;
        }

        // print normal column names
        std::string col = std::format(" {}", it->data());
        for (size_t i = 0; i < col_width; i++) {

        }
    }
}