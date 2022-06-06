#include "pawn.hpp"

pawn::pawn(bool b)
{
    Color = b;
}

int pawn::play(table<Ichess_pieces *> &Table, int x, int y)
{
    Pos pos = this->getPos(Table);

    if (x < 0 || x > 7 || y < 0 || y > 7) //verify the conors
        return OUT_SIZE;
    else if (pos.x == x) //verify if is the same position
        return SAME_PLACE;
    else if (pos.x > x && !this->getColor() || pos.x < x && this->getColor()) //verify if is trying to go back black/white
        return GO_BACK;
    else if (pos.y != y) //verify if he can kill
    {
        if (Table[x][y] && Table[x][y]->getColor() != this->getColor()) //verify if exists and its is not a friend
        {
            delete Table[x][y];
            Table[x][y] = std::move(this);
            Table[pos.x][pos.y] = nullptr;
            std::cout << this->type() << " killed " << Table[x][y]->type() << std::endl;
        }
        else
            return CANT_MOVE;
    }
    else if ((x > (pos.x + 1) || y > (pos.y + 2)) || (x < (pos.x - 1) || y < (pos.y - 2))) //verify if is not walking more them 1 slot black/white
        return LIMIT_MOVES;
    else //last case where he can go front
    {
        if (Table[x][y])
            return CANT_MOVE;
        Table[x][y] = std::move(this);
        Table[pos.x][pos.y] = nullptr;
    }
    return NO_ERROR;
}

Pos pawn::getPos(table<Ichess_pieces *> &Table) const
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (this == Table[i][j])
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