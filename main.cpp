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
    Table[6] = {new rook, new horse, new bishop, new queen, new king, new bishop, new horse, new rook};
    Table[7] = {new pawn, new pawn, new pawn, new pawn, new pawn, new pawn, new pawn, new pawn};


    Table[1][0]->play(Table);


    //std::cout << Table[1][0] << std::endl;
    
    //std::cout << temp << std::endl;
    
    Pos pos = Table[0][5]->getPos(Table);
    std::cout << Table[0][5]->type() << std::endl;

    std::cout << pos.x << "x " << pos.y << "y " << std::endl;

    //Table.printTable();

    //std::cout << temp->getPos(Table).x << temp->getPos(Table).y << std::endl;

}