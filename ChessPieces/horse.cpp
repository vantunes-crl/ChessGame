#include "horse.hpp"

horse::horse(bool b)
{
    Color = b;
}
    
int horse::play(Board_t &Board, int ToMoveint)
{
    int pos = this->getPos(Board);

    // if (ToMoveint.x < 0 || ToMoveint.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //out_size of the Board
    //     return OUT_SIZE;
    // else if (ToMoveint.x == pos.x && ToMoveint.y == pos.y) //same pos
    //     return SAME_PLACE;
    // else if (Board[ToMoveint.x][ToMoveint.y] && Board[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //check if its a friend
    //     return CANT_MOVE;
    // //Verify if its moving in L
    // else if (((ToMoveint.x == (pos.x - 2) && (pos.y - 1) == ToMoveint.y) || (ToMovePos.x == (pos.x - 2) && (pos.y + 1) == ToMovePos.y)) || 
    // ((ToMoveint.x == (pos.x + 2) && (pos.y + 1) == ToMoveint.y) || (ToMovePos.x == (pos.x + 2) && (pos.y - 1) == ToMovePos.y)))
    // {
    //     Board[ToMoveint.x][ToMoveint.y] = Board[pos.x][pos.y];
    //     Board[pos.x][pos.y] = nullptr;
    // }
    // else if (((ToMoveint.y == (pos.y - 2) && (pos.x - 1)) == ToMoveint.x || (ToMovePos.y == (pos.y - 2) && (pos.x + 1) == ToMovePos.x)) || 
    // ((ToMoveint.y == (pos.y + 2) && (pos.x + 1)) == ToMoveint.x || (ToMovePos.y == (pos.y + 2) && (pos.x - 1) == ToMovePos.x)))
    // {
    //     Board[ToMoveint.x][ToMoveint.y] = Board[pos.x][pos.y];
    //     Board[pos.x][pos.y] = nullptr;
    // }
    // else
    //     return CANT_MOVE;

    // return NO_ERROR;   
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
    for (int i = 0; i < 8; ++i)
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