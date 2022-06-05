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
    else if (pos.x == x && pos.y == y) //just can move to left or right not both
    {
        std::cout << "Just go X or Y not both\n";
        return CANT_MOVE;
    }
    else if (pos.x == x && pos.y == y) // check if its the same pos
    {
        std::cout << "Moveeeee!\n";
        return SAME_PLACE;
    }
    else
    {
        int i = 1;
        if (x > pos.x || y > pos.y)
        {
            while ((pos.x + i) < x) //check vertical
            {
                if (Table[pos.x + i][pos.y])
                {
                    std::cout << "there is someone in X " << pos.x + i << " Y " << pos.y << std::endl;
                    return CANT_MOVE;
                }
                ++i;
            }

            i = 1;
            while ((pos.y + i) < y) // check horizontal
            {
                if (Table[pos.x][pos.y + i])
                {
                    std::cout << "there is someone in X " << pos.x << " Y " << pos.y + i << std::endl;
                    return CANT_MOVE;
                }
                ++i;
            }
        }
        else
        {
            i = 1;
            while ((pos.x - i) > x) //check vertical reverse
            {
                if (Table[pos.x - i][pos.y])
                {
                    std::cout << "there is someone in X " << pos.x - i << " Y " << pos.y << std::endl;
                    return CANT_MOVE;
                }
                ++i;
            }

            i = 1;
            while ((pos.y - i) > y) // check horizontal reverse
            {
                if (Table[pos.x][pos.y - i])
                {
                    std::cout << "there is someone in X " << pos.x << " Y " << pos.y + i << std::endl;
                    return CANT_MOVE;
                }
                ++i;
            }
        }
        
    }

    if (Table[x][y] && Table[x][y]->getColor() != this->getColor()) //verify if exists and its is not a friend
    {
        delete Table[x][y];
        Table[x][y] = std::move(this);
        Table[pos.x][pos.y] = nullptr;
        std::cout << this->type() << " killed " << Table[x][y]->type() << std::endl;
    }
    else if (Table[x][y] && Table[x][y]->getColor() == this->getColor())
    {
        std::cout << "Its a frind there\n";
        return CANT_MOVE;
        
    }
    else
    {
        Table[x][y] = std::move(this);
        Table[pos.x][pos.y] = nullptr;
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