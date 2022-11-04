#include <memory>
#include <algorithm>
#include "Board.hpp"
#include "ChessPieces/pawn.hpp"
#include "ChessPieces/bishop.hpp"
#include "ChessPieces/horse.hpp"
#include "ChessPieces/queen.hpp"
#include "ChessPieces/rook.hpp"
#include "ChessPieces/king.hpp"
#include "BackTrackAlgorithm/BackTrack.hpp"
#include "GUI/GUI.hpp"
#include "ChessDataConverter.hpp"
#include <thread>
#include "Bot/AutoPlay.hpp"

int main()
{
    Board<std::shared_ptr<Ichess_pieces>> board;
    
    board = {
        std::make_shared<rook>(0), std::make_shared<horse>(0),std::make_shared<bishop>(0),std::make_shared<queen>(0),std::make_shared<king>(0),std::make_shared<bishop>(0),std::make_shared<horse>(0),std::make_shared<rook>(0),
        std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0),
        nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
        nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
        nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
        nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
        std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1),std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1),std::make_shared<pawn>(1),
        std::make_shared<rook>(1), std::make_shared<horse>(1),std::make_shared<bishop>(1),std::make_shared<queen>(1),std::make_shared<king>(1),std::make_shared<bishop>(1),std::make_shared<horse>(1),std::make_shared<rook>(1),
    };



  // BackTrack backTrack;
  // auto test = backTrack.BackTrackAvalPlacesList(50, board);

  // for (auto t : test)
  //   std::cout << t << std::endl;

  //GUI gui(825, 825);
  AutoPlay<Board<std::shared_ptr<Ichess_pieces>>> autoplay;

  //std::thread first(&GUI::start, gui, std::ref(board));


  std::thread second(&AutoPlay<Board<std::shared_ptr<Ichess_pieces>>>::startPlay, autoplay,"GamesRecorded/ficsgamesdb_202201_standard2000_nomovetimes_263567.pgn", std::ref(board));
  
  //first.join();
  second.join();

  // ChessDataConverter<Board<std::shared_ptr<Ichess_pieces>>> test;

  // auto vec = test.parseMovesFile("GamesRecorded/ficsgamesdb_202201_standard2000_nomovetimes_263567.pgn");
  // auto plays = test.parseMoves(vec[0]);

  // auto a = test.ConvertInput(std::make_pair(7,7));

  // std::cout << a.first << a.second << std::endl;

    //first.join();

}


