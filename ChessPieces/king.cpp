#include "king.hpp"

king::king(bool b)
{
    Color = b;
}


void checkIfSomeoneCanKill(Ichess_pieces::Table_t Table, Pos pos)
{

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (Table[i][j])
            {
                if (!Table[i][j]->play(Table, pos))
                    std::cout << "can be killed\n";
            }
        }
    }
}

int king::play(Table_t &Table, Pos ToMovePos)
{

    Pos pos = this->getPos(Table);

    if (ToMovePos.x < 0 || ToMovePos.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //check out size
        return OUT_SIZE;
    else if (ToMovePos.x == pos.x && ToMovePos.y == pos.y) //check if is in the same place
        return SAME_PLACE;
    else if (ToMovePos.x > (ToMovePos.x + 1) || ToMovePos.x < (ToMovePos.x - 1) ||
            (ToMovePos.y > (ToMovePos.y + 1) || ToMovePos.y < (ToMovePos.y - 1))) // check if can move just 1
        return CANT_MOVE;
    else
    {
        checkIfSomeoneCanKill(Table, {ToMovePos.x, ToMovePos.y});
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

Pos king::getPos(Table_t &Table) const
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (this == Table[i][j].get())
                return {i, j};
        }
    }
    return {-1, -1};
}


std::shared_ptr<Ichess_pieces> king::copy()
{
    return std::make_shared<king>(Color);
}


bool king::getColor() const
{
    return Color;
}