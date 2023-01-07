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
    // //MLP mlp;

    board = loadState();

  
    //*= nullptr;
    
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
  AutoPlay<Board> autoplay;
  // //std::string str = "O-O";

  // // board.printTable();
  // //std::thread second(&AutoPlay<Board<std::shared_ptr<Ichess_pieces>>>::Play, autoplay, std::ref(str), std::ref(board));
  // //autoplay.Play(str, board);
  // //gui.start(board);
  std::thread first(&GUI::start, gui, std::ref(board));

  // //autoplay.startPlay("GamesRecorded/ficsgamesdb_2009_standard2000_nomovetimes_270751.pgn/ficsgamesdb_2009_standard2000_nomovetimes_270751.pgn", board);
  //std::thread second(&AutoPlay<Board>::startPlay, autoplay,"/home/vantunes/ChessGame/GamesRecorded/ficsgamesdb_202201_standard2000_nomovetimes_263567.pgn", std::ref(board));

  // //std::thread second(&AutoPlay<Board<std::shared_ptr<Ichess_pieces>>>::BotPlay, autoplay, std::ref(board));
  
  first.join();
  //second.join();


  // ChessDataConverter<Board<std::shared_ptr<Ichess_pieces>>> test;
  // auto vec = test.parseMovesFile("GamesRecorded/ficsgamesdb_202201_standard2000_nomovetimes_263567.pgn");
  // auto plays = test.parseMoves(vec[0]);
  // auto a = test.ConvertInput(std::make_pair(7,7));
  // std::cout << a.first << a.second << std::endl;
  //first.join();

}


