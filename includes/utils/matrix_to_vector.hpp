#ifndef MATRIX_TO_VECTOR_H
#define MATRIX_TO_VECTOR_H

#include <iostream>
#include <vector>
#include <assert.h>

#include "matrix.hpp"

class matrix;

namespace utils {

  class matrix_to_vector {

    private:

      const matrix *a;

    public:

      matrix_to_vector(matrix *require_a);

      auto execute() -> std::vector<double>;

  };

}

#endif // MATRIX_TO_VECTOR_H