#include "MLP.hpp"
#include <iostream>
#include <algorithm>
#include <cstring>

MLP::MLP()
{
    _hiddenWeights = convertStringToMatrixDoubles(read_weights("weightsHidden.txt"));
    _outPutHeights = convertStringToMatrixDoubles(read_weights("weightsOutPut.txt"));
    _hiddenBias = convertStringToArrayDoubles(read_Bias_weights("weightsBiasHidden.txt"));
    _outputBias = convertStringToArrayDoubles(read_Bias_weights("weightsBiasOut.txt"));
}

MLP::~MLP()
{}

std::vector<std::string> MLP::read_weights(const std::string movesFile)
{
    std::fstream file(movesFile);
    std::string buff;
    std::vector<std::string> vec;
    char c;

    while (file >> std::noskipws >> c)
    {
        buff += c;
        if (c == ']')
        {
            buff.erase(std::remove(buff.begin(), buff.end(), '['), buff.end());
            buff.erase(std::remove(buff.begin(), buff.end(), ']'), buff.end());
            vec.push_back(buff);
            buff.erase(buff.begin(), buff.end());
        }
    }

    return vec;
}


std::string MLP::read_Bias_weights(const std::string movesFile)
{
    std::fstream file(movesFile);
    std::string buff;
    std::string str;

    while (std::getline(file, buff))
        str += buff;

    return str;
}


std::vector<std::vector<double>> MLP::convertStringToMatrixDoubles(std::vector<std::string> vec)
{
    int count = 0;

    std::vector<std::vector<double>> finalVec;

    while (count < vec.size())
    {
        auto splitedStr = std::strtok(const_cast<char *>(vec[count].c_str()), " ");
        std::vector<double> temp;

        while (splitedStr != NULL)
        {  
            try
            {
                temp.push_back(std::stod(splitedStr));
            }
            catch (std::invalid_argument)
            {}
            
            splitedStr = std::strtok(NULL, " ");
        }

        finalVec.push_back(temp);
        temp.erase(temp.begin(), temp.end());
        count++;
    }
    return finalVec;
    
}

std::vector<double> MLP::convertStringToArrayDoubles(std::string string)
{
    auto splitedStr = std::strtok(const_cast<char *>(string.c_str()), " ");
    std::vector<double> temp;

    while (splitedStr != NULL)
    {  
        temp.push_back(std::stod(splitedStr));
        
        splitedStr = std::strtok(NULL, " ");
    }

    return temp;
}


std::string MLP::forward_propagation(const double input[64])
{
    std::vector<double> total;
    float result;
    for (short int i = 0; i < _hiddenWeights.size(); ++i)
    {
        result = 0.0;
        for (short int j = 0; j < 64; j++)
            result += input[j] * _hiddenWeights[j][i] + _hiddenBias[j];
        total.push_back(result);
    }


    std::vector<double> finalWeights;
    for (short int i = 0; i < 19; ++i)
    {
        result = 0.0;
        for (short int j = 0; j < _hiddenWeights.size(); j++)
            result += total[j] * _outPutHeights[j][i] + _outputBias[j];
        finalWeights.push_back(result);
    }

    std::string finalClass[19] = {"Bb5","Be2","Be3","Nc3","Ne5","Nf3","O-O","Ra2","Ra5","a3","a4","a5","bc3","c4","cd5","d4","de5","e3","e4"};
    
    auto elem = std::max_element(finalWeights.begin(), finalWeights.end());
    return finalClass[std::distance(finalWeights.begin(), elem)];

}

int main()
{
    MLP mlp;

    const double test[64] = {12,0,0,0,0,12,9,0,0,10,10,0,7,10,10,10,10,0,8,0,10,0,0,0,0,0,0,0,0,11,0,0,0,0,0,4,7,0,0,0,4,0,4,0,1,2,0,0,0,0,0,0,1,4,4,4,6,0,0,5,0,6,3,0};

    std::cout << mlp.forward_propagation(test) << std::endl;

}