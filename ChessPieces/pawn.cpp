#include "pawn.hpp"

std::string pawn::type()
{
    return "pawn";
}

void pawn::play(table<Ichess_pieces *> &Table)
{

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