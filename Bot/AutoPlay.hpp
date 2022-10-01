#pragma once

#include "../ChessDataConverter.hpp"
#include <iostream>

template <class Board>
class AutoPlay
{
    private:
        ChessDataConverter<Board> converter;
    public:
        void startPlay(std::string movesfile, Board &board);
 
};
