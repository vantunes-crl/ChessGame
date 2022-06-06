#include "bishop.hpp"

int bishop::play(table<Ichess_pieces *> &Table, int x, int y)
{
    Pos pos = this->getPos(Table);

    // if (x > 7 || x < 0 || y > 7 || y < 0)
    //     return OUT_SIZE;
    // else if ()
    // {

    // }
















    return 0;
}

int bishop::type()
{
    if (Color)
        return WHITE_BISHOP;
    else
        return BLACK_BISHOP;
}

Pos bishop::getPos(table<Ichess_pieces *> &Table) const
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

bishop::bishop(bool b)
{
    Color = b;
}