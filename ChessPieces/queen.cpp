#include "queen.hpp"

queen::queen(bool b)
{
    Color = b;
}

int queen::play(Board &board, int ToMovePos)
{
    int pos = this->getPos(board); //original to set pos after move
    
    if (Check(board, ToMovePos) == NO_ERROR)
    {
        for (auto it : moves)
        {
            if (it == ToMovePos)
            {
                board[ToMovePos] = board[pos];
                board[pos] = nullptr;
                moves.clear();
                return NO_ERROR;
            }
        };
    }
    moves.clear();
    return CANT_MOVE;
}

int queen::Check(Board &board, int ToMovePos)
{
    int pos = this->getPos(board); //original to set pos after move
    
    if (ToMovePos > 63 || ToMovePos < 0) //out size of the board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (board[ToMovePos] && board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    
    backTrack.AvalMoves(9, RIGHT_EDGE, pos, board, moves); //move top right
    backTrack.AvalMoves(7, LEFT_EDGE, pos, board, moves); //move top left
    backTrack.AvalMoves(-9, LEFT_EDGE, pos, board, moves); //move botton left
    backTrack.AvalMoves(-7, RIGHT_EDGE, pos, board, moves); //move botton right
    backTrack.AvalMoves(8, BOTTON_EDGE, pos, board, moves); //move top right
    backTrack.AvalMoves(-8, TOP_EDGE, pos, board, moves); //move top left
    backTrack.AvalMoves(-1, LEFT_EDGE, pos, board, moves); //move botton left
    backTrack.AvalMoves(1, RIGHT_EDGE, pos, board, moves); //move botton right

    for (auto it : moves)
        if (it == ToMovePos)
            return NO_ERROR;
    return CANT_MOVE;

}

int queen::type()
{
    if (Color)
        return WHITE_QUEEN;
    else
        return BLACK_QUEEN;
}

int queen::getPos(Board &board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == board[i].get())
            return i;
    }
    return -1;
}


std::shared_ptr<Ichess_pieces> queen::copy()
{
    return std::make_shared<queen>(Color);
}


bool queen::getColor() const
{
    return Color;
}