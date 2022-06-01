#include "queen.hpp"

void queen::play(table<Ichess_pieces *> &Table)
{

}

std::string queen::type()
{
    return "queen";
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