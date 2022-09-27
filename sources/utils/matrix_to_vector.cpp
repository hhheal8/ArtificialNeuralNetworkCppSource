#include <iostream>
#include <vector>
#include <assert.h>

#include "matrix.hpp"
#include "matrix_to_vector.hpp"

utils::matrix_to_vector::matrix_to_vector(matrix *require_a): a(require_a) {}

auto utils::matrix_to_vector::execute() -> std::vector<double> {

  std::vector<double> result;

  for(size_t i{}; i < a->get_row_s(); ++i) {
    for(size_t j{}; j < a->get_row_s(); ++j) {
      result.emplace_back(a->get_val(i, j));
    }
  }

  return result;

}