#ifndef FILTER_H
#define FILTER_H

#include <map>
#include <string>
#include <vector>

struct IrisRow {
    std::string sepal_length, sepal_width, petal_length, petal_width, species;
};

std::string get_column_value(const IrisRow& row, const std::string& column);

std::vector<std::map<std::string, std::string>>
filter(const std::vector<IrisRow> &rows, const std::vector<std::string> &columns, std::string test, const std::string &operation, const std::string &value);

#endif