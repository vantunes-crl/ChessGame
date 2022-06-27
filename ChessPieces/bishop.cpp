#include "bishop.hpp"

int bishop::play(Table_t &Table, Pos ToMovePos)
{
    Pos pos = this->getPos(Table); //original to set pos after move

    if (ToMovePos.x > 7 || ToMovePos.x < 0 || ToMovePos.y > 7 || ToMovePos.y < 0) //out size of the table
        return OUT_SIZE;
    else if (ToMovePos.x == pos.x || ToMovePos.y == pos.y) //if is not moving
        return SAME_PLACE;
    else if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;

    auto List = backTrack.checkDiagonal(Table, pos, DIAGONAL_TOP_LEFT);
    auto List2 = backTrack.checkDiagonal(Table, pos, DIAGONAL_TOP_RIGHT);
    auto List3 = backTrack.checkDiagonal(Table, pos, DIAGONAL_BOTTOM_LEFT);
    auto List4 = backTrack.checkDiagonal(Table, pos, DIAGONAL_BOTTOM_RIGHT);

    List.insert(List.end(), List2.begin(), List2.end());
    List.insert(List.end(), List3.begin(), List3.end());    
    List.insert(List.end(), List4.begin(), List4.end());    

    for (auto it = List.begin(); it != List.end(); ++it)
    {
        if (it->x == -1 && it->y == -1)
            return CANT_MOVE;
        if (ToMovePos.x == it->x && ToMovePos.y == it->y)
        {
            Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
            Table[pos.x][pos.y] = nullptr;
            return NO_ERROR;
        }
    }
    return CANT_MOVE;
}

int bishop::type()
{
    if (Color)
        return WHITE_BISHOP;
    else
        return BLACK_BISHOP;
}

Pos bishop::getPos(Table_t &Table) const
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

bishop::bishop(bool b)
{
    Color = b;
}


std::shared_ptr<Ichess_pieces> bishop::copy()
{
    return std::make_shared<bishop>(Color);
}


bool bishop::getColor() const
{
    return Color;
}