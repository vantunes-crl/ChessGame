#include "bishop.hpp"

int bishop::play(Board &Board, const int &ToMovePos)
{
    int pos = this->getPos(Board);
    if (Check(Board, ToMovePos) == NO_ERROR)
    {
        for (auto it : moves)
        {
            if (it == ToMovePos)
            {
                Board[ToMovePos] = std::move(Board[pos]);
                Board[pos] = nullptr;
                return NO_ERROR;
            }
        };
        moves.clear();
        return NO_ERROR;
    }
    moves.clear();
    return CANT_MOVE;
}

int bishop::Check(Board &Board, const int &ToMovePos)
{
    int pos = this->getPos(Board); //original to set pos after move
    
    if (ToMovePos > 63 || ToMovePos < 0) //out size of the Board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (Board[ToMovePos] && Board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    
    backTrack.AvalMoves(9, RIGHT_EDGE, pos, Board, moves); //move top right
    backTrack.AvalMoves(7, LEFT_EDGE, pos, Board, moves); //move top left
    backTrack.AvalMoves(-9, LEFT_EDGE, pos, Board, moves); //move botton left
    backTrack.AvalMoves(-7, RIGHT_EDGE, pos, Board, moves); //move botton right

    for (auto it : moves)
    {
        if (it == ToMovePos)
            return NO_ERROR;
    };

    return CANT_MOVE;

}

int bishop::type() const
{
    if (Color)
        return WHITE_BISHOP;
    else
        return BLACK_BISHOP;
}

int bishop::getPos(Board &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}

bishop::bishop(COLORS b)
{
    Color = b;
}


bool bishop::getColor() const
{
    return Color;
}