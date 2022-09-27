#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <math.h>
#include <random>
#include <vector>

class neuron {

  private:

    double val{}; 
    double activated_val{}; 
    double derived_val{}; 

  public:

    neuron(double require_val);

    auto set_val(double input_val) -> void; 

    auto get_val() const -> double; 
    auto get_activated_val() const -> double; 
    auto get_derived_val() const -> double; 

    //Fast Sigmoid Function
    //f(x) = x / (1 + |x|)
    auto activate() -> void; 

    //Derivative for Fast Sigmoid Function
    //f(x) = f(x) * (1 - f(x))
    auto derive() -> void; 

};

#endif // NEURON_H