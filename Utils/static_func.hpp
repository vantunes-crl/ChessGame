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
    Piece =  std::make_unique<bishop>(BLACK);
    break;
  case WHITE_HORSE:
    Piece =  std::make_unique<horse>(BLACK);
    break;
  case WHITE_KING:
    Piece =  std::make_unique<king>(BLACK);
    break;
  case WHITE_QUEEN:
    Piece =  std::make_unique<queen>(BLACK);
    break;
  case WHITE_PAWN:
    Piece =  std::make_unique<pawn>(BLACK);
    break;
  case WHITE_ROOK:
    Piece =  std::make_unique<rook>(BLACK);
    break;
  case BLACK_BISHOP:
    Piece =  std::make_unique<bishop>(WHITE);
    break;
  case BLACK_HORSE:
   Piece =  std::make_unique<horse>(WHITE);
    break;
  case BLACK_KING:
    Piece =  std::make_unique<king>(WHITE);
    break;
  case BLACK_QUEEN:
    Piece =  std::make_unique<queen>(WHITE);
    break;
  case BLACK_PAWN:
    Piece =  std::make_unique<pawn>(WHITE);
    break;
  case BLACK_ROOK:
    Piece =  std::make_unique<rook>(WHITE);
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