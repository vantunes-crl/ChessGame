#include <memory>
#include <algorithm>
#include <thread>
#include "Utils/static_func.hpp"
#include "GUI/GUI.hpp"
#include "Bot/AutoPlay.hpp"
#include "Board.hpp"

int main()
{
    
    Board board;
    // // //MLP mlp;

    loadState(board);

    
    // *Board::Board_ = {
    //     std::make_shared<rook>(0), std::make_shared<horse>(0),std::make_shared<bishop>(0),std::make_shared<queen>(0),std::make_shared<king>(0),std::make_shared<bishop>(0),std::make_shared<horse>(0),std::make_shared<rook>(0),
    //     std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0), std::make_shared<pawn>(0),
    //     nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
    //     nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
    //     nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
    //     nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
    //     std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1),std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1), std::make_shared<pawn>(1),std::make_shared<pawn>(1),
    //     std::make_shared<rook>(1), std::make_shared<horse>(1),std::make_shared<bishop>(1),std::make_shared<queen>(1),std::make_shared<king>(1),std::make_shared<bishop>(1),std::make_shared<horse>(1),std::make_shared<rook>(1),
    // };


  //Board::Board_->printTable();

  // BackTrack backTrack;
  // auto test = backTrack.BackTrackAvalPlacesList(50, board);
  // std::string move = mlp.forward_propagation(board.read_state());
  // std::cout << move << std::endl;

  GUI gui(825, 825);
  //AutoPlay<Board> autoplay;

  // // board.printTable();
  std::thread first(&GUI::start, gui, std::ref(board));
  //sleep(10);
  //std::thread second(&AutoPlay<Board>::BotPlay, autoplay, std::ref(board));


  //sleep(3);
  //std::string str = "Qb4";
  //std::thread second(&AutoPlay<Board>::Play, autoplay, std::ref(str), std::ref(board));

  //int i = 221;
  //autoplay.startPlay("/home/vantunes/ChessGame/blackWins.pgn");
  //
  //std::thread second(&AutoPlay<Board>::startPlay, autoplay, "/home/vantunes/ChessGame/dataChess/dataChess.pgn");

  //std::thread second(&AutoPlay<Board<std::shared_ptr<Ichess_pieces>>>::BotPlay, autoplay, std::ref(board));
  
  first.join();
  //second.join();


  // ChessDataConverter<Board<std::shared_ptr<Ichess_pieces>>> test;
  // auto vec = test.parseMovesFile("GamesRecorded/ficsgamesdb_202201_standard2000_nomovetimes_263567.pgn");
  // auto plays = test.parseMoves(vec[0]);
  // auto a = test.ConvertInput(std::make_pair(7,7));
  // std::cout << a.first << a.second << std::endl;
  //first.join();

}


