#include "Ichess_pieces.hpp"
#include "table.hpp"
#include <memory>
#include "ChessPieces/pawn.hpp"
#include "ChessPieces/bishop.hpp"
#include "ChessPieces/horse.hpp"
#include "ChessPieces/queen.hpp"
#include "ChessPieces/rook.hpp"
#include "ChessPieces/king.hpp"

int main()
{
    table<Ichess_pieces *> Table;

    Table[0] = {new rook(0), new horse(0),new bishop(0),new queen(0),new king(0),new bishop(0),new horse(0),new rook(0)};
    Table[1] = {nullptr,     new pawn(0), new pawn(0), nullptr, new pawn(0), new pawn(0), new pawn(0), new pawn(0)};
    Table[2] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[3] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[4] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[5] = {nullptr,     nullptr,     nullptr,     new pawn(0),     nullptr,      nullptr,      nullptr,      nullptr};
    Table[6] = {new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1),new pawn(1)};
    Table[7] = {new rook(1), new horse(1),new bishop(1),new queen(1),new king(1),new bishop(1),new horse(1),new rook(1)};

    std::cout << Table[0][2]->play(Table, 1, 3) << std::endl;
    std::cout << Table[1][3]->play(Table, 2, 2) << std::endl;


    Table.printTable();

}


