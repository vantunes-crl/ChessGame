#include "MLP.hpp"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <array>
#include <math.h>
#include <map>

// MLPModel/
// MLPModel/
// MLPModel/
// MLPModel/
MLP::MLP():
_hiddenWeights(convertStringToMatrixDoubles(read_weights("MLPModel/weightsHidden.txt"))),
_outPutHeights(convertStringToMatrixDoubles(read_weights("MLPModel/weightsOutPut.txt"))),
_hiddenBias(convertStringToArrayDoubles(read_Bias_weights("MLPModel/weightsBiasHidden.txt"))),
_outputBias(convertStringToArrayDoubles(read_Bias_weights("MLPModel/weightsBiasOut.txt")))
{
    std::cout << _hiddenWeights.size() << _outPutHeights.size() << _hiddenBias.size() << _outputBias.size() << std::endl;
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

MLP MLP::getIstance()
{
    return *this;
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


std::vector<std::vector<float>> MLP::convertStringToMatrixDoubles(std::vector<std::string> vec)
{
    int count = 0;

    std::vector<std::vector<float>> finalVec;

    while (count < vec.size())
    {
        auto splitedStr = std::strtok(const_cast<char *>(vec[count].c_str()), " ");
        std::vector<float> temp;

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

std::vector<float> MLP::convertStringToArrayDoubles(std::string string)
{
    auto splitedStr = std::strtok(const_cast<char *>(string.c_str()), " ");
    std::vector<float> temp;

    while (splitedStr != NULL)
    {  
        temp.push_back(std::stod(splitedStr));
        
        splitedStr = std::strtok(NULL, " ");
    }

    return temp;
}

std::vector<float> MLP::sigmoid(const std::vector<float> matrix) 
{
    const unsigned long VECTOR_SIZE = matrix.size();
    std::vector<float> output (VECTOR_SIZE);
    
    for( unsigned i = 0; i != VECTOR_SIZE; ++i ) {
        output[ i ] = 1 / (1 + exp(-matrix[ i ]));
    }
    
    return output;
}

std::vector<std::string>  MLP::forward_propagation(const std::array<float, 64> input)
{
    std::vector<float> total;
    float result;
    for (short int i = 0; i < _hiddenWeights.size(); ++i)
    {
        result = 0.0;
        for (short int j = 0; j < 64; j++)
            result += input[j] * _hiddenWeights[j][i] + _hiddenBias[j];
        total.push_back(result);
    }

	auto finalClass = read_classes("MLPModel/classes.txt");
    
    std::vector<float> finalWeights;
    for (short int i = 0; i < finalClass.size(); ++i)
    {
        result = 0.0;
        for (short int j = 0; j < _hiddenWeights.size(); j++)
            result += total[j] * _outPutHeights[j][i] + _outputBias[j];
        finalWeights.push_back(result);
    }
 
	std::map<float, std::string> mp;
    for (int i = 0; i < finalClass.size(); ++i)
        mp.insert(std::make_pair(finalWeights[i], finalClass[i]));

    std::vector<std::string> finalList;
    for (auto i : mp)
        finalList.push_back(i.second);

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


// void plays_proba()
// // {

// // }


// int main()
// {
//     MLP mlp;

//     std::array<double, 64> test = {12,8,7,11,9,7,8,12,10,10,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,6,2,1,5,3,1,2,6};

//     // for (auto i : test)
//     //     std::cout << i << std::endl;
//     std::cout <<  "forward " << *mlp.forward_propagation(test).rbegin() << std::endl;


// }