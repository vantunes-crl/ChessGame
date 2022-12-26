
#include <string>
#include <fstream>
#include <vector>

class MLP
{
private:
    std::vector<std::vector<double>> _hiddenWeights;
    std::vector<std::vector<double>> _outPutHeights;
    std::vector<double> _hiddenBias;
    std::vector<double> _outputBias;
public:
    MLP(/* args */);
    ~MLP();

    std::vector<std::vector<double>> convertStringToMatrixDoubles(std::vector<std::string> vec);
    std::vector<double> convertStringToArrayDoubles(std::string string);
    
    std::vector<std::string> read_weights(const std::string movesFile);
    std::string read_Bias_weights(const std::string movesFile);

    std::string forward_propagation(const double input[64]);
};