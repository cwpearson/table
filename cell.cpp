#include "cell.hpp"

void Cell::set(int i) {
    reset();
    type_ = Type::INT;
    set<int>(i);
}

void Cell::set(double d) {
    reset();
    type_ = Type::DOUBLE;
    set<double>(d);
}

void Cell::set(const std::string &s) {
    reset();
    type_ = Type::STRING;
    set<std::string>(s);
}

void Cell::reset() {
    if (data_) {
        switch(type_) {
            case Type::DOUBLE: {
                delete reinterpret_cast<double*>(data_);
                break;
            }
            case Type::STRING: {
                delete reinterpret_cast<std::string*>(data_);
                break;
            }
            case Type::INT: {
                delete reinterpret_cast<int*>(data_);
                break;
            }
            assert(0 && "How did we get here");
        }
        data_ = nullptr;
    }
}

std::string Cell::str() const {
    if (data_) {
        switch(type_) {
            case Type::DOUBLE: {
                return std::to_string(*reinterpret_cast<double*>(data_));
            }
            case Type::STRING: {
                return *reinterpret_cast<std::string*>(data_);
            }
            case Type::INT: {
                return std::to_string(*reinterpret_cast<int*>(data_));
            }
            assert(0 && "How did we get here");
        }
    } else {
        return "";
    }
}