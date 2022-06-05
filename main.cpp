#include "Ichess_pieces.hpp"
#include "table.hpp"
#include <memory>
#include "ChessPieces/pawn.hpp"
#include "ChessPieces/bishop.hpp"
#include "ChessPieces/horse.hpp"
#include "ChessPieces/queen.hpp"
#include "ChessPieces/rook.hpp"
#include "ChessPieces/king.hpp"

int main(int argc, char **argv)
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



    //Test pawn
    // Table[1][0]->play(Table, 2, 0);
    // Table[2][0]->play(Table, 3, 0);
    // Table[3][0]->play(Table, 4, 0);
    // Table[4][0]->play(Table, 5, 0);
    // Table[5][0]->play(Table, 6, 1);
    // Table[6][1]->play(Table, 6, 0);
    // Table[6][1]->play(Table, 7, 1);
    // Table[6][1]->play(Table, 7, 0);


    //test rook
    // Table[0][0]->play(Table, 4, 0);
    // Table[4][3] = new pawn(0);
    // Table[4][0]->play(Table, 4, 2);
    // Table[4][2]->play(Table, 4, 4);


   
    //Table[5][0]->play(Table, 0, 0);


    //Table[6][0]->play(Table, 6, 1);
    //Table[6][1]->play(Table, 6, 0);
    //Pos pos = Table[6][1]->getPos(Table);
    //std::cout << pos.x << pos.y << std::endl;


    
    //Table[2][0]->play(Table, 3, 0);
    // Table[3][0]->play(Table, 4, 0);
    // Table[4][0]->play(Table, 5, 0);
    // Table[5][0]->play(Table, 6, 1);
    // Table[6][1]->play(Table, 6, 0);
    // Table[6][1]->play(Table, 7, 1);
    // Table[6][1]->play(Table, 7, 0);











    // while (true)
    // {
    //     Pos pos_piece;
    //     Pos pos_move_to;
    //     std::cout << "Pos piece: X Y \n";
    //     std::cin >> pos_piece.x;
    //     std::cin >> pos_piece.y;
    //     std::cout << "Pos move to: X Y \n";
    //     std::cin >> pos_move_to.x;
    //     std::cin >> pos_move_to.y;
    //     Table[pos_piece.x][pos_piece.y]->play(Table, pos_move_to.x, pos_move_to.y);
         Table.printTable();
    // }

}