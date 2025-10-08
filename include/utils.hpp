
#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <vector>
#include <string>

// Sorts the rows of a table
void sort_table(std::vector<std::map<std::string, std::string>> &table, std::string &column);

// Pretty prints a table
void print_table(std::vector<std::map<std::string, std::string>> &table);

#endif

