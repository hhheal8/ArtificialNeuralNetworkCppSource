#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"

class matrix {

  private:

    const size_t row_s{}; 
    const size_t col_s{};
    bool is_random{};
    
    std::vector<std::vector<double>> values;

  public:

    matrix(size_t require_row_s, size_t require_col_s, bool require_is_random);

    matrix *transpose(); 

    auto set_val(size_t r, size_t c, double val) -> void;

    auto get_val(size_t r, size_t c) const -> double;

    auto get_row_s() const -> size_t;
    auto get_col_s() const -> size_t;

    auto gen_random_number() const -> double;

    auto display_result() -> void;

};

#endif // MATRIX_H