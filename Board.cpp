#include "Board.hpp"

void Board::printTable()
{
    std::array<std::string, 13> Pieces = {
    "\033[1;32mempty\033[0m",
    "\033[1;39mBishop\033[0m", "\033[1;39mHorse\033[0m",
    "\033[1;39mKing\033[0m", "\033[1;39mPawn\033[0m",
    "\033[1;39mQueen\033[0m", "\033[1;39mRook\033[0m",
    "\033[1;30mBishop\033[0m", "\033[1;30mHorse\033[0m",
    "\033[1;30mKing\033[0m", "\033[1;30mPawn\033[0m",
    "\033[1;30mQueen\033[0m", "\033[1;30mRook\033[0m"
    };

    for (int i = 0; i < 64; ++i )
    {
        if (i % 8 == 0)
            std::cout << std::left << "\n--------------------------------------------------------------------------\n";
        std::cout << std::left << std::setw(20) << std::setfill(' ');
        if (PlayBoard[i])
            std::cout << Pieces[PlayBoard[i]->type()];
        else
            std::cout << "\033[1;32mempty\033[0m";   
    }
    std::cout << std::left << "\n--------------------------------------------------------------------------\n";
}

void Board::saveState(std::string move, std::string color, int playNumber)
{
    std::array<int, 64> encodedBoard {};
    for (int i = 0; i < 64; ++i)
    {
        if (PlayBoard[i])
            encodedBoard[i] = PlayBoard[i]->type();
        else
            encodedBoard[i] = 0;
    }

    std::ofstream file("DataChess.csv", std::ios_base::app);
    for (auto i = 0; i < 64; ++i){
        file << encodedBoard[i];
        if (i < 63)
            file << ',';
    }
    file << "\n";
    file.close();

    move.erase(std::remove(move.begin(), move.end(), 'x'), move.end());
    move.erase(std::remove(move.begin(), move.end(), '#'), move.end());
    move.erase(std::remove(move.begin(), move.end(), '+'), move.end());

    std::size_t end = move.find('=');
    if (end != std::string::npos)
        move = move.substr(0, end);


    std::ofstream file1("Target.csv", std::ios_base::app);
    file1 << move;
    file1 << "\n";
    file1.close();

}

std::array<double, 64> Board::read_state()
{
    std::array<double, 64> state {};

    for (int i = 0; i < 64; ++i)
    {
        if (PlayBoard[i])
            state[i] = PlayBoard[i]->type();
        else
            state[i] = 0;
    }

    return state;
}

std::unique_ptr<Ichess_pieces> &Board::operator[](const int i)
{ 
    return PlayBoard[i];
}


void Board::setMoveEvent(int move, bool doubleMove)
{
    LogsMove.push_back(std::make_pair(move, doubleMove));
}

std::pair<int, bool> Board::getLastEventMove()
{
    return LogsMove.back();
}