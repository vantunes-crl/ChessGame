#include "king.hpp"

king::king(bool b)
{
    Color = b;
}

bool king::checkIfSomeoneCanKill(Ichess_pieces::Table_t Table, Pos pos)
{
    Table[pos.x][pos.y] = std::make_shared<king>(Color);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (Table[i][j] != nullptr && Table[i][j]->type() != WHITE_KING && Table[i][j]->type() != BLACK_KING )
            {
                if (Table[i][j]->getColor() != this->Color && Table[i][j]->play(Table, pos) == 0)
                    return true;
            }
        }
    }
    return false;
}

int king::play(Table_t &Table, Pos ToMovePos)
{

    Pos pos = this->getPos(Table);

    if (ToMovePos.x < 0 || ToMovePos.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7) //check out size
        return OUT_SIZE;
    else if (ToMovePos.x == pos.x && ToMovePos.y == pos.y) //check if is in the same place
        return SAME_PLACE;
    else if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    else
    {
        if (checkIfSomeoneCanKill(Table, {ToMovePos.x, ToMovePos.y}))
            return CANT_MOVE;
    }

   std::list<Pos> List;
    for (int i = 0; i < 4; ++i) //check all diagonal
        List.push_back(*backTrack.checkDiagonal(Table, pos, DIAGONAL_CHECK_CASE(i)).begin());

    //check all vertical/horizontal
    List.push_back(*backTrack.checkVertical(Table, pos, VERTICAL_TOP).begin());
    List.push_back(*backTrack.checkVertical(Table, pos, VERTICAL_BOTTOM).begin());
    List.push_back(*backTrack.checkHorizontal(Table, pos, HORIZONTAL_RIGHT).begin());
    List.push_back(*backTrack.checkHorizontal(Table, pos, HORIZONTAL_RIGHT).begin());


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