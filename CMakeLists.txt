cmake_minimum_required(VERSION 3.0.0)

project(
  ArtificialNeuralNetworkCpp VERSION 0.1.0 LANGUAGES CXX
)

add_executable(
  ArtificialNeuralNetworkCpp 
  main.cpp

  sources/layer.cpp
  sources/matrix.cpp
  sources/utils/matrix_to_vector.cpp
  sources/utils/multiply_matrix.cpp
  sources/neural_network.cpp
  sources/neuron.cpp
)

target_include_directories(
  ArtificialNeuralNetworkCpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes
  ArtificialNeuralNetworkCpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/utils
)
