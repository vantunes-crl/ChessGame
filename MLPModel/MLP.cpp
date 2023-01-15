#include "MLP.hpp"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <array>
#include <math.h>
#include <map>


MLP::MLP():
_hiddenWeights(read_weights("MLPModel/weightsHidden.txt")),
_outPutHeights(read_weights("MLPModel/weightsOut.txt")),
_hiddenBias(read_Bias_weights("MLPModel/weightsBiasHidden.txt")),
_outputBias(read_Bias_weights("MLPModel/weightsBiasOut.txt"))
{
    _hidden_layer_neuros_size = _hiddenWeights[0].size();
    _features_size = _hiddenWeights.size();
    _output_size = _outputBias.size();
    std::cout << _hiddenWeights.size() << " " << _outPutHeights.size() << " " << _hiddenBias.size() << " " << _outputBias.size() << std::endl;
}

MLP::~MLP()
{}

std::vector<std::vector<double>> MLP::read_weights(const std::string movesFile)
{

    std::fstream file(movesFile);
    std::string buff;
    std::vector<double> vec;
    std::vector<std::vector<double>> matrix;
    char c;

    if (!file)
        std::cout << "file not open\n";
    int count = 0;
    while (file >> std::noskipws >> c)
    {
        buff += c;
        if (c == ',')
        {
            buff.erase(std::remove(buff.begin(), buff.end(), ','), buff.end());
            vec.push_back(std::stod(buff));
            buff.erase(buff.begin(), buff.end());
        }
        if (c == '\n')
        {
            vec.push_back(std::stod(buff));
            matrix.push_back(vec);
            vec.erase(vec.begin(), vec.end());
        }
    }

    return matrix;
}

MLP MLP::getIstance()
{
    return *this;
}

std::vector<double> MLP::read_Bias_weights(const std::string movesFile)
{
    std::fstream file(movesFile);
    std::string buff;
    std::vector<double> temp;

    while (std::getline(file, buff))
        temp.push_back(std::stod(buff));

    return temp;
}

double MLP::sigmoid(double value) 
{
    return 1 / (1 + exp(value));
}

void MLP::Relu(std::vector<double> &vec)
{   
    std::transform(vec.begin(), vec.end(), vec.begin(), [](float x) {
                    if (x < 0.f)
                        return 0.f;
                    return x;
                });
}

std::vector<std::string> MLP::forward_propagation(const std::array<double, 64> input)
{
    auto finalClass = read_classes("MLPModel/classes.txt");
    std::vector<double> vec;

    //forward hidden layer
    double result;
    for (int i = 0; i < _hidden_layer_neuros_size; ++i)
    {
        result = 0.0;
        for (int j = 0; j < _features_size; ++j)
            result += (input[j] * _hiddenWeights[j][i]);
        vec.push_back(result + _hiddenBias[i]);
    }

     //use relu on the first outputs
    Relu(vec);

    //Forward output layer
    std::vector<double> finalWeights;
    for (int i = 0; i < _output_size; ++i)
    {
        result = 0.0;
        for (int j = 0; j < _hidden_layer_neuros_size; ++j)
            result += (vec[j] * _outPutHeights[j][i]);
        finalWeights.push_back(result + _outputBias[i]);
    }

    //Organize by size of the neurons
	std::map<double, std::string> mp;
    for (int i = 0; i < finalClass.size(); ++i)
        mp.insert(std::make_pair(finalWeights[i], finalClass[i]));

    //return a list of plays organized
    std::vector<std::string> finalList;
    for (auto i : mp)
    {
        i.second.erase(std::remove(i.second.begin(), i.second.end(), ' '), i.second.end());
        finalList.push_back(i.second);
    }        

    return finalList;

}

std::vector<std::string> MLP::read_classes(const std::string movesFile)
{
    std::fstream file(movesFile);
    std::string buff;
    std::vector<std::string> vec;
    char c;

    while (file >> std::noskipws >> c)
    {
        buff += c;
        if (c == ' ')
        {
            vec.push_back(buff);
			buff.clear();
        }
    }

    return vec;
}