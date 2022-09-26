#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "matrix.hpp"

matrix::matrix(size_t require_row_s, size_t require_col_s, bool require_is_random):
row_s(require_row_s), col_s(require_col_s), is_random(require_is_random) {

  for(size_t i{}; i < row_s; ++i) {

    std::vector<double> col_values;

    for(size_t j{}; j < col_s; ++j) {

      double r{};

      if(is_random) {
        r = gen_random_number();
      }

      col_values.emplace_back(r);

    }

    values.emplace_back(col_values);

  }

}

matrix *matrix::transpose() {

  matrix *m = new matrix(col_s, row_s, false);

  for(size_t i{}; i < row_s; ++i) {

    for(size_t j{}; j < col_s; ++j) {

      m->set_val(j, i, get_val(i, j));

    }

  }

  return m;

  delete m;
  m = nullptr;

}

auto matrix::set_val(size_t r, size_t c, double val) -> void {
  values.at(r).at(c) = val;
}

auto matrix::get_val(size_t r, size_t c) const -> double 
{
  return values.at(r).at(c);
}

auto matrix::get_row_s() const -> size_t {
  return row_s;
}

auto matrix::get_col_s() const -> size_t {
  return col_s;
}

auto matrix::gen_random_number() const -> double {
  
  // std::random_device rd;
  // std::mt19937 gen(rd());
  // std::uniform_real_distribution<> dis(0, 1);

  std::mt19937 gen(rand());
  std::uniform_real_distribution<> dis(0, 1);

  return dis(gen);
  
}

auto matrix::display_result() -> void {

  for(size_t i{}; i < row_s; ++i) {
    for(size_t j{}; j < col_s; ++j) {
      std::cout << values.at(i).at(j) << "\t\t";
    }
    std::cout << "\n";
  }

}