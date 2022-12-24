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



std::shared_ptr<Ichess_pieces> make_piece(const int type)
{
  switch (type)
  {
  case WHITE_BISHOP:
    return std::make_shared<bishop>(1);
  case WHITE_HORSE:
    return std::make_shared<horse>(1);
  case WHITE_KING:
    return std::make_shared<king>(1);
  case WHITE_QUEEN:
    return std::make_shared<queen>(1);
  case WHITE_PAWN:
    return std::make_shared<pawn>(1);
  case WHITE_ROOK:
    return std::make_shared<rook>(1);
  case BLACK_BISHOP:
    return std::make_shared<bishop>(0);
  case BLACK_HORSE:
    return std::make_shared<horse>(0);
  case BLACK_KING:
    return std::make_shared<king>(0);
  case BLACK_QUEEN:
    return std::make_shared<queen>(0);
  case BLACK_PAWN:
    return std::make_shared<pawn>(0);
  case BLACK_ROOK:
    return std::make_shared<rook>(0);
  }
  return nullptr;
}


std::array<std::shared_ptr<Ichess_pieces>, 64> loadState()
{

  std::fstream file("Game.rec", std::ios::in);
  std::array<std::shared_ptr<Ichess_pieces>, 64> board;
  int n;
  for (int i = 0; i < 64; ++i)
  {
      file >> n;
      board[i] = make_piece(n);
  }
  return board;
}


int main()
{
    Board<std::shared_ptr<Ichess_pieces>> board;
    
    //board = loadState();
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

  //board.printTable();

  // BackTrack backTrack;
  // auto test = backTrack.BackTrackAvalPlacesList(50, board);

  // for (auto t : test)
  //   std::cout << t << std::endl;

  // GUI gui(825, 825);
  // std::thread first(&GUI::start, gui, std::ref(board));

  AutoPlay<Board<std::shared_ptr<Ichess_pieces>>> autoplay;
  std::thread second(&AutoPlay<Board<std::shared_ptr<Ichess_pieces>>>::startPlay, autoplay,"GamesRecorded/ficsgamesdb_202201_standard2000_nomovetimes_263567.pgn", std::ref(board));
  second.join();

  // first.join();




  // ChessDataConverter<Board<std::shared_ptr<Ichess_pieces>>> test;
  // auto vec = test.parseMovesFile("GamesRecorded/ficsgamesdb_202201_standard2000_nomovetimes_263567.pgn");
  // auto plays = test.parseMoves(vec[0]);
  // auto a = test.ConvertInput(std::make_pair(7,7));
  // std::cout << a.first << a.second << std::endl;
  //first.join();

}


