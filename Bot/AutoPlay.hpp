#pragma once

#include "../Utils/ChessDataConverter.hpp"
#include "../ChessPieces/Ichess_pieces.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <vector>
#include "../MLPModel/MLP.hpp"
#include "../Utils/static_func.hpp"

/**
 * @brief Class to auto play recorded games.
 * 
 * @tparam Board where the pieces are.
 */


template <class Board>
class AutoPlay
{
    private:
        ChessDataConverter<Board> converter;
        MLP mlp;
        int ROUND = 0;
    public:
        /**
         * @brief Play a encode move Exempale: Ne4
         * 
         * @param move Encoded move.
         * @param board Board where the pieces are.
         **/
        bool Play(std::string &move, Board &board)
        {
            int posToMove = converter.encodeToPosNumber(move);
            auto piecePos = findPieceToPlay(move, board);

            if (move == "O-O")
            {
                posToMove = ROUND ? 4 : 60; //Error handler king pos for swap 60 White 4 Black. 
                piecePos = ROUND ? 7 : 63;
            }
            else if (move == "O-O-O")
            {
                posToMove = ROUND ? 4 : 60; //Error handler king pos for swap 60 White 4 Black. 
                piecePos = ROUND ? 0 : 56;
            }

            std::cout << "Play: " << move << std::endl;
            std::cout << "Played toMove: " << converter.posNumberToEncode(posToMove).first << converter.posNumberToEncode(posToMove).second << std::endl;
            std::cout << "Played:MoveFrom " << converter.posNumberToEncode(piecePos).first << converter.posNumberToEncode(piecePos).second << std::endl;

            if (!(board[piecePos]->play(board, posToMove)))
                ROUND = ROUND ? 0 : 1; // Round 0 White, 1 Black. 
            else //for debug
            {
                std::cout << "Round " << ROUND << " Piece Pos " << piecePos << " MoveToPos " << posToMove << " Normal Move " << move << std::endl;
                sleep(100);
            }
            return true;
        }


        void BotPlay(Board &board)
        {
                    
            auto state = board.read_state();
            auto moves =  mlp.getIstance().forward_propagation(state);
    
            for (auto i = moves.rbegin(); i != moves.rend(); ++i)
            {
                if (!Play(*i, board))
                    break;
                else
                    std::cout << "invalid move" << std::endl;
            }
        }

        /**
         * @brief Start play a recorded game.
         * 
         * @param movesfile .pgn file
         * @param board Board where the initial pieces are.
         */
        void startPlay(std::string movesfile, Board &board)
        {
            auto vec = converter.parseMovesFile(movesfile);
            
            for (int i = 0; i < vec.size(); ++i)
            {
                auto plays = converter.parseMoves(vec[i]);

                for (auto it = plays.begin(); it != plays.end(); ++it)
                {
                    //sleep(1);
                    std::cout << "Number play: " << it->numberOfPlay << std::endl;
                    board.saveState(it->WhitePlay, "White", it->numberOfPlay);
                    Play(it->WhitePlay, board);
                    
                    //sleep(1);
                    board.saveState(it->BlackPlay, "Black", it->numberOfPlay);
                    Play(it->BlackPlay, board);
                }
                std::cout << "finish" << std::endl;
                std::cout << "Loop number: " << i << "Target: " << vec.size() << std::endl;
                board = loadState();
                board.swap_reset();
            }
            
        }

        /**
         * @brief Check which piece of the table can move to that place, as the encode are generic.
         * 
         * @param board Board where the initial pieces are.
         * @param toMovePos Pos to move converted to number based in 64 places.
         * @param Piece Piece type. WHITE_BISHOP, BLACK_BISHOP, BLACK_PAWN...
         * @return The piece pos that can move.
         */
        int predictPieceToMove(Board board, int toMovePos, PIECES Piece, char duplicateMove)
        {
            Board cpyBoard = board;
            int array[2] = {0,0};
            int count = 0;
            
            for (int i = 0; i < 64; ++i)
            {
                cpyBoard = board;
                if (cpyBoard[i] && cpyBoard[i]->type() == Piece)
                {
                    if (!cpyBoard[i]->play(cpyBoard, toMovePos))
                        array[count++] = i;
                    else
                        continue;
                }
            }
            if (duplicateMove && array[1] && converter.posNumberToEncode(array[1]).first == duplicateMove)
                return array[1];

            return array[0];
        }

        /**
         * @brief Find the type of piece based on the encode.
         * Example: K, ROUND 1 = BLACK_KING. 
         * 
         * @param type Piece type
         * @return Piece type.
         */
        PIECES findType(char type)
        {
            switch (type)
            {
            case 'N':
                return ROUND ? BLACK_HORSE : WHITE_HORSE;
            case 'Q':
                return ROUND ? BLACK_QUEEN : WHITE_QUEEN;
            case 'B':
                return ROUND ? BLACK_BISHOP : WHITE_BISHOP;
            case 'R':
            case 'O':
                return ROUND ? BLACK_ROOK : WHITE_ROOK;
            case 'K':
                return ROUND ? BLACK_KING : WHITE_KING;
            default:
                return ROUND ? BLACK_PAWN : WHITE_PAWN;
            }
        }

        /**
         * @brief Find the piece that can play based on the encoded move.
         * 
         * @param move Encoded move.
         * @param board Board where all the pieces are.
         * @return Pos of the piece.
         */
        int findPieceToPlay(std::string move, Board &board)
        {
            auto type = findType(move[0]);
            move.erase(std::remove(move.begin(), move.end(), '+'), move.end());

            int toMovePos = 0;
            char duplicateMove = '\0';

            if (move[0] == 'O')
                toMovePos = ROUND ? 4 : 60;
            else
            {
                if (move.size() == 3 && !std::isupper(move[0]))
                {
                    duplicateMove = move[0];
                    move.erase(move.begin());
                }
                else if ((move.size() == 4 && std::isupper(move[0]) && !std::isupper(move[1])))
                {
                    duplicateMove = move[1]; 
                    move.erase(move.begin() + 1);
                }
                
                toMovePos = converter.encodeToPosNumber(move);
            }
            return predictPieceToMove(board, toMovePos, type, duplicateMove);
        }
 
};