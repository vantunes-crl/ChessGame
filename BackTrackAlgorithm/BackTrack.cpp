#include "BackTrack.hpp"

std::list<Pos> BackTrack::BackTrackAvalPlacesList(const Pos &PiecesPos, Ichess_pieces::Table_t &Table)
{
    std::list<Pos> list;
    Ichess_pieces::Table_t CpyTable;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            CpyTable = Table;
            if (CpyTable[PiecesPos.x][PiecesPos.y]->play(CpyTable, Pos(i, j)) == 0)
                list.push_back(Pos(i, j));
        }
    }
    return list;
}

void BackTrack::BackTrackAvalPlacesPrint(const Pos &PiecesPos, Ichess_pieces::Table_t &Table)
{
    Ichess_pieces::Table_t CpyTable;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            CpyTable = Table;
            if (CpyTable[PiecesPos.x][PiecesPos.y]->play(CpyTable, Pos(i, j)) == 0)
                std::cout << "Can move to Pos: " << i << ":" << j << std::endl;
        }
    }
}

std::list<Pos> BackTrack::checkDiagonalTopLeft(Ichess_pieces::Table_t &Table, Pos StartPos)
{
    std::list<Pos> List;

    while (StartPos.x < 7 && StartPos.y < 7 && StartPos.x > 0 && StartPos.y > 0)
    {
        StartPos.x--;
        StartPos.y--;
        if (Table[StartPos.x][StartPos.y] != nullptr)
            List.push_back({StartPos.x, StartPos.y});
    }

    return List;
}

std::list<Pos> BackTrack::checkDiagonalTopRight(Ichess_pieces::Table_t &Table, Pos StartPos)
{
    std::list<Pos> List;

    while (StartPos.x < 7 && StartPos.y < 7 && StartPos.x > 0 && StartPos.y > 0)
    {
        StartPos.x--;
        StartPos.y++;
        if (Table[StartPos.x][StartPos.y] != nullptr)
            List.push_back({StartPos.x, StartPos.y});
    }

    return List;
}


std::list<Pos> BackTrack::checkDiagonalBottonLeft(Ichess_pieces::Table_t &Table, Pos StartPos)
{
    std::list<Pos> List;

    while (StartPos.x < 7 && StartPos.y < 7 && StartPos.x > 0 && StartPos.y > 0)
    {
        StartPos.x++;
        StartPos.y--;
        if (Table[StartPos.x][StartPos.y] != nullptr)
            List.push_back({StartPos.x, StartPos.y});
    }

    return List;
}

std::list<Pos> BackTrack::checkDiagonalBottonRight(Ichess_pieces::Table_t &Table, Pos StartPos)
{
    std::list<Pos> List;

    while (StartPos.x < 7 && StartPos.y < 7 && StartPos.x > 0 && StartPos.y > 0)
    {
        StartPos.x++;
        StartPos.y++;
        if (Table[StartPos.x][StartPos.y] != nullptr)
            List.push_back({StartPos.x, StartPos.y});
    }

    return List;
}