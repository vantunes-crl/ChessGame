#include <memory>
#include <algorithm>
#include "table.hpp"
#include "ChessPieces/pawn.hpp"
#include "ChessPieces/bishop.hpp"
#include "ChessPieces/horse.hpp"
#include "ChessPieces/queen.hpp"
#include "ChessPieces/rook.hpp"
#include "ChessPieces/king.hpp"

std::list<Pos> BackTrackAvalPlaces(const Pos &PiecesPos, Ichess_pieces::Table_t &Table)
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

int main()
{
    table<std::shared_ptr<Ichess_pieces>> Table;
    // table<Ichess_pieces *> Table2;
   
    Table[0] = {std::make_shared<rook>(0), std::make_shared<horse>(0),nullptr,std::make_shared<queen>(0),std::make_shared<king>(0),std::make_shared<bishop>(0),std::make_shared<horse>(0),std::make_shared<rook>(0)};
    Table[1] = {nullptr,     nullptr, std::make_shared<pawn>(0), nullptr, std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0)};
    Table[2] = {nullptr,     std::make_shared<pawn>(0),     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[3] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[4] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[5] = {nullptr,     nullptr,     nullptr,     std::make_shared<pawn>(0),     nullptr,      nullptr,      nullptr,      nullptr};
    Table[6] = {std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1),std::make_shared<pawn>(1)};
    Table[7] = {std::make_shared<rook>(1), std::make_shared<horse>(1),nullptr,std::make_shared<queen>(1),std::make_shared<king>(1),std::make_shared<bishop>(1),std::make_shared<horse>(1),std::make_shared<rook>(1)};


    // auto list = BackTrackAvalPlaces({4, 2}, Table);

    // std::for_each(list.begin(), list.end(), [](auto &pos){ std::cout << pos.x << " " << pos.y << " " << std::endl; });

    Table[0][0] = Table[0][1]->copy();
    Table.printTable();

}


