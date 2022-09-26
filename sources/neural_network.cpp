#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "neural_network.hpp"
#include "layer.hpp"
#include "matrix.hpp"

neural_network::neural_network(std::vector<int> require_topology): topology(require_topology) {

  topology_s = topology.size();

  for(size_t i{}; i < topology_s; ++i) {

    layer *l = new layer(topology.at(i));

    layers.emplace_back(l);

    if(i == topology_s) {
      delete l;
      l = nullptr;
    }

  }

  for(size_t i{}; i < (topology_s - 1); ++i) {

    matrix *m = new matrix(topology.at(i), topology.at(i + 1), true);

    weight_matrices.emplace_back(m);

    if(i == topology_s) {
      delete m;
      m = nullptr;
    } 

  }

}

auto neural_network::set_current_input(std::vector<double> require_input) -> void {

  input = require_input;

  for(size_t i{}; i < input.size(); ++i) {
    layers.at(0)->set_val(i, input.at(i));
  }

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

  }

}