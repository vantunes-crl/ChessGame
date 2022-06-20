#include <memory>
#include "table.hpp"
#include "ChessPieces/pawn.hpp"
#include "ChessPieces/bishop.hpp"
#include "ChessPieces/horse.hpp"
#include "ChessPieces/queen.hpp"
#include "ChessPieces/rook.hpp"
#include "ChessPieces/king.hpp"

int main()
{
    table<Ichess_pieces *> Table;
    table<Ichess_pieces *> Table2;


    Table[0] = {new rook(0), new horse(0),new bishop(0),new queen(0),new king(0),new bishop(0),new horse(0),new rook(0)};
    Table[1] = {nullptr,     new pawn(0), new pawn(0), nullptr, new pawn(0), new pawn(0), new pawn(0), new pawn(0)};
    Table[2] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[3] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[4] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[5] = {nullptr,     nullptr,     nullptr,     new pawn(0),     nullptr,      nullptr,      nullptr,      nullptr};
    Table[6] = {new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1),new pawn(1)};
    Table[7] = {new rook(1), new horse(1),new bishop(1),new queen(1),new king(1),new bishop(1),new horse(1),new rook(1)};

    Table[0][4]->play(Table, 1, 5);

   // Table.printTable();

}


