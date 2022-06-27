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

std::list<Pos> BackTrack::checkDiagonal(Ichess_pieces::Table_t &Table, Pos StartPos, const DIAGONAL_CHECK_CASE CASE)
{
    std::list<Pos> List;

    while (StartPos.x < 7 && StartPos.y < 7 && StartPos.x > 0 && StartPos.y > 0)
    {
        switch (CASE)
        {
        case DIAGONAL_TOP_LEFT:
            StartPos.x--;
            StartPos.y--;
        case DIAGONAL_TOP_RIGHT:
            StartPos.x--;
            StartPos.y++;
        case DIAGONAL_BOTTOM_LEFT:
            StartPos.x++;
            StartPos.y--;
        case DIAGONAL_BOTTOM_RIGHT:
            StartPos.x++;
            StartPos.y++;
        }
        if (Table[StartPos.x][StartPos.y] != nullptr)
            List.push_back({StartPos.x, StartPos.y});
    }

    return List;
}



std::list<Pos> BackTrack::checkHorizontal(Ichess_pieces::Table_t &Table, Pos StartPos, const HORIZONTAL_CHECK_CASE CASE)
{
    std::list<Pos> List;

    while (StartPos.y < 7 && StartPos.y > 0)
    {
        switch (CASE)
        {
        case HORIZONTAL_LEFT:
            StartPos.y--;
        case HORIZONTAL_RIGHT:
            StartPos.y++;
        }
        if (Table[StartPos.x][StartPos.y] != nullptr)
            List.push_back({StartPos.x, StartPos.y});
    }

    return List;
}


std::list<Pos> BackTrack::checkVertical(Ichess_pieces::Table_t &Table, Pos StartPos, const VERTICAL_CHECK_CASE CASE)
{

    std::list<Pos> List;

    while (StartPos.x < 7 && StartPos.x > 0)
    {
        switch (CASE)
        {
        case VERTICAL_BOTTOM:
            StartPos.x--;
        case VERTICAL_TOP:
            StartPos.y++;
        }
        if (Table[StartPos.x][StartPos.y] != nullptr)
            List.push_back({StartPos.x, StartPos.y});
    }

    return List;

}