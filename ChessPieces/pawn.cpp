#include "pawn.hpp"

pawn::pawn(bool b)
{
    Color = b;
}

int pawn::play(Table_t &Table, Pos ToMovePos)
{
    Pos pos = this->getPos(Table);

    if (ToMovePos.x < 0 || ToMovePos.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //verify if not out_size
        return OUT_SIZE;
    else if (pos.x == ToMovePos.x && pos.y == ToMovePos.y) //verify if is the same position
        return SAME_PLACE;
    else if (pos.x > ToMovePos.x && !this->getColor() || pos.x < ToMovePos.x && this->getColor()) //verify if is trying to go back black/white
        return GO_BACK;
    else if (ToMovePos.x - pos.x != 0 || ToMovePos.y - pos.y != 0)
    {
        return LIMIT_MOVES;
    }
    // std::cout << ToMovePos.x << ToMovePos.y << std::endl;
    // std::cout << pos.x << pos.y << std::endl;
    return 0;
}

Pos pawn::getPos(Table_t &Table) const
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

int pawn::type()
{
    if (Color)
        return WHITE_PAWN;
    else
        return BLACK_PAWN;
}

std::shared_ptr<Ichess_pieces> pawn::copy()
{
    return std::make_shared<pawn>(Color);
}


bool pawn::getColor() const
{
    return Color;
}