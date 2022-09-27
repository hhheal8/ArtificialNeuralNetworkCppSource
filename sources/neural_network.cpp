#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "neural_network.hpp"
#include "layer.hpp"
#include "matrix.hpp"
#include "multiply_matrix.hpp"

neural_network::neural_network(std::vector<size_t> require_topology): topology(require_topology) {

  for(size_t i{}; i < topology.size(); ++i) {

    layer *l = new layer(topology.at(i));

    layers.emplace_back(l);

    if(i == topology.size()) {
      dealloc_all(l);
    }

  }

  for(size_t i{}; i < (topology.size() - 1); ++i) {

    matrix *m = new matrix(topology.at(i), topology.at(i + 1), true);

    weight_matrices.emplace_back(m);

    if(i == topology.size()) {
      dealloc_all(m);
    } 

  }

}

auto neural_network::set_current_input(std::vector<double> require_input) -> void {

  input = require_input;

  for(size_t i{}; i < input.size(); ++i) {
    layers.at(0)->set_val(i, input.at(i));
  }

}

auto neural_network::feed_forward() -> void {

  for(size_t i{}; i < (layers.size() - 1); ++i) {

    matrix *a = get_neuron_matrix(i);

    if(i != 0) {
      a = get_activated_neuron_matrix(i);
    }

    matrix *b = get_weight_matrix(i);
    matrix *c = (new utils::multiply_matrix(a, b))->execute();

    std::vector<double> vals;

    for(size_t c_i{}; c_i < c->get_col_s(); ++c_i) {

      vals.emplace_back(c->get_val(0, c_i));

      set_neuron_val(i + 1, c_i, c->get_val(0, c_i));

      if(c_i == c->get_col_s()) {
        dealloc_all(c);
      }
      
    }

  }

}

matrix *neural_network::get_neuron_matrix(size_t index) {
  return layers.at(index)->matrixify_vals();
}

matrix *neural_network::get_activated_neuron_matrix(size_t index) {
  return layers.at(index)->matrixify_activated_vals();
}

matrix *neural_network::get_derived_neuron_matrix(size_t index) {
  return layers.at(index)->matrixify_derived_vals();
}

matrix *neural_network::get_weight_matrix(size_t index) {
  return weight_matrices.at(index);
}

auto neural_network::set_neuron_val(size_t index_l, size_t index_n, double val) -> void {
  layers.at(index_l)->set_val(index_n, val);
}

auto neural_network::display_result() -> void {

  for(size_t i{}; i < layers.size(); ++i) {

    std::cout << "LAYER: " << i << "\n";

    if(i == 0) {
      matrix *m = layers.at(i)->matrixify_vals();
      m->display_result(); 
    } 
    else {
      matrix *m = layers.at(i)->matrixify_activated_vals();
      m->display_result(); 
    }

    std::cout << "--------------------------------------------------------\n";

    if(i < layers.size() - 1) {
      std::cout << "Weight matrix: " << i << "\n";
      get_weight_matrix(i)->display_result();
    }

    std::cout << "--------------------------------------------------------\n";

  }

}

