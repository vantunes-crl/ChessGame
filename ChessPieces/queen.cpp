#include "queen.hpp"

void queen::play(table<Ichess_pieces *> &Table, int x, int y)
{

}

PIECES queen::type()
{
    if (Color)
        return WHITE_QUEEN;
    else
        return BLACK_QUEEN;
}

Pos queen::getPos(table<Ichess_pieces *> &Table) const
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