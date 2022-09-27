#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "layer.hpp"
#include "neuron.hpp"
#include "matrix.hpp"

layer::layer(size_t require_size): size(require_size) {

  for(size_t i{}; i < size; ++i) {

    neuron *n = new neuron(0.00);

    neurons.emplace_back(n);

    if(i == size) {
      dealloc_all(n);
    }

  }

}

auto layer::set_val(size_t i, double val) -> void {
  neurons.at(i)->set_val(val);
}

matrix *layer::matrixify_vals() {
  
  matrix *m1 = new matrix(1, neurons.size(), false);

  for(size_t i{}; i < neurons.size(); ++i) {
    m1->set_val(0, i, neurons.at(i)->get_val());
    // if(i == neurons.size()) {
    //   dealloc_all(m1);
    // }
  }

  return m1;

  // dealloc_all(m1);


}

matrix *layer::matrixify_activated_vals() {

  matrix *m2 = new matrix(1, neurons.size(), false);

  for(size_t i{}; i < neurons.size(); ++i) {
    m2->set_val(0, i, neurons.at(i)->get_activated_val());
    // if(i == neurons.size()) {
    //   dealloc_all(m2);
    // }
  }

  return m2;

  // dealloc_all(m2);

}

matrix *layer::matrixify_derived_vals() {

  matrix *m3 = new matrix(1, neurons.size(), false);

  for(size_t i{}; i < neurons.size(); ++i) {
    m3->set_val(0, i, neurons.at(i)->get_derived_val());
    // if(i == neurons.size()) {
    //   dealloc_all(m3);
    // }
  }

  return m3;

  // dealloc_all(m3);

}