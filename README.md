# Query
Trying to implement a **local query engine** as a learning exercise

# Requirements included as headers
- CSV Parser library by Ben Strasser.
- CLI11

# What currently works
- Reading a CSV file into memory
- Parsing each row splitting its values
- ~~Querying or filtering rows by a search term, currently only by species~~
- Querying or filtering rows by a **selection** of columns and a condition 
- Pretty printing tables
- Basic user input via command line arguments. User can select the columns they want, the value to search with and the colum to filter with, with an SQL-like syntax, but as command line arguments:


# Working on
- Maybe trying to improve or re-implement how we work with the command line arguments