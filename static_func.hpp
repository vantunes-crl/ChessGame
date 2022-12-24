#include "ChessPieces/pawn.hpp"
#include "ChessPieces/bishop.hpp"
#include "ChessPieces/horse.hpp"
#include "ChessPieces/queen.hpp"
#include "ChessPieces/rook.hpp"
#include "ChessPieces/king.hpp"

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


static std::array<std::shared_ptr<Ichess_pieces>, 64> loadState()
{

  std::fstream file("init.rec", std::ios::in);
  std::array<std::shared_ptr<Ichess_pieces>, 64> board;
  int n;
  for (int i = 0; i < 64; ++i)
  {
      file >> n;
      board[i] = make_piece(n);
  }
  return board;
}