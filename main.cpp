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
    Table[1] = {new pawn(0), new pawn(0), new pawn(0), new pawn(0), new pawn(0), new pawn(0), new pawn(0), new pawn(0)};
    Table[2] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[3] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[4] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[5] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[6] = {new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1), new pawn(1),new pawn(1)};
    Table[7] = {new rook(1), new horse(1),new bishop(1),new queen(1),new king(1),new bishop(1),new horse(1),new rook(1)};


//     Table[6][0]->play(Table, 5, 0); //case try go back
//    Table[5][0]->play(Table, 6, 0);
//     Table[6][0]->play(Table, 5, 1);
    
//     Table[1][0]->play(Table, -1, 1); //case out of table
//     Table[1][0]->play(Table, 1, 0); //case same position
//     Table[1][0]->play(Table, 2, 1); // case if can kill
//     Table[1][0]->play(Table, 2, 0); //he can move
//     Table[1][0]->play(Table, 3, 0); //try move more than 1 slot
//     { //case of someone is in front
//         Table[1][0]->play(Table, 2, 0);
//         Table[2][0]->play(Table, 3, 0);
//         Table[3][0]->play(Table, 4, 0);
//         Table[4][0]->play(Table, 5, 0);
//         Table[5][0]->play(Table, 6, 0);
//     }

    Table[2][0] = std::move(Table[0][0]);
    Table[0][0] = nullptr;

    // Table[2][4] = std::move(Table[1][4]); 
    // Table[1][4] = nullptr;


    //Table[0][0]->play(Table, 0, 0);


    // Table[1][1]->play(Table, 2, 1); test if he can kill friend
    // Table[1][0]->play(Table, 2, 1);

    //std::cout << Table[0][2]->getColor() << std::endl;

    //std::cout << temp->getColor();


    Table.printTable();

    //std::cout << temp->getPos(Table).x << temp->getPos(Table).y << std::endl;

}