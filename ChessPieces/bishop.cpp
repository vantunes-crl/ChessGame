#include "bishop.hpp"

int bishop::play(table<Ichess_pieces *> &Table, int x, int y)
{
    Pos pos = this->getPos(Table); //original to set pos after move
    Pos posCpy(pos); //cpy to increment and decrement

    if (x > 7 || x < 0 || y > 7 || y < 0) //out size of the table
        return OUT_SIZE;
    else if (x == pos.x || y == pos.y) //if is not moving in diagonal left/right
        return CANT_MOVE;
    else if (pos.y < y)
    {
        while (true) //move right
        {
            if (x < pos.x) //move back else move forward
                posCpy.x--;
            else
                posCpy.x++;
            posCpy.y++;
            if (posCpy.x < 0 || posCpy.y < 0 || posCpy.x > 7 || posCpy.y > 7)
                break;
            if (Table[posCpy.x][posCpy.y] && (posCpy.x != x && y != posCpy.y)) //someone along the way, cant move
                return CANT_MOVE;
            if (x == posCpy.x && y == posCpy.y) // can move
            {
                if (Table[x][y] && Table[x][y]->getColor() == this->getColor()) //its a friend
                    return CANT_MOVE;
                Table[x][y] = std::move(this); //kill
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
            if (x < pos.x) //move back else move forward
                posCpy.x--;
            else
                posCpy.x++;
            posCpy.y--;
            if (posCpy.x < 0 || posCpy.y < 0 || posCpy.x > 7 || posCpy.y > 7)
                break;
            if (Table[posCpy.x][posCpy.y]) //someone along the way, cant move
                return CANT_MOVE;
            if (x == posCpy.x && y == posCpy.y) // can move
            {
                if (Table[x][y] && Table[x][y]->getColor() == this->getColor()) //its a friend
                    return CANT_MOVE;
                Table[x][y] = std::move(this); //kill
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

Pos bishop::getPos(table<Ichess_pieces *> &Table) const
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

bishop::bishop(bool b)
{
    Color = b;
}