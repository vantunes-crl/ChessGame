#include "knight.hpp"

knight::knight(bool b)
{
    Color = b;
}

int knight::play(table<Ichess_pieces *> &Table, int x, int y)
{
return 0;
}

int knight::type()
{
    if (Color)
        return WHITE_KNIGHT;
    else
        return BLACK_KNIGHT;
}

Pos knight::getPos(table<Ichess_pieces *> &Table) const
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