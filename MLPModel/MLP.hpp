
#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <array>

class MLP
{
private:
    std::vector<std::vector<double>> _hiddenWeights;
    std::vector<std::vector<double>> _outPutHeights;
    std::vector<double> _hiddenBias;
    std::vector<double> _outputBias;
    size_t _hidden_layer_neuros_size;
    size_t _features_size;
    size_t _output_size;


public:
    MLP();
    ~MLP();

    MLP getIstance();
    
    std::vector<std::vector<double>> read_weights(const std::string movesFile);
    std::vector<double> read_Bias_weights(const std::string movesFile);
    std::vector<std::string> forward_propagation(std::array<double, 64> input);
    std::vector<std::string> read_classes(const std::string movesFile);
    double sigmoid (double value);
    void Relu(std::vector<double> &vec);
};