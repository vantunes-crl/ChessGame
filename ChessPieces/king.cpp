#include "king.hpp"


king::king(bool b)
{
    Color = b;
}

bool king::checkIfSomeoneCanKill(Board board, int ToMovePos)
{
    board[ToMovePos] = std::make_shared<king>(Color);
    for (int i = 0; i < 64; ++i)
    {
        if (board[i] != nullptr && board[i]->type() != WHITE_KING && board[i]->type() != BLACK_KING)
        {
            if (board[i]->getColor() != this->Color && board[i]->play(board, ToMovePos) == 0)
                return true;
        }
    }
    return false;
}

int king::play(Board &board, int ToMovePos)
{
    int pos = this->getPos(board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (board[ToMovePos] && board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;

    const int AvalPos[8] = {-1, 1, 8, -8, 7, -7, 9, -9};

    if (std::find(std::begin(AvalPos), std::end(AvalPos), ToMovePos - pos) != std::end(AvalPos) && !checkIfSomeoneCanKill(board, ToMovePos))
    {
        board[ToMovePos] = board[pos];
        board[pos] = nullptr;
        return NO_ERROR;
    }

    return CANT_MOVE;
}

int king::type()
{
    if (Color)
        return WHITE_KING;
    else
        return BLACK_KING;
}

int king::getPos(Board &board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == board[i].get())
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