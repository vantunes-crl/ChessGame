#include "rook.hpp"

rook::rook(bool b)
{
    Color = b;
}

int rook::play(Table_t &Table, Pos ToMovePos)
{
    Pos pos = this->getPos(Table);

    if (ToMovePos.x < 0 || ToMovePos.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7)
        return OUT_SIZE;
    else if (pos.x != ToMovePos.x && pos.y != ToMovePos.y) //just can move to left or right not both
        return CANT_MOVE;
    else if (pos.x == ToMovePos.x && pos.y == ToMovePos.y) // check if its the same pos
        return SAME_PLACE;
    else
    {
        int i = 1;
        if (ToMovePos.x > pos.x || ToMovePos.y > pos.y)
        {
            while ((pos.x + i) < ToMovePos.x) //check vertical
            {
                if (Table[pos.x + i][pos.y])
                    return CANT_MOVE;
                ++i;
            }

            i = 1;
            while ((pos.y + i) < ToMovePos.y) // check horizontal
            {
                if (Table[pos.x][pos.y + i])
                    return CANT_MOVE;
                ++i;
            }
        }
        else
        {
            i = 1;
            while ((pos.x - i) > ToMovePos.x) //check vertical reverse
            {
                if (Table[pos.x - i][pos.y])
                    return CANT_MOVE;
                ++i;
            }

            i = 1;
            while ((pos.y - i) > ToMovePos.y) // check horizontal reverse
            {
                if (Table[pos.x][pos.y - i])
                    return CANT_MOVE;
                ++i;
            }
        }
        
    }

    if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() != this->getColor()) //verify if exists and its is not a friend
    {
        Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
        Table[pos.x][pos.y] = nullptr;
    }
    else if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor())
        return CANT_MOVE;
    else
    {
        Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
        Table[pos.x][pos.y] = nullptr;
    }

    return NO_ERROR;
}

int rook::type()
{
    if (Color)
        return WHITE_ROOK;
    else
        return BLACK_ROOK;
}

Pos rook::getPos(Table_t &Table) const
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

std::shared_ptr<Ichess_pieces> rook::copy()
{
    return std::make_shared<rook>(Color);
}


bool rook::getColor() const
{
    return Color;
}