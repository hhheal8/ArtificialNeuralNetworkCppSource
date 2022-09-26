#include <iostream>
#include <math.h>
#include <random>
#include <vector>

#include "dealloc_all.hpp"
#include "neuron.hpp"

neuron::neuron(double require_val): val(require_val) {
  activate(); 
  derive(); 
}

auto neuron::set_val(double input_val) -> void {
  val = input_val;
  activate(); 
  derive();
}

auto neuron::get_val() const -> double { 
  return val; 
}

auto neuron::get_activated_val() const -> double { 
  return activated_val; 
}

auto neuron::get_derived_val() const -> double { 
  return derived_val; 
}

auto neuron::activate() -> void {
  activated_val = val / (1 + std::abs(val));
}

auto neuron::derive() -> void {
  derived_val = activated_val * (1 - activated_val);
}