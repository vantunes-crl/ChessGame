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
            auto plays = converter.parseMoves(vec[1]);

            for (auto it = plays.begin(); it != plays.end(); ++it)
            {
                sleep(1);
                auto parsedMove = 0;
                if (it->WhitePlay[0] == 'O')
                {   
                    std::string s = "K";
                    auto king = findType(s);
                    for (int i = 0; i < 64; ++i)
                    {
                        if (board[i] && board[i]->type() == king)
                            parsedMove = i;
                    }
                }
                else
                    parsedMove = converter.parseMove(it->WhitePlay);
                auto piecePos = ConvertPlay(it->WhitePlay, board);
                if (!(board[piecePos]->play(board, parsedMove)))
                    G_ROUND = 1;
                else
                    std::cout << "G_Round " << G_ROUND << " Piece Pos " << piecePos << " ParsedMove " << parsedMove << " Normal Move " << it->WhitePlay << std::endl; 
                sleep(1);
                if (it->BlackPlay[0] == 'O')
                {   
                    std::string s = "K";
                    auto king = findType(s);
                    for (int i = 0; i < 64; ++i)
                    {
                        if (board[i] && board[i]->type() == king)
                            parsedMove = i;
                    }
                }
                else
                    parsedMove = converter.parseMove(it->BlackPlay);
                piecePos = ConvertPlay(it->BlackPlay, board);
                if (!(board[piecePos]->play(board, parsedMove)))
                    G_ROUND = 0;
                else
                    std::cout << "G_Round " << G_ROUND << " Piece Pos " << piecePos << " ParsedMove " << parsedMove << " Normal Move " << it->BlackPlay << std::endl; 
            }

        }

        int predictPieceToMove(Board &board, int finalPos, PIECES Piece)
        {
            Board cpyBoard = board;
            for (int i = 0; i < 64; ++i)
            {
                cpyBoard = board;
                if (cpyBoard[i] && cpyBoard[i]->type() == Piece)
                {
                    if (!cpyBoard[i]->play(cpyBoard, finalPos))
                        return i;
                    else
                        continue;
                }
            }
            return 0;
        }

        PIECES findType(std::string &move)
        {
            switch (move[0])
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

        int ConvertPlay(std::string &move, Board &board)
        {
            auto type = findType(move);
            int final = 0;
            if (move[0] == 'O')
            {   
                std::string s = "K";
                auto king = findType(s);
                for (int i = 0; i < 64; ++i)
                {
                    if (board[i] && board[i]->type() == king)
                        final = i;
                }
            }
            else
                final = converter.parseMove(move);

            std::cout << final << "final" << std::endl;
            std::cout << type << "type" << std::endl;
            auto test = predictPieceToMove(board, final, type);
            std::cout << "test " << test << std::endl;
            return test;
        }
 
};
