#include "king.hpp"

king::king(bool b)
{
    Color = b;
}

int king::play(table<Ichess_pieces *> &Table, int x, int y)
{
return 0;
}

int king::type()
{
    if (Color)
        return WHITE_KING;
    else
        return BLACK_KING;
}

Pos king::getPos(table<Ichess_pieces *> &Table) const
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