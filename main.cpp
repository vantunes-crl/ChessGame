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
// #include "GUI/GUI.hpp"

int main()
{
    Board<std::shared_ptr<Ichess_pieces>> Board;
    
    Board = {
        nullptr, std::make_shared<horse>(0),std::make_shared<bishop>(0),std::make_shared<queen>(0),nullptr,std::make_shared<bishop>(0),std::make_shared<horse>(0),std::make_shared<rook>(0),
        std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0),
        std::make_shared<rook>(0),nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
        nullptr,std::make_shared<king>(0),nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
        nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
        nullptr,nullptr,nullptr,nullptr,std::make_shared<bishop>(1),nullptr,nullptr,nullptr,
        std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), nullptr, std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1),std::make_shared<pawn>(1),
        std::make_shared<rook>(1), std::make_shared<horse>(1),std::make_shared<bishop>(1),std::make_shared<queen>(1),std::make_shared<king>(1),std::make_shared<bishop>(1),std::make_shared<horse>(1),std::make_shared<rook>(1),
    };
    
    Board.printTable();
    
    BackTrack backTrack;
    backTrack.BackTrackAvalPlacesPrint(59, Board);

    //Board[16]->play(Board, 24);
    
    
    
    //GUI gui(800,800);
   
    // Table[0] = {std::make_shared<rook>(0), std::make_shared<horse>(0),std::make_shared<bishop>(0),std::make_shared<queen>(0),std::make_shared<king>(0),std::make_shared<bishop>(0),std::make_shared<horse>(0),std::make_shared<rook>(0)};
    // Table[1] = {std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0)};
    // Table[6] = {std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1),std::make_shared<pawn>(1)};
    // Table[7] = {std::make_shared<rook>(1), std::make_shared<horse>(1),std::make_shared<bishop>(1),std::make_shared<queen>(1),std::make_shared<king>(1),std::make_shared<bishop>(1),std::make_shared<horse>(1),std::make_shared<rook>(1)};

    

    //gui.start(Table);

}


