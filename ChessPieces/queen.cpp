#include "queen.hpp"

void queen::play(table<Ichess_pieces *> &Table)
{

}

PIECES queen::type()
{
    return QUEEN;
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