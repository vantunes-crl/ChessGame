#include "BackTrack.hpp"

std::list<int> BackTrack::BackTrackAvalPlacesList(const int &PiecesPos, Ichess_pieces::Board_t &Board)
{
    std::list<int> list;
    Ichess_pieces::Board_t CpyBoard;

    if (!Board[PiecesPos])
        return list;

    for (int i = 0; i < 64; ++i)
    {
        CpyBoard = Board;
        if (CpyBoard[PiecesPos]->play(CpyBoard, i) == 0)
            list.push_back(i);
    }
    return list;
}

void BackTrack::BackTrackAvalPlacesPrint(const int &PiecesPos, Ichess_pieces::Board_t &Board)
{
    Ichess_pieces::Board_t CpyBoard;

   
    for (int i = 0; i < 64; ++i)
    {
        CpyBoard = Board;
        if (CpyBoard[PiecesPos]->play(CpyBoard, i) == 0)
            std::cout << "Can move to int: " << i << std::endl;
        
    }
}

void BackTrack::AvalMoves(int steps, EDGES Edge, int pos, Ichess_pieces::Board_t &Board, std::list<int> &moves)
{
    std::array<std::array<int, 8>, 4> All_Edges = {{
        {0,1,2,3,4,5,6,7},
        {56,57,58,59,60,61,62,63},
        {0,8,16,24,32,40,48,56},
        {7,15,23,31,39,47,55,63},
    }};

    while (true)
    {
        if (std::find(All_Edges[Edge].begin(), All_Edges[Edge].end(), pos) != All_Edges[Edge].end())
            break;
        pos += steps;
        if (pos > 63 || pos < 0)
            break;
        moves.push_back(pos);
        if (Board[pos])
            break;
    }
}