#ifndef MULTIPLY_MATRIX_H
#define MULTIPLY_MATRIX_H

#include <iostream>
#include <vector>
#include <assert.h>

#include "dealloc_all.hpp"
#include "matrix.hpp"

class matrix;

namespace utils {

  class multiply_matrix {

    private:

      const matrix *a;
      const matrix *b;
      matrix *c;

    public:

      multiply_matrix(matrix *require_a, matrix *require_b);

      matrix *execute();

  };

}

#endif // MULTIPLY_MATRIX_H