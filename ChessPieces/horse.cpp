#include "horse.hpp"

horse::horse(bool b)
{
    Color = b;
}

bool checkDistance(int pos, int ToMovePos)
{
    int y1 = pos % 8;
    int y2 = ToMovePos % 8;

    if (abs(y1 - y2) > 3)
        return true;
    return false;
}
    
int horse::play(Board_t &Board, int ToMovePos)
{
    int pos = this->getPos(Board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the Board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (Board[ToMovePos] && Board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    if (!backTrack.checkOpositeEdges(pos, ToMovePos))
        return CANT_MOVE;
    if (checkDistance(pos, ToMovePos))
        return CANT_MOVE;

    const int AvalPos[8] = {17, -17, 15, -15, 6, -6, 10, -10};

    if (std::find(std::begin(AvalPos), std::end(AvalPos), ToMovePos - pos) != std::end(AvalPos))
    {
        Board[ToMovePos] = Board[pos];
        Board[pos] = nullptr;
        return NO_ERROR;
    }
    
    return CANT_MOVE;   
}

int horse::type()
{
    if (Color)
        return WHITE_HORSE;
    else
        return BLACK_HORSE;
}

int horse::getPos(Board_t &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}

std::shared_ptr<Ichess_pieces> horse::copy()
{
    return std::make_shared<horse>(Color);
}

bool horse::getColor() const
{
    return Color;
}