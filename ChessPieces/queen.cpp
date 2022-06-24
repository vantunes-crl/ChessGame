#include "queen.hpp"

queen::queen(bool b)
{
    Color = b;
}

int queen::play(Table_t &Table, Pos ToMovePos)
{

    Pos pos = this->getPos(Table);
    Pos posCpy(pos);

    if (ToMovePos.x < 0 || ToMovePos.x > 7 || ToMovePos.y < 0 || ToMovePos.y > 7)
        return OUT_SIZE;
    else if (pos.x == ToMovePos.x && pos.y == ToMovePos.y)
        return SAME_PLACE;
    else if (Table[ToMovePos.x][ToMovePos.y] && Table[ToMovePos.x][ToMovePos.y]->getColor() == this->getColor())
        return CANT_MOVE;
    else if (ToMovePos.x != pos.x && ToMovePos.y != pos.y) //diagonal case
    {
        if (pos.y < ToMovePos.y)
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
                    Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y]; //kill
                    Table[pos.x][pos.y] = nullptr;
                    return NO_ERROR;
                }
            }
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
                    Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y]; //kill
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
        if (ToMovePos.x > pos.x || ToMovePos.y > pos.y)
        {
            while ((pos.x + i) < ToMovePos.x) //check vertical
            {
                if (Table[pos.x + i][pos.y])
                    return CANT_MOVE;
                ++i;
            }

            i = 1;
            while ((pos.y + i) < ToMovePos.y) // check horizontal
            {
                if (Table[pos.x][pos.y + i])
                    return CANT_MOVE;
                ++i;
            }
        }
        else
        {
            i = 1;
            while ((pos.x - i) > ToMovePos.x) //check vertical reverse
            {
                if (Table[pos.x - i][pos.y])
                    return CANT_MOVE;
                ++i;
            }

            i = 1;
            while ((pos.y - i) > ToMovePos.y) // check horizontal reverse
            {
                if (Table[pos.x][pos.y - i])
                    return CANT_MOVE;
                ++i;
            }
        }

        if (Table[ToMovePos.x][ToMovePos.y])
        {
            Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
            Table[pos.x][pos.y] = nullptr;
            std::cout << this->type() << " killed " << Table[ToMovePos.x][ToMovePos.y]->type() << std::endl;
        }
        else
        {
            Table[ToMovePos.x][ToMovePos.y] = Table[pos.x][pos.y];
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