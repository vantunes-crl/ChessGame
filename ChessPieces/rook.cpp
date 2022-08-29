#include "rook.hpp"

rook::rook(bool b)
{
    Color = b;
}

int rook::play(Board_t &Board, int ToMovePos)
{
    int pos = this->getPos(Board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the Board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (Board[ToMovePos] && Board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    
    std::list<int> moves;
    backTrack.AvalMoves(8, BOTTON_EDGE, pos, Board, moves); //move top right
    backTrack.AvalMoves(-8, TOP_EDGE, pos, Board, moves); //move top left
    backTrack.AvalMoves(-1, LEFT_EDGE, pos, Board, moves); //move botton left
    backTrack.AvalMoves(1, RIGHT_EDGE, pos, Board, moves); //move botton right

    for (auto it : moves)
    {
        if (it == ToMovePos)
        {
            Board[ToMovePos] = Board[pos];
            Board[pos] = nullptr;
            return NO_ERROR;
        }
    };

    return CANT_MOVE;
}

int rook::type()
{
    if (Color)
        return WHITE_ROOK;
    else
        return BLACK_ROOK;
}

int rook::getPos(Board_t &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}

std::shared_ptr<Ichess_pieces> rook::copy()
{
    return std::make_shared<rook>(Color);
}


bool rook::getColor() const
{
    return Color;
}