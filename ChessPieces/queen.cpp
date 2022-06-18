#include "queen.hpp"

queen::queen(bool b)
{
    Color = b;
}

int queen::play(table<Ichess_pieces *> &Table, int x, int y)
{

    Pos pos = this->getPos(Table);
    Pos posCpy(pos);

    if (x < 0 || x > 7 || y < 0 || y > 7)
        return OUT_SIZE;
    else if (pos.x == x && pos.y == y)
        return SAME_PLACE;
    else if (Table[x][y] && Table[x][y]->getColor() == this->getColor())
        return CANT_MOVE;
    else if (x != pos.x && y != pos.y) //diagonal case
    {
        if (pos.y < y)
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
                    Table[x][y] = std::move(this); //kill
                    Table[pos.x][pos.y] = nullptr;
                    return NO_ERROR;
                }
            }
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
                    Table[x][y] = std::move(this); //kill
                    Table[pos.x][pos.y] = nullptr;
                    return NO_ERROR;
                }
            }
        }
        return CANT_MOVE;
    }
    else
    {

        int i = 1;
        if (x > pos.x || y > pos.y)
        {
            while ((pos.x + i) < x) //check vertical
            {
                if (Table[pos.x + i][pos.y])
                    return CANT_MOVE;
                ++i;
            }

            i = 1;
            while ((pos.y + i) < y) // check horizontal
            {
                if (Table[pos.x][pos.y + i])
                    return CANT_MOVE;
                ++i;
            }
        }
        else
        {
            i = 1;
            while ((pos.x - i) > x) //check vertical reverse
            {
                if (Table[pos.x - i][pos.y])
                    return CANT_MOVE;
                ++i;
            }

            i = 1;
            while ((pos.y - i) > y) // check horizontal reverse
            {
                if (Table[pos.x][pos.y - i])
                    return CANT_MOVE;
                ++i;
            }
        }

        if (Table[x][y])
        {
            delete Table[x][y];
            Table[x][y] = std::move(this);
            Table[pos.x][pos.y] = nullptr;
            std::cout << this->type() << " killed " << Table[x][y]->type() << std::endl;
        }
        else
        {
            Table[x][y] = std::move(this);
            Table[pos.x][pos.y] = nullptr;
        }
        return NO_ERROR;
    }
}

int queen::type()
{
    if (Color)
        return WHITE_QUEEN;
    else
        return BLACK_QUEEN;
}

Pos queen::getPos(table<Ichess_pieces *> &Table) const
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