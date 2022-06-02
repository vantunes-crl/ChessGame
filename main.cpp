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

    Table[0] = {new rook, new horse, new bishop, new queen, new king, new bishop, new horse, new rook};
    Table[1] = {new pawn, new pawn, new pawn, new pawn, new pawn, new pawn, new pawn, new pawn};
    Table[2] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    Table[3] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    Table[4] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    Table[5] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    Table[7] = {new pawn, new pawn, new pawn, new pawn, new pawn, new pawn, new pawn, new pawn};
    Table[6] = {new rook, new horse, new bishop, new queen, new king, new bishop, new horse, new rook};


    //Table[1][0]->play(Table, 0, 0); //case try go back
    //Table[1][0]->play(Table, -1, 1); //case out of table
    //Table[1][0]->play(Table, 1, 0); //case same position
    //Table[1][0]->play(Table, 2, 1); // case if can kill
    //Table[1][0]->play(Table, 2, 0); //he can move
    //Table[1][0]->play(Table, 3, 0); //try move more than 1 slot
    // { //case of someone is in front
    //     Table[1][0]->play(Table, 2, 0);
    //     Table[2][0]->play(Table, 3, 0);
    //     Table[3][0]->play(Table, 4, 0);
    //     Table[4][0]->play(Table, 5, 0);
    //     Table[5][0]->play(Table, 6, 0);
    // }

    Table.printTable();

    //std::cout << temp->getPos(Table).x << temp->getPos(Table).y << std::endl;

}