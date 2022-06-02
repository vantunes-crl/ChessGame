#include "pawn.hpp"

PIECES pawn::type()
{
    return PAWN;
}

void pawn::play(table<Ichess_pieces *> &Table, int x, int y)
{

    Pos pos = this->getPos(Table);

    if (x < 0 || x > 7 || y < 0 || y > 7) //verify the conors
    {
        std::cout << "Error: out of the table!" << std::endl;
        return;
    }
    else if (pos.x == x) //verify if is the same position
    {
        std::cout << "Error: You are in the same spot!, move!" << std::endl;
        return ;
    }
    else if (pos.x > x) //verify if is trying to go back
    {
        std::cout << "Error: You can't go back pawn, be courageous!!" << std::endl;
        return;
    }
    else if (pos.y != y) //verify if he can kill
    {
        if (Table[x][y])
        {
            delete Table[x][y];
            Table[x][y] = std::move(this);
            Table[pos.x][pos.y] = nullptr;
            std::cout << this->type() << " killed " << Table[x][y]->type() << std::endl;
        }
        else
        {
            std::cout << "Error: can't move left/right if the is no enemy to kill! Focus on get in the other side\n";
            return ;
        }
    }
    else if (x > (pos.x + 1) || y > (pos.y + 2)) //verify if is not walking more them 1 slot
    {
        std::cout << "Error: you just can move 1 slot per time Sr.Pawn\n";
        return ;
    }
    else //last case where he can go front
    {
        if (Table[x][y])
        {
            std::cout << "Error: There is a guy Blocking you, Wait!\n";
            return ;
        }
        Table[x][y] = std::move(this);
        Table[pos.x][pos.y] = nullptr;
    }
}

Pos pawn::getPos(table<Ichess_pieces *> &Table) const
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