#pragma once

#include "../ChessDataConverter.hpp"
#include <iostream>

template <class Board>
class AutoPlay
{
    private:
        ChessDataConverter<Board> converter;
    public:
        void startPlay(std::string movesfile, Board &board)
        {
            auto vec = converter.parseMovesFile(movesfile);
            auto plays = converter.parseMoves(vec[0]);

            for (auto it = plays.begin(); it != plays.end(); ++it)
            {
                std::cout << it->BlackPlay << std::endl;
            }

        }
 
};
