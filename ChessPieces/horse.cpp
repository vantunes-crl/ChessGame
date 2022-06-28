#include "horse.hpp"

horse::horse(bool b)
{
    Color = b;
}
    
int horse::play(Table_t &Table, Pos ToMovePos)
{
    Pos pos = this->getPos(Table);

    if (ToMovePos.x < 0 || ToMovePos.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //out_size of the table
        return OUT_SIZE;
    else if (ToMovePos.x == pos.x && ToMovePos.y == pos.y) //same pos
        return SAME_PLACE;
    else if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //check if its a friend
        return CANT_MOVE;
    //Verify if its moving in L
    else if (((ToMovePos.x == (pos.x - 2) && (pos.y - 1) == ToMovePos.y) || (ToMovePos.x == (pos.x - 2) && (pos.y + 1) == ToMovePos.y)) || 
    ((ToMovePos.x == (pos.x + 2) && (pos.y + 1) == ToMovePos.y) || (ToMovePos.x == (pos.x + 2) && (pos.y - 1) == ToMovePos.y)))
    {
        Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
        Table[pos.x][pos.y] = nullptr;
    }
    else if (((ToMovePos.y == (pos.y - 2) && (pos.x - 1)) == ToMovePos.x || (ToMovePos.y == (pos.y - 2) && (pos.x + 1) == ToMovePos.x)) || 
    ((ToMovePos.y == (pos.y + 2) && (pos.x + 1)) == ToMovePos.x || (ToMovePos.y == (pos.y + 2) && (pos.x - 1) == ToMovePos.x)))
    {
        Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
        Table[pos.x][pos.y] = nullptr;
    }
    else
        return CANT_MOVE;

    return NO_ERROR;   
}

int horse::type()
{
    if (Color)
        return WHITE_HORSE;
    else
        return BLACK_HORSE;
}

Pos horse::getPos(Table_t &Table) const
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (this == Table[i][j].get())
                return {i, j};
        }
    }
    return {-1, -1};
}

std::shared_ptr<Ichess_pieces> horse::copy()
{
    return std::make_shared<horse>(Color);
}

bool horse::getColor() const
{
    return Color;
}