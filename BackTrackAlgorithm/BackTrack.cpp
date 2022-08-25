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