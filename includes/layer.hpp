#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "neuron.hpp"
#include "matrix.hpp"

class neuron;
class matrix;

class layer {

  private: 

    const size_t size{};

    std::vector<neuron*> neurons;

  public:

    layer(size_t require_size);

    auto set_val(size_t i, double val) -> void;
    
    matrix *matrixify_vals();
    matrix *matrixify_activated_vals(); 
    matrix *matrixify_derived_vals(); 

};

#endif // LAYER_H