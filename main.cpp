#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "layer.hpp"
#include "matrix.hpp"
#include "neural_network.hpp"
#include "neuron.hpp"

auto main() -> int {

  neuron *test1 = new neuron(1.5);

  std::cout << "Value of `double val` is " << test1->get_val() << std::endl;
  std::cout << "Value of `double activated_val` is " << test1->get_activated_val() << std::endl;
  std::cout << "Value of `double derived_val` is " << test1->get_derived_val() << std::endl;

  // dealloc_all(test1);

  srand(time(nullptr));

  matrix *m = new matrix(3, 2, true);

  m->display_result();

  std::cout << "--------------------------------------------\n";

  matrix *m2 = m->transpose();

  m2->display_result();

  // dealloc_all(m);

  std::vector<int> topology;

  topology.emplace_back(3);
  topology.emplace_back(2);
  topology.emplace_back(3);

  std::vector<double> input;

  input.emplace_back(1.0);
  input.emplace_back(0.0);
  input.emplace_back(1.0);

  neural_network *nn = new neural_network(topology);

  nn->set_current_input(input);

  nn->display_result();

  dealloc_all(test1, m, nn);

}