#include <memory>
#include <algorithm>
#include "table.hpp"
#include "ChessPieces/pawn.hpp"
#include "ChessPieces/bishop.hpp"
#include "ChessPieces/horse.hpp"
#include "ChessPieces/queen.hpp"
#include "ChessPieces/rook.hpp"
#include "ChessPieces/king.hpp"

std::list<Pos> BackTrackAvalPlaces(const Pos &PiecesPos, table<Ichess_pieces *> &Table)
{
    std::list<Pos> list;
    table<Ichess_pieces *> CpyTable;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            CpyTable = Table;
            if (CpyTable[PiecesPos.x][PiecesPos.y]->play(CpyTable, i, j) == 0)
                list.push_back(Pos(i, j));
        }
    }
    return list;
}

int main()
{
    table<Ichess_pieces *> Table;
    table<Ichess_pieces *> Table2;


    Table[0] = {new rook(0), new horse(0),nullptr,new queen(0),new king(0),new bishop(0),new horse(0),new rook(0)};
    Table[1] = {nullptr,     nullptr, new pawn(0), nullptr, new pawn(0), new pawn(0), new pawn(0), new pawn(0)};
    Table[2] = {nullptr,     new pawn(0),     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[3] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[4] = {nullptr,     nullptr,     new bishop(0),     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[5] = {nullptr,     nullptr,     nullptr,     new pawn(0),     nullptr,      nullptr,      nullptr,      nullptr};
    Table[6] = {new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1),new pawn(1)};
    Table[7] = {new rook(1), new horse(1),new bishop(1),new queen(1),new king(1),new bishop(1),new horse(1),new rook(1)};

    auto list = BackTrackAvalPlaces({4, 2}, Table);

    std::for_each(list.begin(), list.end(), [](auto &pos){ std::cout << pos.x << " " << pos.y << " " << std::endl; });


    Table.printTable();

}


