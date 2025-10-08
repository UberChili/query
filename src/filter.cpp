#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "filter.hpp"

std::string get_column_value(const IrisRow &row, const std::string &column) {
    if (column == "sepal_length")
        return row.sepal_length;
    if (column == "sepal_width")
        return row.sepal_width;
    if (column == "petal_length")
        return row.petal_length;
    if (column == "petal_width")
        return row.petal_width;
    if (column == "species")
        return row.species;

    return "";
}

std::vector<std::map<std::string, std::string>>
filter(const std::vector<IrisRow> &rows,
       const std::vector<std::string> &columns,
       const std::string test,
       const std::string &operation,
       const std::string &value) {
    std::vector<std::map<std::string, std::string>> results;
    
    // Loop through every row
    for (const auto &row : rows) {
        // Extracting the value we need to test with
        std::string test_value = get_column_value(row, test);
        bool matches = false;
        
        if (operation == "==") 
            matches = (test_value == value);
        else if (operation == ">" || operation == "<") {
            try {
                float value_f = std::stof(value);
                float test_f = std::stof(test_value);
                
                if (operation == ">") {
                    matches = (test_f > value_f);
                } else {
                    matches = (test_f < value_f);
                }
            } catch (std::invalid_argument&) {
                // Skip this row if conversion fails
                continue;
            }
        }
        
        // If we found a matching row, we need to get only the columns we want to return
        // (the ones specified by the columns argument)
        if (matches) {
            std::map<std::string, std::string> result_row;
            
            for (const auto &col : columns) {
                // Here, the get_column_value function is handy again
                std::string col_val = get_column_value(row, col);
                result_row[col] = col_val;
            }
            
            results.push_back(result_row);
        }
    }

    return results;
}
