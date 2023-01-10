
#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <array>

class MLP
{
private:
    std::vector<std::vector<float>> _hiddenWeights;
    std::vector<std::vector<float>> _outPutHeights;
    std::vector<float> _hiddenBias;
    std::vector<float> _outputBias;

public:
    MLP();
    ~MLP();

    MLP getIstance();

    std::vector<std::vector<float>> convertStringToMatrixDoubles(std::vector<std::string> vec);
    std::vector<float> convertStringToArrayDoubles(std::string string);
    
    std::vector<std::string> read_weights(const std::string movesFile);
    std::string read_Bias_weights(const std::string movesFile);
    std::vector<std::string> forward_propagation(std::array<float, 64> input);
    std::vector<std::string> read_classes(const std::string movesFile);
    std::vector<float> sigmoid (const std::vector<float> matrix);
};