#include "bishop.hpp"

int bishop::play(Board_t &Board, int ToMoveint)
{
    // int pos = this->getPos(Board); //original to set pos after move

    // if (ToMoveint.x > 7 || ToMoveint.x < 0 || ToMovePos.y > 7 || ToMovePos.y < 0) //out size of the Board
    //     return OUT_SIZE;
    // else if (ToMoveint.x == pos.x || ToMoveint.y == pos.y) //if is not moving
    //     return SAME_PLACE;
    // else if (Board[ToMoveint.x][ToMoveint.y] && Board[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //try kill friend
    //     return CANT_MOVE;

    // //Check all diagonal cases and save in a std::list
    // std::list<int> List;
    // for (int i = 0; i < 4; ++i)
    // {
    //     auto ListCpy = backTrack.checkDiagonal(Board, pos, DIAGONAL_CHECK_CASE(i));
    //     List.insert(List.end(), ListCpy.begin(), ListCpy.end());
    // }

    // //Compare the avalivable pos, and move if exists.
    // for (auto it = List.begin(); it != List.end(); ++it)
    // {
    //     if (ToMoveint.x == it->x && ToMoveint.y == it->y)
    //     {
    //         Board[ToMoveint.x][ToMoveint.y] = Board[pos.x][pos.y];
    //         Board[pos.x][pos.y] = nullptr;
    //         return NO_ERROR;
    //     }
    // }
    // return CANT_MOVE;
}

int bishop::type()
{
    if (Color)
        return WHITE_BISHOP;
    else
        return BLACK_BISHOP;
}

int bishop::getPos(Board_t &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}

bishop::bishop(bool b)
{
    Color = b;
}


std::shared_ptr<Ichess_pieces> bishop::copy()
{
    return std::make_shared<bishop>(Color);
}


bool bishop::getColor() const
{
    return Color;
}