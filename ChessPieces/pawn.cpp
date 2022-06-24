#include "pawn.hpp"

pawn::pawn(bool b)
{
    Color = b;
}

int pawn::play(Table_t &Table, Pos ToMovePos)
{
    Pos pos = this->getPos(Table);

    if (ToMovePos.x < 0 || ToMovePos.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //verify the conors
        return OUT_SIZE;
    else if (pos.x == ToMovePos.x) //verify if is the same position
        return SAME_PLACE;
    else if (pos.x > ToMovePos.x && !this->getColor() || pos.x < ToMovePos.x && this->getColor()) //verify if is trying to go back black/white
        return GO_BACK;
    else if (pos.y != ToMovePos.y) //verify if he can kill
    {
        if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() != this->getColor()) //verify if exists and its is not a friend
        {
            Table[ToMovePos.x][ToMovePos.y] = std::move(Table[pos.x][pos.y]);
            Table[pos.x][pos.y] = nullptr;
        }
        else
            return CANT_MOVE;
    }
    else if ((ToMovePos.x > (pos.x + 1) || ToMovePos.y > (pos.y + 2)) || (ToMovePos.x < (pos.x - 1) || ToMovePos.y < (pos.y - 2))) //verify if is not walking more them 1 slot black/white
        return LIMIT_MOVES;
    else //last case where he can go front
    {
        if (Table[ToMovePos.x][ToMovePos.y])
            return CANT_MOVE;
        Table[ToMovePos.x][ToMovePos.y] = std::move(Table[pos.x][pos.y]);
        Table[pos.x][pos.y] = nullptr;
    }
    return NO_ERROR;
}

Pos pawn::getPos(Table_t &Table) const
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

int pawn::type()
{
    if (Color)
        return WHITE_PAWN;
    else
        return BLACK_PAWN;
}

std::shared_ptr<Ichess_pieces> pawn::copy()
{
    return std::make_shared<pawn>(Color);
}


bool pawn::getColor() const
{
    return Color;
}