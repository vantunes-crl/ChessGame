#pragma once

#include <map>

template <class BoardMatrix>
class ChessDataConverter
{
    public:
        const std::pair<char, int> ConvertInput(const std::pair<int, int> &Move) const
        {
            return std::make_pair(Move.first + 'a', Move.second);
        }

        const std::pair<int, int> ConvertInput(const std::pair<char, int> &Move) const
        {
            return std::make_pair(Move.first - 'a', Move.second);
        }

        

        std::array<int, 64> MatrixToEncode(const BoardMatrix &Board);

        BoardMatrix EncodeToMatrix(const std::array<int, 64> &Board);

        

    private:



};

