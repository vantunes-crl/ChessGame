#include "BackTrack.hpp"

std::list<int> BackTrack::BackTrackAvalPlacesList(const int &PiecesPos, Ichess_pieces::Board_t &Board)
{
    std::list<int> list;
    Ichess_pieces::Board_t CpyBoard;

    // for (int i = 0; i < 8; ++i)
    // {
    //     for (int j = 0; j < 8; ++j)
    //     {
    //         CpyBoard = Board;
    //         if (CpyBoard[Piecesint.x][Piecesint.y]->play(CpyBoard, int(i, j)) == 0)
    //             list.push_back(int(i, j));
    //     }
    // }
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

std::list<int> BackTrack::checkDiagonal(Ichess_pieces::Board_t &Board, int Startint, const DIAGONAL_CHECK_CASE CASE)
{
    std::list<int> List;
    // while (true)
    // {
    //     switch (CASE)
    //     {
    //     case DIAGONAL_TOP_LEFT:
    //         Startint.x--;
    //         Startint.y--;
    //         break;
    //     case DIAGONAL_TOP_RIGHT:
    //         Startint.x--;
    //         Startint.y++;
    //         break;
    //     case DIAGONAL_BOTTOM_LEFT:
    //         Startint.x++;
    //         Startint.y--;
    //         break;
    //     case DIAGONAL_BOTTOM_RIGHT:
    //         Startint.x++;
    //         Startint.y++;
    //         break;
    //     }
    //     if (Startint.x > 7 || Startint.y > 7 || Startint.x < 0 || Startint.y < 0)
    //         break;
    //     else
    //         List.push_back({Startint.x, Startint.y});
    //     if (Board[Startint.x][Startint.y] != nullptr)
    //         break;
    // }
    return List;
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



std::list<int> BackTrack::checkHorizontal(Ichess_pieces::Board_t &Board, int Startint, const HORIZONTAL_CHECK_CASE CASE)
{
    std::list<int> List;

    // while (true)
    // {
    //     switch (CASE)
    //     {
    //     case HORIZONTAL_LEFT:
    //         Startint.y--;
    //         break;
    //     case HORIZONTAL_RIGHT:
    //         Startint.y++;
    //         break;
    //     }
    //     if (Startint.y > 7 || Startint.y < 0)
    //         break;
    //     else
    //         List.push_back({Startint.x, Startint.y});
    //     if (Board[Startint.x][Startint.y] != nullptr)
    //         break;
    // }
    
    return List;
}


std::list<int> BackTrack::checkVertical(Ichess_pieces::Board_t &Board, int Startint, const VERTICAL_CHECK_CASE CASE)
{
    std::list<int> List;

    // while (true)
    // {
    //     switch (CASE)
    //     {
    //     case VERTICAL_BOTTOM:
    //         Startint.x--;
    //         break;
    //     case VERTICAL_TOP:
    //         Startint.x++;
    //         break;
    //     }
    //     if (Startint.x > 7 || Startint.x < 0)
    //         break;
    //     else
    //         List.push_back({Startint.x, Startint.y});
    //     if (Board[Startint.x][Startint.y] != nullptr)
    //         break;
    // }

    return List;
}