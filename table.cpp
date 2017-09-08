#include "table.hpp"

Column &Table::column(const size_t cIdx) {
    return Column(*this, cIdx);
}