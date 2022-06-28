#include "queen.hpp"

queen::queen(bool b)
{
    Color = b;
}

int queen::play(Table_t &Table, Pos ToMovePos)
{
    Pos pos = this->getPos(Table);
    Pos posCpy(pos);

    if (ToMovePos.x < 0 || ToMovePos.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //out_size of the table
        return OUT_SIZE;
    else if (pos.x == ToMovePos.x && pos.y == ToMovePos.y) //Same place
        return SAME_PLACE;
    else if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //its a friend
        return CANT_MOVE;
    
    std::list<Pos> List;
    for (int i = 0; i < 4; ++i) //check all diagonal
    {
        auto ListCpy = backTrack.checkDiagonal(Table, pos, DIAGONAL_CHECK_CASE(i));
        List.insert(List.end(), ListCpy.begin(), ListCpy.end());
    }

    //check all vertical/horizontal
    auto List1 = backTrack.checkVertical(Table, pos, VERTICAL_TOP);
    auto List2 = backTrack.checkVertical(Table, pos, VERTICAL_BOTTOM);
    auto List3 = backTrack.checkHorizontal(Table, pos, HORIZONTAL_RIGHT);
    auto List4 = backTrack.checkHorizontal(Table, pos, HORIZONTAL_RIGHT);

    //append in the main list
    List.insert(List.end(), List1.begin(), List1.end());
    List.insert(List.end(), List2.begin(), List2.end());
    List.insert(List.end(), List3.begin(), List3.end());
    List.insert(List.end(), List4.begin(), List4.end());

    //Check in the list of avaliable places, if exists move.
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

int queen::type()
{
    if (Color)
        return WHITE_QUEEN;
    else
        return BLACK_QUEEN;
}

Pos queen::getPos(Table_t &Table) const
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


std::shared_ptr<Ichess_pieces> queen::copy()
{
    return std::make_shared<queen>(Color);
}


bool queen::getColor() const
{
    return Color;
}