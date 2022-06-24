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
