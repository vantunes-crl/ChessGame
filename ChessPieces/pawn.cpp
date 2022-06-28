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
    else if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //friend
        return CANT_MOVE;

    std::list<Pos> List;
    if (!this->getColor())
    {
        for (int i = 2; i < 4; ++i)
            List.push_back(*backtrack.checkDiagonal(Table, pos, DIAGONAL_CHECK_CASE(i)).begin());
        List.push_back(*backtrack.checkVertical(Table, pos, VERTICAL_TOP).begin());
    }   
    else
    {
        for (int i = 0; i < 2; ++i)
            List.push_back(*backtrack.checkDiagonal(Table, pos, DIAGONAL_CHECK_CASE(i)).begin());
        List.push_back(*backtrack.checkVertical(Table, pos, VERTICAL_BOTTOM).begin());
    }

    auto it = List.begin();
    if (it->x == ToMovePos.x && it->y == ToMovePos.y && Table[ToMovePos.x][ToMovePos.y]) //check if can kill diagonal right
    {
        Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
        Table[pos.x][pos.y] = nullptr;
        return NO_ERROR;
    }
    ++it;
    if (it->x == ToMovePos.x && it->y == ToMovePos.y && Table[ToMovePos.x][ToMovePos.y]) //check if can kill diagonal left
    {
        Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
        Table[pos.x][pos.y] = nullptr;
        return NO_ERROR;
    }
    ++it;
    if (it->x == ToMovePos.x && it->y == ToMovePos.y && !Table[ToMovePos.x][ToMovePos.y]) //no one in front
    {
        Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
        Table[pos.x][pos.y] = nullptr;
        return NO_ERROR;
    }

    return CANT_MOVE;
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