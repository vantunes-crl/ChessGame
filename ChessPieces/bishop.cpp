#include "bishop.hpp"
#include <cstring>

 enum EDGES
 {
    TOP_EDGE, BOTTON_EDGE, LEFT_EDGE, RIGHT_EDGE
 };

void AvalMoves(int steps, EDGES Edge, int pos, Ichess_pieces::Board_t &Board, std::list<int> &moves)
{
    std::array<std::array<int, 8>, 4> All_Edges = {{
        {0,1,2,3,4,5,6,7},
        {56,57,58,59,60,61,62,63},
        {0,8,16,24,32,40,48,56},
        {7,15,23,31,39,47,55,63},
    }};

    while (true)
    {
        if (std::find(All_Edges[Edge].begin(), All_Edges[Edge].end(), pos) != All_Edges[Edge].end())
            break;
        pos += steps;
        if (pos > 63 || pos < 0)
            break;
        moves.push_back(pos);
        if (Board[pos])
            break;
    }
}


int bishop::play(Board_t &Board, int ToMovePos)
{
    int pos = this->getPos(Board); //original to set pos after move
    
    if (ToMovePos > 63 || ToMovePos < 0) //out size of the Board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (Board[ToMovePos] && Board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    
    std::list<int> moves;
    AvalMoves(9, RIGHT_EDGE, pos, Board, moves);
    AvalMoves(7, LEFT_EDGE, pos, Board, moves);
    AvalMoves(-9, LEFT_EDGE, pos, Board, moves);
    AvalMoves(-7, RIGHT_EDGE, pos, Board, moves);

    for (auto it : moves)
    {
        if (it == ToMovePos)
            return NO_ERROR;
    };

    return CANT_MOVE;
}



int bishop::type()
{
    if (Color)
        return WHITE_BISHOP;
    else
        return BLACK_BISHOP;
}

int bishop::getPos(Board_t &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
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