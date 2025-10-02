#ifndef FILTER_H
#define FILTER_H

#include <stdexcept>

struct IrisRow {
    std::string sepal_length, sepal_width, petal_length, petal_width, species;
};


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
            matches = (column_value == value);
        }
        else if (operation == ">" || operation == "<") {
            try {
                float value_f = std::stof(value);
                float column_f = std::stof(column_value);

                if (operation == ">") {
                    matches = (column_f > value_f);
                } else {
                    matches = (column_f < value_f);
                }
            } catch (std::invalid_argument&) {
                // skip this row if conversion fails
                continue;
            }

        }

        if (matches)
            results.push_back(row);
    }

    return results;
}

#endif
