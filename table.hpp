#ifndef TABLE_HPP
#define TABLE_HPP

#include <cstdlib>
#include <map>

#include "column.hpp"
#include "cell.hpp"
#include "row.hpp"


class Table {
public:
    size_t num_rows() const;
    size_t num_cols() const;

    Cell &cell(size_t rowIdx, size_t colIdx);
    Row &row(const size_t idx);
    Column &column(const size_t idx);
    
private:
    std::map<size_t, std::map<size_t, Cell>> data_;

};

#endif