#include "horse.hpp"

horse::horse(bool b)
{
    Color = b;
}

static bool checkOpositeEdges(const int &pos, const int &ToMovePos)
{
    const int LeftEdges[8] = {0, 8, 16, 24, 32, 40, 48, 56};
    const int RightEdges[8] = {7, 15, 23, 31,39, 47, 55, 63};

    bool PosLeft = false;
    bool PosRight = false;
    bool ToMovePosLeft = false;
    bool ToMovePosRight = false;

    if (std::find(std::begin(LeftEdges), std::end(LeftEdges), pos) != std::end(LeftEdges))
        PosLeft = true;
    if (std::find(std::begin(RightEdges), std::end(RightEdges), pos) != std::end(RightEdges))
        PosRight = true;
    if (std::find(std::begin(RightEdges), std::end(RightEdges), ToMovePos) != std::end(RightEdges))
        ToMovePosRight = true;
    if (std::find(std::begin(LeftEdges), std::end(LeftEdges), ToMovePos) != std::end(LeftEdges))
        ToMovePosLeft = true;
    
    if (ToMovePosRight == PosRight || ToMovePosLeft == PosLeft)
        return true;
    return false;
}
    
int horse::play(Board_t &Board, int ToMovePos)
{
    int pos = this->getPos(Board);

    if (ToMovePos > 63 || ToMovePos < 0) //out size of the Board
        return OUT_SIZE;
    else if (pos == ToMovePos) //if is not moving
        return SAME_PLACE;
    else if (Board[ToMovePos] && Board[ToMovePos]->getColor() == this->getColor()) //try kill friend
        return CANT_MOVE;
    if (!checkOpositeEdges(pos, ToMovePos))
        return CANT_MOVE;

    const int AvalPos[4] = {17, -17, 15, -15};
    if (std::find(std::begin(AvalPos), std::end(AvalPos), ToMovePos - pos) != std::end(AvalPos))
    {
        Board.getFirstPlay(this->Color) = false;
        Board[ToMovePos] = Board[pos];
        Board[pos] = nullptr;
        return NO_ERROR;
    }
    
    return CANT_MOVE;   
}

int horse::type()
{
    if (Color)
        return WHITE_HORSE;
    else
        return BLACK_HORSE;
}

int horse::getPos(Board_t &Board) const
{
    for (int i = 0; i < 64; ++i)
    {
        if (this == Board[i].get())
            return i;
    }
    return -1;
}

std::shared_ptr<Ichess_pieces> horse::copy()
{
    return std::make_shared<horse>(Color);
}

bool horse::getColor() const
{
    return Color;
}