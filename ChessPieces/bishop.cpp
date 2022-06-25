#include "bishop.hpp"


int bishop::play(Table_t &Table, Pos ToMovePos)
{
    Pos pos = this->getPos(Table); //original to set pos after move

    Pos posCpy(pos); //cpy to increment and decrement

    if (ToMovePos.x > 7 || ToMovePos.x < 0 || ToMovePos.y > 7 || ToMovePos.y < 0) //out size of the table
        return OUT_SIZE;
    else if (ToMovePos.x == pos.x || ToMovePos.y == pos.y) //if is not moving in diagonal left/right
        return CANT_MOVE;
    else if (pos.y < ToMovePos.y)
    {
        while (true) //move right
        {
            if (ToMovePos.x < pos.x) //move back else move forward
                posCpy.x--;
            else
                posCpy.x++;
            posCpy.y++;
            if (posCpy.x < 0 || posCpy.y < 0 || posCpy.x > 7 || posCpy.y > 7)
                break;
            if (Table[posCpy.x][posCpy.y] && (posCpy.x != ToMovePos.x && ToMovePos.y != posCpy.y)) //someone along the way, cant move
                return CANT_MOVE;
            if (ToMovePos.x == posCpy.x && ToMovePos.y == posCpy.y) // can move
            {
                if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //its a friend
                    return CANT_MOVE;
                Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y]; //kill
                Table[pos.x][pos.y] = nullptr;
                return NO_ERROR;
            }
        }
        return CANT_MOVE;
    }
    else
    {

        while (true) //move left
        {
            if (ToMovePos.x < pos.x) //move back else move forward
                posCpy.x--;
            else
                posCpy.x++;
            posCpy.y--;
            if (posCpy.x < 0 || posCpy.y < 0 || posCpy.x > 7 || posCpy.y > 7)
                break;
            if (Table[posCpy.x][posCpy.y]) //someone along the way, cant move
                return CANT_MOVE;
            if (ToMovePos.x == posCpy.x && ToMovePos.y == posCpy.y) // can move
            {
                if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor()) //its a friend
                    return CANT_MOVE;
                Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y]; //kill
                Table[pos.x][pos.y] = nullptr;
                return NO_ERROR;
            }
        }
    return CANT_MOVE;
    }
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