#include "horse.hpp"

horse::horse(bool b)
{
    Color = b;
}
    
int horse::play(table<Ichess_pieces *> &Table, int x, int y)
{
    return 0;   
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