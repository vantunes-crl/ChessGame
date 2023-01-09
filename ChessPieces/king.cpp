#include "king.hpp"


king::king(bool b)
{
    Color = b;
}

bool king::checkIfSomeoneCanKill(Board &board, int ToMovePos)
{
    for (int i = 0; i < 64; ++i)
    {
        if (board[i] != nullptr && board[i]->type() != WHITE_KING && board[i]->type() != BLACK_KING)
        {
            auto check = board[i]->Check(board, ToMovePos);
            if (board[i]->getColor() != this->Color && check == NO_ERROR)
                return true;
        }
    }
    return false;
}

int king::play(Board &board, int ToMovePos)
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

int king::Check(Board &board, int ToMovePos)
{
    int pos = this->getPos(board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (board[ToMovePos] && board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;

    if (std::find(std::begin(AvalPos), std::end(AvalPos), ToMovePos - pos) != std::end(AvalPos)) //&& !checkIfSomeoneCanKill(board, ToMovePos))
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

int king::getPos(Board &board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == board[i].get())
            return i;
    }
    return -1;
}


std::unique_ptr<Ichess_pieces> king::copy()
{
    return std::make_unique<king>(Color);
}


bool king::getColor() const
{
    return Color;
}