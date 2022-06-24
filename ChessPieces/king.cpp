#include "king.hpp"

king::king(bool b)
{
    Color = b;
}


void checkIfSomeoneCanKill(table<Ichess_pieces *> Table, Pos pos)
{

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (Table[i][j])
            {
                if (!Table[i][j]->play(Table, pos.x, pos.y))
                    std::cout << "can be killed\n";
            }
        }
    }
}

int king::play(table<Ichess_pieces *> &Table, int x, int y)
{

    Pos pos = this->getPos(Table);

    if (x < 0 || x > 7 || y < 0 || y > 7) //check out size
        return OUT_SIZE;
    else if (x == pos.x && y == pos.y) //check if is in the same place
        return SAME_PLACE;
    else if (x > (x + 1) || x < (x - 1) || y > (y + 1) || y < (y - 1)) // check if can move just 1
        return CANT_MOVE;
    else
    {
        checkIfSomeoneCanKill(Table, {x, y});
    }

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


king *king::copy()
{
    return new king(Color);
}