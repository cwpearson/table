#include "column.hpp"

Column::Column(Table &table, size_t cIdx) : table_(table), idx_(cIdx) {}

Cell &Column::cell(size_t rIdx) {
    return table_.cell(rIdx, idx_);
}