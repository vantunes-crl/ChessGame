#include "horse.hpp"

horse::horse(bool b)
{
    Color = b;
}
    
int horse::play(table<Ichess_pieces *> &Table, int x, int y)
{

    Pos pos = this->getPos(Table);


    if (x < 0 || x > 7 || y < 0 || y > 7)
        return OUT_SIZE;
    else if (x == pos.x && y == pos.y)
        return SAME_PLACE;
    else if (Table[x][y] && Table[x][y]->getColor() == this->getColor())
        return CANT_MOVE;
    else if (((x == (pos.x - 2) && (pos.y - 1)) || (x == (pos.x + 2) && (pos.y - 1) == y)) || 
    ((x == (pos.x + 2) && (pos.y + 1)) || (x == (pos.x + 2) && (pos.y + 1) == y)))
    {
        if (Table[x][y])
            delete Table[x][y];
        Table[x][y] = std::move(this);
        Table[pos.x][pos.y] = nullptr;
    }
    else if (((y == (pos.y - 2) && (pos.x - 1)) || (y == (pos.y + 2) && (pos.x - 1) == x)) || 
    ((y == (pos.y + 2) && (pos.x + 1)) || (y == (pos.y + 2) && (pos.x + 1) == x)))
    {
        if (Table[x][y])
            delete Table[x][y];
        Table[x][y] = std::move(this);
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

Pos horse::getPos(table<Ichess_pieces *> &Table) const
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

horse *horse::copy()
{
    return new horse(Color);
}
