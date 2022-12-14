#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "layer.hpp"
#include "matrix.hpp"
#include "multiply_matrix.hpp"
#include "neural_network.hpp"
#include "neuron.hpp"

auto main() -> int {

  srand(time(nullptr));

  // neuron *test1 = new neuron(1.5);

  // std::cout << "Value of `double val` is " << test1->get_val() << std::endl;
  // std::cout << "Value of `double activated_val` is " << test1->get_activated_val() << std::endl;
  // std::cout << "Value of `double derived_val` is " << test1->get_derived_val() << std::endl;

  // // dealloc_all(test1);


  // matrix *m = new matrix(3, 2, true);

  // m->display_result();

  // std::cout << "--------------------------------------------\n";

  // matrix *m2 = m->transpose();

  // m2->display_result();

  // // dealloc_all(m);

  // std::vector<size_t> topology;

  // topology.emplace_back(3);
  // topology.emplace_back(2);
  // topology.emplace_back(3);

  // std::vector<double> input;

  // input.emplace_back(1.0);
  // input.emplace_back(0.0);
  // input.emplace_back(1.0);

  // neural_network *nn = new neural_network(topology);

  // nn->set_current_input(input);

  // nn->display_result();

  std::vector<double> input;

  input.emplace_back(1);
  input.emplace_back(0);
  input.emplace_back(1);

  std::vector<size_t> topology;

  topology.emplace_back(3);
  topology.emplace_back(2);
  topology.emplace_back(1);

  neural_network *nn2 = new neural_network(topology);

  nn2->set_current_input(input);
  nn2->set_current_target(input);

  nn2->feed_forward();

  nn2->set_errors();

  nn2->display_result();

  std::cout << "Total Error: " << nn2->get_total_errors() << "\n";

  dealloc_all(nn2);
  // dealloc_all(test1, m, nn, nn2);

}