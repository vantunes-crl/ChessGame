#include "horse.hpp"

horse::horse(bool b)
{
    Color = b;
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

    const int AvalPos[4] = {17, -17, 15, -15};
    if (std::find(std::begin(AvalPos), std::end(AvalPos), ToMovePos - pos) != std::end(AvalPos))
    {
        Board.getFirstPlay(this->Color) = false;
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