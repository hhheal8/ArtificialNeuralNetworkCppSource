#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "layer.hpp"
#include "matrix.hpp"
#include "multiply_matrix.hpp"

class layer;
class matrix;

class neural_network {

  private:

    const std::vector<size_t> topology;

    std::vector<layer*> layers;
    std::vector<matrix*> weight_matrices;

    std::vector<double> input;

  public:

    neural_network(std::vector<size_t> require_topology);

    auto set_current_input(std::vector<double> require_input) -> void;
    
    auto feed_forward() -> void;

    matrix *get_neuron_matrix(size_t index);
    matrix *get_activated_neuron_matrix(size_t index);
    matrix *get_derived_neuron_matrix(size_t index);
    matrix *get_weight_matrix(size_t index);

    auto set_neuron_val(size_t index_l, size_t index_n, double val) -> void;

    auto display_result() -> void;

};

#endif // NEURAL_NETWORK_H