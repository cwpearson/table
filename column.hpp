#ifndef COLUMN_HPP
#define COLUMN_HPP

#include "cell.hpp"
#include "table.hpp"

class Column {
    friend Table;
    Cell &cell(size_t rIdx);
private:
    Column(Table &table, size_t cIdx);
    size_t idx_;
    Table &table_;
};

#endif