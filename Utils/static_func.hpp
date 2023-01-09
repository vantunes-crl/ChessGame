#pragma once

#include "../ChessPieces/pawn.hpp"
#include "../ChessPieces/bishop.hpp"
#include "../ChessPieces/horse.hpp"
#include "../ChessPieces/queen.hpp"
#include "../ChessPieces/rook.hpp"
#include "../ChessPieces/king.hpp"


static void make_piece(const int type, std::unique_ptr<Ichess_pieces> &Piece)
{
  switch (type)
  {
  case WHITE_BISHOP:
    Piece =  std::make_unique<bishop>(1);
    break;
  case WHITE_HORSE:
    Piece =  std::make_unique<horse>(1);
    break;
  case WHITE_KING:
    Piece =  std::make_unique<king>(1);
    break;
  case WHITE_QUEEN:
    Piece =  std::make_unique<queen>(1);
    break;
  case WHITE_PAWN:
    Piece =  std::make_unique<pawn>(1);
    break;
  case WHITE_ROOK:
    Piece =  std::make_unique<rook>(1);
    break;
  case BLACK_BISHOP:
    Piece =  std::make_unique<bishop>(0);
    break;
  case BLACK_HORSE:
   Piece =  std::make_unique<horse>(0);
    break;
  case BLACK_KING:
    Piece =  std::make_unique<king>(0);
    break;
  case BLACK_QUEEN:
    Piece =  std::make_unique<queen>(0);
    break;
  case BLACK_PAWN:
    Piece =  std::make_unique<pawn>(0);
    break;
  case BLACK_ROOK:
    Piece =  std::make_unique<rook>(0);
    break;
  }
}

static void loadState(Board &board)
{
  std::fstream file("Utils/init.rec", std::ios::in);

  int n;
  for (int i = 0; i < 64; ++i)
  {
      file >> n;
      make_piece(n, board[i]);
  }
}