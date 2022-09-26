#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "layer.hpp"
#include "matrix.hpp"

class layer;
class matrix;

class neural_network {

  private:

    size_t topology_s;
    const std::vector<int> topology;

    std::vector<layer*> layers;
    std::vector<matrix*> weight_matrices;

    std::vector<double> input;

  public:

    neural_network(std::vector<int> require_topology);

    auto set_current_input(std::vector<double> require_input) -> void;

    auto display_result() -> void;

};

#endif // NEURAL_NETWORK_H