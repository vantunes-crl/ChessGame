#include "king.hpp"

king::king(bool b)
{
    Color = b;
}

bool king::checkIfSomeoneCanKill(Ichess_pieces::Board_t Board, int ToMovePos)
{
    Board[ToMovePos] = std::make_shared<king>(Color);
    for (int i = 0; i < 64; ++i)
    {
        if (Board[i] != nullptr && Board[i]->type() != WHITE_KING && Board[i]->type() != BLACK_KING)
        {
            if (Board[i]->getColor() != this->Color && Board[i]->play(Board, ToMovePos) == 0)
                return true;
        }
    }
    return false;
}

int king::play(Board_t &Board, int ToMovePos)
{
    int pos = this->getPos(Board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the Board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (Board[ToMovePos] && Board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;

    const int AvalPos[8] = {-1, 1, 8, -8, 7, -7, 9, -9};

    if (std::find(std::begin(AvalPos), std::end(AvalPos), ToMovePos - pos) != std::end(AvalPos) && !checkIfSomeoneCanKill(Board, ToMovePos))
        return NO_ERROR;

    return CANT_MOVE;
}

int king::type()
{
    if (Color)
        return WHITE_KING;
    else
        return BLACK_KING;
}

int king::getPos(Board_t &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}


std::shared_ptr<Ichess_pieces> king::copy()
{
    return std::make_shared<king>(Color);
}


bool king::getColor() const
{
    return Color;
}