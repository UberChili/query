// #include "bst.hpp"
#include <print>
#include <string>
#include <vector>

#include <CLI11.hpp>
#include <csv.hpp>
#include <filter.hpp>
#include <utils.hpp>

int main(int argc, char **argv) {
    // Getting command line arguments
    CLI::App app{"App description"};
    argv = app.ensure_utf8(argv);

    std::vector<std::string> select_columns;
    app.add_option("-s, --select", select_columns,
                   "Selection. Can be multiple columns.");

    std::string col_search = "";
    app.add_option("-w, --where", col_search, "Column name to search with.");

    std::string operation = "==";
    app.add_option("-o, --operation", operation, "Operation to search with.");

    std::string value = "";
    app.add_option("-v, --value ", value, "Value to filter with.");

    std::string colum_to_sort_by = "";
    app.add_option("--sort", colum_to_sort_by, "Column to sort by.");

    CLI11_PARSE(app, argc, argv);

    // First clear of screen
    // system("clear");

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

    // Filter specified columns
    auto results = filter(rows_v, select_columns, col_search, operation, value);
    sort_table(results, colum_to_sort_by);

    std::println("");
    print_table(results);


    return 0;
}
