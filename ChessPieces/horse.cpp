#include "horse.hpp"

horse::horse(COLORS b)
{
    Color = b;
}

bool horse::checkDistance(const int &pos, const int &ToMovePos)
{
    int y1 = pos % 8;
    int y2 = ToMovePos % 8;

    if (abs(y1 - y2) > 3)
        return true;
    return false;
}
    
int horse::play(Board &board, const int &ToMovePos)
{
    int pos = this->getPos(board);

    if (Check(board, ToMovePos) == NO_ERROR)
    {
        board[ToMovePos] = std::move(board[pos]);
        board[pos] = nullptr;
        return NO_ERROR;
    }    
    return CANT_MOVE;   
}

int horse::Check(Board &board, const int &ToMovePos)
{
    int pos = this->getPos(board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if it is not moving
        return SAME_PLACE;
    else if (board[ToMovePos] && board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    if (!backTrack.checkOpositeEdges(pos, ToMovePos))
        return CANT_MOVE;
    if (checkDistance(pos, ToMovePos))
        return CANT_MOVE;

    if (std::find(std::begin(AvalPos), std::end(AvalPos), ToMovePos - pos) != std::end(AvalPos))
        return NO_ERROR;
    return CANT_MOVE; 
}

int horse::type() const
{
    if (Color)
        return WHITE_HORSE;
    else
        return BLACK_HORSE;
}

int horse::getPos(Board &board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == board[i].get())
            return i;
    }
    return -1;
}

bool horse::getColor() const
{
    return Color;
}