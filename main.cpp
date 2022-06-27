#include <memory>
#include <algorithm>
#include "table.hpp"
#include "ChessPieces/pawn.hpp"
#include "ChessPieces/bishop.hpp"
#include "ChessPieces/horse.hpp"
#include "ChessPieces/queen.hpp"
#include "ChessPieces/rook.hpp"
#include "ChessPieces/king.hpp"
#include "BackTrackAlgorithm/BackTrack.hpp"

int main()
{
    table<std::shared_ptr<Ichess_pieces>> Table;
    // table<Ichess_pieces *> Table2;
   
    Table[0] = {std::make_shared<rook>(0), std::make_shared<horse>(0),std::make_shared<bishop>(0),std::make_shared<queen>(0),std::make_shared<king>(0),std::make_shared<bishop>(0),std::make_shared<horse>(0),std::make_shared<rook>(0)};
    Table[1] = {nullptr,     nullptr, std::make_shared<pawn>(0), nullptr, std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0)};
    Table[2] = {nullptr,     nullptr,     nullptr,     nullptr,     std::make_shared<pawn>(0),    nullptr,      nullptr,      nullptr};
    Table[3] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      std::make_shared<pawn>(0),      nullptr};
    Table[4] = {nullptr,     nullptr,     nullptr,     nullptr,     nullptr,      nullptr,      nullptr,      nullptr};
    Table[5] = {nullptr,     nullptr,     nullptr,     std::make_shared<pawn>(0),     nullptr,      nullptr,      nullptr,      nullptr};
    Table[6] = {std::make_shared<pawn>(1), nullptr, std::make_shared<pawn>(1), nullptr, std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1),std::make_shared<pawn>(1)};
    Table[7] = {std::make_shared<rook>(1), std::make_shared<horse>(1),std::make_shared<bishop>(1),std::make_shared<queen>(1),std::make_shared<king>(1),std::make_shared<bishop>(1),std::make_shared<horse>(1),std::make_shared<rook>(1)};


    // Table[0][0] = std::make_shared<rook>(0);
    // Table[4][4] = std::make_shared<bishop>(0);
    // Table[3][3] = std::make_shared<bishop>(0);


   // Table[4][4]->play(Table, {0,2});


    BackTrack backTrack;
   backTrack.BackTrackAvalPlacesPrint({7, 2}, Table);

    //std::cout << Table[1][5]->type() << std::endl;

   //std::cout << Table[0][2]->play(Table, {1,0}) << std::endl;
    Table.printTable();

}


