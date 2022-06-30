#include "rook.hpp"

rook::rook(bool b)
{
    Color = b;
}

int rook::play(Table_t &Table, Pos ToMovePos)
{
    Pos pos = this->getPos(Table);
    std::list<Pos> List;

    if (ToMovePos.x < 0 || ToMovePos.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //out_side of the table
        return OUT_SIZE;
    else if (pos.x != ToMovePos.x && pos.y != ToMovePos.y) //just can move to left or right not both
        return CANT_MOVE;
    else if (pos.x == ToMovePos.x && pos.y == ToMovePos.y) // check if its the same pos
        return SAME_PLACE;
    else if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    else if (pos.x != ToMovePos.x) //BackTrack of Vertical
    {
        List = backtrack.checkVertical(Table, pos, VERTICAL_TOP);
        auto List2 = backtrack.checkVertical(Table, pos, VERTICAL_BOTTOM);
        List.insert(List.end(), List2.begin(), List2.end());
    }
    else  //BackTrack of Horizontal
    {
        List = backtrack.checkHorizontal(Table, pos, HORIZONTAL_RIGHT);
        auto List2 = backtrack.checkHorizontal(Table, pos, HORIZONTAL_LEFT);
        List.insert(List.end(), List2.begin(), List2.end());
    }

    for (auto it = List.begin(); it != List.end(); ++it)
    {
        if (ToMovePos.x == it->x && ToMovePos.y == it->y)
        {
            Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
            Table[pos.x][pos.y] = nullptr;
            return NO_ERROR;
        }
    }

    return CANT_MOVE;
}

int rook::type()
{
    if (Color)
        return WHITE_ROOK;
    else
        return BLACK_ROOK;
}

Pos rook::getPos(Table_t &Table) const
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

std::shared_ptr<Ichess_pieces> rook::copy()
{
    return std::make_shared<rook>(Color);
}


bool rook::getColor() const
{
    return Color;
}