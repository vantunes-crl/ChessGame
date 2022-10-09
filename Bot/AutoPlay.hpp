#pragma once

#include "../ChessDataConverter.hpp"
#include "../ChessPieces/Ichess_pieces.hpp"
#include <iostream>
#include <unistd.h>

template <class Board>
class AutoPlay
{
    private:
        ChessDataConverter<Board> converter;
        int G_ROUND = 0;
    public:
        void startPlay(std::string movesfile, Board &board)
        {
            auto vec = converter.parseMovesFile(movesfile);
            auto plays = converter.parseMoves(vec[0]);

            for (auto it = plays.begin(); it != plays.end(); ++it)
            {
                sleep(1);
                int posToMove = converter.encodeToPosNumber(it->WhitePlay);
                if (it->WhitePlay[0] == 'O')
                    posToMove = 60;
                auto piecePos = ConvertPlay(it->WhitePlay, board);
                std::cout << "WhitePlay" << "Play: " << it->WhitePlay << std::endl;

                if (!(board[piecePos]->play(board, posToMove)))
                    G_ROUND = 1;
                else
                {
                    std::cout << "G_Round " << G_ROUND << " Piece Pos " << piecePos << " MoveToPos " << posToMove << " Normal Move " << it->WhitePlay << std::endl;
                    sleep(100);
                }
                sleep(1);
                posToMove = converter.encodeToPosNumber(it->BlackPlay);
                if (it->BlackPlay[0] == 'O')
                    posToMove = 4;
                piecePos = ConvertPlay(it->BlackPlay, board);
                std::cout << "BlackPlay" << "Play: " << it->BlackPlay << std::endl;
                if (!(board[piecePos]->play(board, posToMove)))
                    G_ROUND = 0;
                else
                {
                    std::cout << "G_Round " << G_ROUND << " Piece Pos " << piecePos << " MoveToPos " << posToMove << " Normal Move " << it->BlackPlay << std::endl;
                    sleep(100);
                }
            }

        }

        int predictPieceToMove(Board board, int toMovePos, PIECES Piece)
        {
            Board cpyBoard = board;
            for (int i = 0; i < 64; ++i)
            {
                cpyBoard = board;
                if (cpyBoard[i] && cpyBoard[i]->type() == Piece)
                {
                    if (!cpyBoard[i]->play(cpyBoard, toMovePos))
                        return i;
                    else
                        continue;
                }
            }
            return 0;
        }

        PIECES findType(char type)
        {
            switch (type)
            {
            case 'N':
                return G_ROUND ? BLACK_HORSE : WHITE_HORSE;
            case 'Q':
                return G_ROUND ? BLACK_QUEEN : WHITE_QUEEN;
            case 'B':
                return G_ROUND ? BLACK_BISHOP : WHITE_BISHOP;
            case 'R':
            case 'O':
                return G_ROUND ? BLACK_ROOK : WHITE_ROOK;
            case 'K':
                return G_ROUND ? BLACK_KING : WHITE_KING;
            default:
                return G_ROUND ? BLACK_PAWN : WHITE_PAWN;
            }
        }

        int findKingPos(Board &board)
        {
            auto king = findType('K');
            for (int i = 0; i < 64; ++i)
            {
                if (board[i] && board[i]->type() == king)
                    return i;
            }
            return 0;
        }

        int ConvertPlay(std::string &move, Board &board)
        {
            auto type = findType(move[0]);
            int toMovePos = 0;
            if (move[0] == 'O')
                toMovePos = findKingPos(board);
            else
                toMovePos = converter.encodeToPosNumber(move);
            return predictPieceToMove(board, toMovePos, type);
        }
 
};
