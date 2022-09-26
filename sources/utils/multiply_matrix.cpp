#include <iostream>
#include <vector>
#include <assert.h>

#include "dealloc_all.hpp"
#include "matrix.hpp"
#include "multiply_matrix.hpp"

utils::multiply_matrix::multiply_matrix(matrix *require_a, matrix *require_b)
: a(require_a), b(require_b) {
  
  if(a->get_col_s() != b->get_row_s()) {
    std::cerr << "A_rows: " << a->get_row_s() << " != B_cols: " << b->get_col_s() << "\n";
    assert(false);
  }

  c = new matrix(a->get_row_s(), b->get_col_s(), false);

  dealloc_all(c);

}

matrix *utils::multiply_matrix::execute() {

  for(size_t i{}; i < a->get_row_s(); ++i) {
    for(size_t j{}; j < b->get_col_s(); ++j) {
      for(size_t k{}; k < b->get_row_s(); ++k) {
        double p = a->get_val(i, k) * b->get_val(k, j);
        double new_val = c->get_val(i, j) + p;
        c->set_val(i, j, new_val);
      }
    }
  }

}