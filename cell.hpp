#ifndef CELL_HPP
#define CELL_HPP

#include <string>
#include <memory>
#include <cassert>

#include "type.hpp"

class Cell {
    Cell(const Type &type) : data_(nullptr), type_(type) {}
    
    void set(double d);
    void set(int i);
    void set(const std::string &s);
    
    std::string str() const;

private:
    template<typename T> void set(const T& val) {
        assert(nullptr == data_);
        data_ = new T;
        *reinterpret_cast<T*>(data_) = val;
    }

    void reset();

    void *data_;
    Type type_;
};

#endif