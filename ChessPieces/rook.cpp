#include "rook.hpp"

rook::rook(bool b)
{
    Color = b;
}

int rook::play(table<Ichess_pieces *> &Table, int x, int y)
{

    Pos pos = this->getPos(Table);

    if (x < 0 || x > 7 || y < 0 || y > 7)
    {
        std::cout << "Error: out_size\n";
        return OUT_SIZE;
    }
    else if (pos.x != x && pos.y != y)
    {
        std::cout << "Just go X or Y not both\n";
        return CANT_MOVE;
    }
    else if (pos.x == x && pos.y == y)
    {
        std::cout << "Moveeeee!\n";
        return SAME_PLACE;
    }
    else if (Table[x][y]->getColor() == this->getColor())
    {
        std::cout << "you have a friend there!" << std::endl;
        return CANT_MOVE;
    }
    else
    {
        int i = 1;
        if (pos.x != x) //check if is someone along the way X
        {
            while ((pos.x + i) != x)
            {
                if (Table[pos.x + i][pos.y])
                {
                    std::cout << "there is someone in X " << pos.x + i << " Y " << pos.y << std::endl;
                    return CANT_MOVE;
                }
                ++i;
            }
        }
        else if (pos.y != y) // Y
        {
            while ((pos.y + i) != y)
            {
                if (Table[pos.x][pos.y + i])
                {
                    std::cout << "there is someone in X " << pos.x << " Y " << pos.y + i << std::endl;
                    return CANT_MOVE;
                }
                ++i;
            }
        }
    }



    return NO_ERROR;
}

int rook::type()
{
    if (Color)
        return WHITE_ROOK;
    else
        return BLACK_ROOK;
}

Pos rook::getPos(table<Ichess_pieces *> &Table) const
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